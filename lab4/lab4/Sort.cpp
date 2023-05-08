#include "Sort.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <stdarg.h>
#include <stack>

Sort::Sort()
{
}

Sort::Sort(int numElements, int minValue, int maxValue)
{
	for (int i = 0; i < numElements; i++) {
		int randomValue = rand() % (maxValue - minValue + 1) + minValue;
		list.push_back(randomValue);
	}
}

Sort::Sort(std::initializer_list<int> initList) : list(initList)
{
}

Sort::Sort(std::vector<int>& vec, int numElements)
{
	for (int i = 0; i < numElements; i++) {
		list.push_back(vec[i]);
	}
}

Sort::Sort(int count, ...)
{
	va_list args;
	va_start(args, count);
	for (int i = 0; i < count; i++) {
		int value = va_arg(args, int);
		list.push_back(value);
	}
	va_end(args);
}

Sort::Sort(std::string str)
{
	std::stringstream ss(str);
	std::string num;
	while (getline(ss, num, ',')) {
		list.push_back(std::stoi(num));
	}
}

void Sort::InsertSort(bool ascendent)
{
	for (int i = 1; i < list.size(); i++)
	{
		int key = list[i];
		int j = i - 1;
		while ((ascendent && j >= 0 && list[j] > key) || (!ascendent && j >= 0 && list[j] < key))
		{
			list[j + 1] = list[j];
			j--;
		}
		list[j + 1] = key;
	}
}

int Sort::Partition(int left, int right, bool ascendent)
{
	int pivot = list[right];
	int i = left - 1;
	for (int j = left; j < right; j++) {
		if ((ascendent && list[j] <= pivot) || (!ascendent && list[j] >= pivot)) {
			i++;
			std::swap(list[i], list[j]);
		}
	}
	std::swap(list[i + 1], list[right]);
	return i + 1;
}

void Sort::QuickSort(bool ascendent)
{
	std::stack<std::pair<int, int>> stack;
	int left = 0;
	int right = list.size() - 1;
	stack.push(std::make_pair(left, right));
	while (!stack.empty()) {
		left = stack.top().first;
		right = stack.top().second;
		stack.pop();
		int pivotIndex = Partition(left, right, ascendent);
		if (pivotIndex - 1 > left) {
			stack.push(std::make_pair(left, pivotIndex - 1));
		}
		if (pivotIndex + 1 < right) {
			stack.push(std::make_pair(pivotIndex + 1, right));
		}
	}

}

void Sort::BubbleSort(bool ascendent)
{
	bool swapped;
	for (int i = 0; i < list.size() - 1; i++) {
		swapped = false;
		for (int j = 0; j < list.size() - i - 1; j++) {
			if ((ascendent && list[j] > list[j + 1]) || (!ascendent && list[j] < list[j + 1])) {
				std::swap(list[j], list[j + 1]);
				swapped = true;
			}
		}
		if (!swapped) {
			break;
		}
	}
}

void Sort::Print()
{
	for (int i = 0; i < list.size(); i++) {
		std::cout << list[i] << " ";
	}
	std::cout << "\n";
}

int Sort::GetElementsCount()
{
	return list.size();
}

int Sort::GetElementFromIndex(int index)
{
	if (index < 0 || index >= list.size()) {
		throw std::out_of_range("Index out of range");
	}
	return list[index];
}
