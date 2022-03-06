#include<iostream>
#include "NumberList.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	NumberList FirstList;

	int x;

	FirstList.Init();

	cout << "Enter your numbers:" << endl;
	cin >> x;
	while(FirstList.Add(x))
	{
		cin >> x;
	}

	cout << "FirstList before sorting:"<<endl;
	FirstList.Print();
	
	FirstList.Sort();
	cout << "FirstList after sorting:" << endl;
	FirstList.Print();

	return 0;
}