#include <iostream>
#include "Sort.h"

using std::cout;
using std::endl;

int main()
{
	int vector[15] = { 3,5,6,1,2,7 };
	
	cout << "Exemplu in care este utilizat constructorul cu rand():"<<endl;
	Sort Obj1(12, 1, 10);
	Obj1.Print();
	Obj1.BubbleSort();
	cout << "Lista dupa ce a fost sortata descrescator cu Bubble Sort: " << endl;
	Obj1.Print();
	cout << endl;

	cout << "Exemplu in care este utilizata o lista de initializare:" << endl;
	Sort Obj2{ 3,2,1,5,5,9 };
	Obj2.Print();
	cout << "Lista contine " << Obj2.GetElementsCount() << " elemente" << endl << endl;

	cout << "Exemplu in care este folosit un alt vector:" << endl;
	Sort Obj3(vector, 6);
	Obj3.Print();
	Obj3.QuickSort(true);
	cout << "Lista dupa ce a fost sortata crescator cu Quick Sort: " << endl;
	Obj3.Print();
	cout << endl;

	cout << "Exemplu in care sunt folositi parametrii variadici" << endl;
	Sort Obj4(6, 6, 5, 4, 3, 2, 1);
	Obj4.Print();
	cout << "Elementul de pe index-ul 6 este: " << Obj4.GetElementFromIndex(6) << endl;
	cout << "Elementul de pe index-ul 3 este: " << Obj4.GetElementFromIndex(3) << endl << endl;

	cout << "Exemplu in care se foloseste un string: " << endl;
	Sort Obj5("3,1,9,21,7,5");
	Obj5.Print();
	Obj5.InsertSort(false);
	cout << "Lista dupa ce a fost sortata descrescator cu Insert Sort: " << endl;
	Obj5.Print();


}