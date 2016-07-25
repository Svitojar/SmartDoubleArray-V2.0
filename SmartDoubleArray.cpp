#pragma one;
#include <iostream>
#include <cstring>
#include <math.h>
#include <cmath>
#include <random>
#include "SmartDoubleArray.h"
namespace lesson_9
{
	using namespace std;

	SmartDoubleArray::~SmartDoubleArray()
	{
		delete[] mas;
		mas = 0;
	}
	SmartDoubleArray::SmartDoubleArray() : arrSize(10)
	{
		mas = new int[arrSize];
		if  (mas == nullptr)
		{
			std::runtime_error("Can't allocate memory!!");
		}
		uniform_int_distribution<int> random(0, 100);
		mt19937 generator;
		for (int i = 0; i < arrSize; i++)
		{
			mas[i] = random(generator);
		}
		
	}

	SmartDoubleArray::SmartDoubleArray(int arr_size) : arrSize(arr_size)
	{
		mas = new int[arrSize];
		if (mas == nullptr)
		{
			std::runtime_error("Can't allocate memory!!");
		}
		uniform_int_distribution<int> random(0, 100);
		mt19937 generator;
		for (int i = 0; i < arrSize; i++)
		{
			mas[i] = random(generator);
		}
	}

	int SmartDoubleArray::getSize() const// it is capacity
	{
		return arrSize;
	}

	void SmartDoubleArray::Add(const int  value)
	{
		if (mas == nullptr)
		{
			std::runtime_error("Can't allocate memory!!");
		}
		int *temp = new int[arrSize + 1];
		for (int i = 0; i < arrSize; i++)
		{
			temp[i] = mas[i];
		}
		arrSize++;
		temp[arrSize - 1] = value;
		delete[] mas;

		mas = temp;
		
	}

	void SmartDoubleArray::Insert(const  int index, const int  value)
	{
		if (mas == nullptr)
		{
			std::runtime_error("Can't allocate memory!!");
		}
		if ((index <= 0)||(index>arrSize))
		{
			std::runtime_error("Incorrect index!!");
		}
		int *temp = new int[arrSize + 1];
		for (int i = 0; i <= index-1; i++)
		{
			temp[i] = mas[i];
		}
		arrSize++;
		temp[index] = value;

		for (int i = index; i <= arrSize-1; i++)
		{
			temp[i+1] = mas[i];
		}
		delete[] mas;
		mas = temp;
		
	}

	void SmartDoubleArray::remove(const int index)
	{
		if (mas == nullptr)
		{
			std::runtime_error("Can't allocate memory!!");
		}
		if ((index <= 0) || (index>=arrSize))
		{
			std::runtime_error("Incorrect index!!");
		}
		int *temp = new int[arrSize-1];
		for (int i = 0; i <= index-1; i++)
		{
			temp[i] = mas[i];
		}
		arrSize--;
		for (int i = index+1; i <= arrSize; i++)
		{
			temp[i-1] = mas[i];
		}
		delete[] mas;
		mas = temp;
	}
	int SmartDoubleArray::GetAt(int index)
	{
		if (mas == nullptr)
		{
			std::runtime_error("Can't allocate memory!!");
		}
		if ((index < 0) || (index>=arrSize))
		{
			std::runtime_error("Incorrect index!!");
		}
		return mas[index];
	}

	int SmartDoubleArray::Count(int value)
	{
		if (mas == nullptr)
		{
			std::runtime_error("Can't allocate memory!!");
		}
		int count = 0;
		for (int i = 0; i <= arrSize; i++)
		{
			if (mas[i] == value) { count++; }
		}
		return count;
	}

	int SmartDoubleArray::FindNext(int value, int index)
	{
		if (mas == nullptr)
		{
			std::runtime_error("Can't allocate memory!!");
		}
		if ((index <= 0) || (index>=arrSize))
		{
			std::runtime_error("Incorrect index!!");
		}
		int i = index;
		int count = 0;
		while (mas[i] != value)
		{
			i++;
			count++;
		}
		return count;
	}

	int SmartDoubleArray::operator [](int i)
	{
		if ((i >= 0) || (i<arrSize))
		{
			return mas[i];
		}
		
	}

	int SmartDoubleArray::SizeOf() const
	{
		int size = 0;
		for (int i = 0; i < getSize(); i++)
		{
			if (mas[i] != NULL)
			{
				size++;
			}
		}
		return size;
	}
}