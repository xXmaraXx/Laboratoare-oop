#pragma warning(disable : 4996)
#include "Numbers.h"
#include <stdexcept>
#include<iostream>
#include <cstring>
#include <algorithm>

Number::Number(const char* value, int base) : value(nullptr), base(base), length(0)
{
	if (base < 2 || base>16) {
		throw std::invalid_argument("Base must be between 2 and 16");
	}
	length = std::strlen(value);
	this->value = new char[length + 1];
	std::strcpy(this->value, value);
	FromCharToInt(this->value);
}

Number::Number(int value) : value(nullptr), base(10), length(0)
{
	if (value < 0) {
		throw std::invalid_argument("Value must be positive");
	}
	int temp = value;
	while (temp) {
		length++;
		temp /= base;
	}
	this->value = new char[length + 1];
	FromIntToChar(value);

	std::reverse(this->value, this->value + this->length);
	this->value[this->length] = '\0';
}

Number::Number(const Number& other) : value(nullptr), base(other.base), length(other.length)
{
	this->value = new char[this->length + 1];
	std::strcpy(this->value, other.value);
}

Number::Number(Number&& other) noexcept: value(other.value), base(other.base), length(other.length)
{
	other.value = nullptr;
	other.base = 10;
	other.length = 0;
}

Number::~Number()
{
	delete[] value;
}

Number& Number::operator=(const char* value)
{
	FromCharToInt(value);
	return *this;
}

Number& Number::operator=(const Number& other)
{
	if (this == &other) {
		return *this;
	}

	base = other.base;

	// Reallocate the value array if necessary
	if (length != other.length) {
		delete[] value;
		length = other.length;
		value = new char[length + 1];
	}

	// Copy the value array
	for (int i = 0; i < length; i++) {
		value[i] = other.value[i];
	}

	return *this;
}

Number& Number::operator=(Number&& other) noexcept
{
	if (this == &other) {
		return *this;
	}

	base = other.base;
	length = other.length;
	value = other.value;

	other.length = 0;
	other.value = nullptr;

	return *this;
}


Number& Number::operator--()
{
	if (value[0] == '0' && length == 1) {
		throw std::out_of_range("Number cannot be negative");
	}
	for (int i = 1; i < length; i++) {
		int digit = value[i] - '0';
		if (digit < 0) {
			digit += base;
		}
		value[i] = digit + '0';
	}
	if (value[1] == '0' && length > 1) {
		// remove leading zeros
		int i = 1;
		while (i < length && value[i] == '0') {
			i++;
		}
		for (int j = i; j < length; j++) {
			value[j - i] = value[j];
		}
		length -= i;
	}
	else {
		//value[0] = '0'; // remove first digit
		length--;
	}
	return *this;
}

Number Number::operator--(int)
{
	Number temp(*this);
	--temp.length;
	return temp;
}

char& Number::operator[](int index)
{
	if (index < 0 || index >= length) {
		throw std::out_of_range("Index out of range");
	}
	return value[index];
}

const char& Number::operator[](int index) const
{
	if (index < 0 || index >= length) {
		throw std::out_of_range("Index out of range");
	}
	return value[index];
}

Number& Number::operator+=(const Number& other)
{
	if (base != other.base) {
		throw std::invalid_argument("Bases do not match");
	}

	int carry = 0;
	int max_length = std::max(length, other.length);

	for (int i = 0; i < max_length; i++) {
		int digit1 = i < length ? value[length - i - 1] - '0' : 0;
		int digit2 = i < other.length ? other.value[other.length - i - 1] - '0' : 0;
		int sum = digit1 + digit2 + carry;

		if (sum >= base) {
			sum -= base;
			carry = 1;
		}
		else {
			carry = 0;
		}

		if (i < length) {
			value[length - i - 1] = sum + '0';
		}
		else {
			// Extend the string with the new digit
			char* new_value = new char[i + 2];
			new_value[i + 1] = '\0';
			new_value[i] = sum + '0';
			for (int j = 0; j < i; j++) {
				new_value[i - j - 1] = value[length - j - 1];
			}
			delete[] value;
			value = new_value;
			length = i + 1;
		}
	}

	if (carry > 0) {
		// Extend the string with the carry digit
		char* new_value = new char[max_length + 2];
		new_value[max_length + 1] = '\0';
		new_value[max_length] = carry + '0';
		for (int i = 0; i < max_length; i++) {
			new_value[max_length - i - 1] = value[length - i - 1];
		}
		delete[] value;
		value = new_value;
		length = max_length + 1;
	}

	return *this;
}

