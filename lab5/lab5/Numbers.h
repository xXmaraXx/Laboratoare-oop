#pragma once
class Number

{

	char* value;
	int base;
    int length;

    void FromCharToInt(const char* value);
    void FromIntToChar(int num);

public:

	Number(const char* value, int base); // where base is between 2 and 16
	Number(int value);
	Number(const Number& other);
	Number(Number&& other) noexcept;
	~Number();

    Number& operator=(const Number& other);
    Number& operator=(Number&& other) noexcept;
    Number& operator=(const char* value);
    Number& operator--();
    Number operator--(int);
    char& operator[](int index);
    const char& operator[](int index) const;
    Number& operator+=(const Number& other);
    friend Number operator+(const Number& n1, const Number& n2);
    friend Number operator-(const Number& n1, const Number& n2);
    bool operator<(const Number& n);
    bool operator<=(const Number& n);
    bool operator>(const Number& n);
    bool operator>=(const Number& n);
    bool operator==(const Number& n);
    bool operator!=(const Number& n);

	void SwitchBase(int newBase);

	void Print() const;

	int  GetDigitsCount() const; // returns the number of digits for the current number

	int  GetBase() const; // returns the current base

};