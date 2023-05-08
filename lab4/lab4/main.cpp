#include "Sort.h"
#include <iostream>
#include <vector>

int main()
{
	Sort s1(10, 1, 100);
	s1.Print();
	s1.InsertSort(false);
	s1.Print();

	Sort s2 = { 5,2,8,3,6 };
	s2.Print();
	s2.QuickSort(false);
	s2.Print();

	std::vector<int> v = { 9,1,5,7,3 };
	Sort s3(v, 5);
	s3.Print();
	s3.BubbleSort(true);
	s3.Print();

	Sort s4(7, 10, 20, 5, 25, 15, 30, 1);
	s4.Print();
	s4.QuickSort(false);
	s4.Print();

	Sort s5("10,40,100,5,70"); 
	s5.Print();
	s5.QuickSort(true);
	s5.Print();

	return 0;

}