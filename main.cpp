#pragma one;
#include "SmartDoubleArray.h"
#include <math.h>
#include <iostream>
#include <cmath>
using namespace lesson_9;
using namespace std;
void main()
{
	SmartDoubleArray MyArray;
	cout << "Array capacity" << MyArray.getSize() << endl;
	for (int i = 0; i < MyArray.getSize(); i++)
	{
		cout << i << "    " << MyArray[i] << endl;
	}
	cout << "    " << endl;
	MyArray.Add(8);
	MyArray.Insert(3,89);
	MyArray.remove(5);
	for (int i = 0; i < MyArray.getSize(); i++)
	{
		cout << i << "    " << MyArray[i] << endl;
	}
	cout << "Array capacity" << MyArray.getSize() << endl;
	cout << "Array Size of" << MyArray.SizeOf() << endl;
	cout << "Element #7 is " << MyArray.GetAt(7)<< endl;
	cout << "Count of  89 is " << MyArray.Count(89) << endl;
	cout << "After #3 element 43, find is " << MyArray.FindNext(43, 3) <<" times"<< endl;
	MyArray.~SmartDoubleArray();
	cin.get();
	cin.get();
}
