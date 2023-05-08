#pragma once
#include <vector>
#include <initializer_list>
#include <string>


class Sort

{

    std::vector<int> list;

public:

    Sort(); //default
    Sort(int numElements, int minValue, int maxValue);
    Sort(std::initializer_list<int> initList);
    Sort(std::vector<int>& vec, int numElements);
    Sort(int count, ...);
    Sort(std::string str);

    void InsertSort(bool ascendent = false);

    int Partition(int left, int right, bool ascendent);

    void QuickSort(bool ascendent = false);

    void BubbleSort(bool ascendent = false);

    void Print();

    int  GetElementsCount();

    int  GetElementFromIndex(int index);

};