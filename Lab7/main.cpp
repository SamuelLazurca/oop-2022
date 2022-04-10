#include <iostream>
#include "vector.h"

using namespace std;

int main()
{
	Vector<int> v1;
	v1.Push(1);
	v1.Push(2);
	v1.Set(3, 0);
	v1.Insert(4, 0);
	v1.Sort();

	for(unsigned i=0;i<v1.Count();i++)
		std::cout << v1.Get(i)<<" ";
	std::cout << std::endl << v1.Count();
	
	cout << endl << v1.firstIndexOf(4);
	
	return 0;
}