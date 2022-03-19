#pragma once

#include <initializer_list>

class Sort {
	int v[200];
	int count = 6;
public:
	Sort(int nr, int min, int max);
	Sort(int vector[], int n);
	Sort(int count, ...);
	Sort(const char* string);
	Sort(std::initializer_list<int> l);
	void InsertSort(bool ascendent = false);
	void QuickSort(bool ascendent = false);
	void BubbleSort(bool ascendent = false);
	void Print();
	int  GetElementsCount();
	int  GetElementFromIndex(int index);
};
