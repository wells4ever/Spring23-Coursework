#pragma once
#include <iostream>
#include <assert.h>

using std::cout;
using std::cin;
using std::string;
using std::endl;

template <typename T, int elementCount>
class MyArray
{
	//member vars , priv
private:
	T data[elementCount];

	//member functs, publ
public:
	/// <summary>
	/// Returns element count
	/// </summary>
	/// <returns>the element count</returns>
	int getElementCount()
	{
		return elementCount;
	}

	T getElementAt(int index)
	{
		assert(index >= 0);
		return data[index];
	}

	void print()
	{
		for (int i = 0; i < elementCount; i++)
			cout << data[i] << endl;
	}

	void ModifyElement(int index, T dataItem)
	{
		data[index] = dataItem;
	}
	/// <summary>
	/// overloaded subscript (index) operator
	/// </summary>
	/// <param name="index"></param>
	/// <returns> item at index </returns>
	T operator [] (int index)
	{
		return data[index];
	}
};