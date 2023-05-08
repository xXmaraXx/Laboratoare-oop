#include "NumberList.h"
#include <iostream>
#include <algorithm>


void NumberList::Init() {
	count = 0;
}

bool NumberList::Add(int x) {
	if (count >= 10) {
		return false;
	}
	numbers[count] = x;
	count++;
	return true;
}

void NumberList::Sort() {
	std::sort(numbers, numbers + count);
}

void NumberList::Print() {
	for (int i = 0; i < count; i++) {
		std::cout << numbers[i] << " ";
	}
	std::cout << "\n";
}