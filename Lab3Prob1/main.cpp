#include <iostream>
#include "math.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	Math Example;

	cout << Example.Add(1, 4) << " " << Example.Add(100, 2301, 0) << endl; //int 
	cout << Example.Add(1.5, 4.16) << " " << Example.Add(100.01, 2301.02, 0.41) << endl; //double
	cout << Example.Mul(27, 4) << " " << Example.Mul(10, 23, 2) << endl; //int
	cout << Example.Mul(1.6, 1.0) << " " << Example.Mul(1.5, 3.0, 1.0) << endl; //double
	cout << Example.Add(5, 43, 12, 1, 0, 29) << endl;
	
	char* string = Example.Add("Ana are", " mere.");
	if (string != nullptr) cout << string;
	else cout << "invalid string";

	return 0;
}