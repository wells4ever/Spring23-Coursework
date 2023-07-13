#pragma once


#include<iostream>
#include<assert.h>


using std::cout;
using std::cin;
using std::endl;
using std::string;


/// <summary>
/// 
/// </summary>
/// <typeparam name="T"></typeparam>
/// <typeparam name="elementCount"></typeparam>
template <typename T, int elementCount>
class MyArray
{
	//member vars (private) 
private: 
	T data[elementCount];
	//member functions (public)
public: 
	/// <summary>
	/// Returns element count ...
	/// </summary>
	/// <returns>the element count ...</returns>
	int getElementCount()
	{
		return elementCount; 
	}

	void print()
	{
		for (int i = 0; i < elementCount; i++)
		{
			cout << data[i] << endl; 
		}
	}

	T getElementAt(int index)
	{
		assert(index >= 0);
		return data[index];
	}

	void modifyElement(int index, T dataItem)
	{
		data[index] = dataItem;
	}
	

};