Number operator+(const Number& n1, const Number& n2)
{
	if (n1.base != n2.base) {
		throw std::invalid_argument("Bases do not match");
	}
	int carry = 0;
	int max_length = std::max(n1.length, n2.length);
	char* result = new char[max_length + 1];

	for (int i = 0; i < max_length; i++) {
		int digit1 = (i < n1.length) ? n1.value[i] - '0' : 0;
		int digit2 = (i < n2.length) ? n2.value[i] - '0' : 0;
		int sum = digit1 + digit2 + carry;

		result[i] = sum % n1.base + '0';
		carry = sum / n1.base;
	}

	if (carry > 0) {
		result[max_length] = carry + '0';
		return Number(result, n1.base);
	}
	else {
		result[max_length] = '\0';
		return Number(result, n1.base);
	}
}

Number operator-(const Number& n1, const Number& n2)
{
	if (n1.base != n2.base) {
		throw std::invalid_argument("Bases do not match");
	}

	if (n1.value < n2.value) {
		throw std::invalid_argument("Cannot subtract a larger number from a smaller one");
	}

	int borrow = 0;
	int size = n1.length;
	char* result = new char[size + 1];

	for (int i = 0; i < size; i++) {
		int digit1 = n1.value[i] - '0' - borrow;
		int digit2 = (i < n2.length) ? n2.value[i] - '0' : 0;

		if (digit1 < digit2) {
			digit1 += n1.base;
			borrow = 1;
		}
		else {
			borrow = 0;
		}
		result[i] = digit1 - digit2 + '0';
	}

	while (result[size - 1] == '0' && size > 1) {
		size--;
	}

	result[size] = '\0';
	std::reverse(result, result + size);
	return Number(result, n1.base);
}

bool Number::operator<(const Number& n)
{
	if (base != n.base) {
		throw std::invalid_argument("Bases do not match");
	}

	if (length != n.length) {
		return length < n.length;
	}

	for (int i = length - 1; i >= 0; i--) {
		if (value[i] != n.value[i]) {
			return value[i] < n.value[i];
		}
	}
	return false;
}

bool Number::operator<=(const Number& n)
{
	if (base != n.base) {
		throw std::invalid_argument("Bases do not match");
	}
	return (*this < n) || (*this == n);
}

bool Number::operator>(const Number& n)
{
	if (base != n.base) {
		throw std::invalid_argument("Bases do not match");
	}
	return !(*this <= n);
}

bool Number::operator>=(const Number& n)
{
	if (base != n.base) {
		throw std::invalid_argument("Bases do not match");
	}
	return !(*this < n);
}

bool Number::operator==(const Number& n)
{
	if (base != n.base || length != n.length) {
		return false;
	}

	for (int i = 0; i < length; i++) {
		if (value[i] != n.value[i]) {
			return false;
		}
	}
	return true;
}

bool Number::operator!=(const Number& n)
{
	return !(*this == n);
}

void Number::SwitchBase(int newBase)
{
	if (newBase < 2 || newBase>16) {
		throw std::invalid_argument("Invalid base");
	}

	int oldBase = base;
	base = newBase;
	int num = 0;
	for (int i = length - 1; i >= 0; i--) {
		num += (value[i] - '0') * pow(oldBase, length - i - 1);
	}
	delete[] value;
	FromIntToChar(num);
}

void Number::Print() const
{
	for (int i = 0; i <length;i++) {
		std::cout << value[i];
	}
	std::cout << '\n';
}

int Number::GetDigitsCount() const
{
	return length;
}

int Number::GetBase() const
{
	return base;
}

void Number::FromCharToInt(const char* value)
{
	int num = 0;
	for (int i = length - 1; i >= 0; i--) {
		if (value[i] >= '0' && value[i] <= '9') {
			num += (value[i] - '0') * pow(base, length - i - 1);
		}
		else if (value[i] >= 'A' && value[i] <= 'F') {
			num += (value[i] - 'A' + 10) * pow(base, length - i - 1);
		}
		else if (value[i] >= 'a' && value[i] <= 'f') {
			num += (value[i] - 'a' + 10) * pow(base, length - i - 1);
		}
		else {
			throw std::invalid_argument("Invalid input");
		}
	}

	//delete[] value;
	FromIntToChar(num);
}

void Number::FromIntToChar(int num)
{
	length = 0;

	if (num == 0) {
		value = new char[2];
		value[0] = '0';
		value[1] = '\0';
		length = 1;
		return;
	}

	int temp = num;
	while (temp > 0) {
		temp /= base;
		length++;
	}

	value = new char[length + 1];

	for (int i = 0; i < length; i++) {
		int remainder = num % base;
		if (remainder < 10) {
			value[i] = remainder + '0';
		}
		else {
			value[i] = remainder - 10 + 'A';
		}
		num /= base;
	}

	value[length] = '\0';

	std::reverse(value, value + length);
}

