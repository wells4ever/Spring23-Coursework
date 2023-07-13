#pragma once

#include <iostream>

#include <cassert>

using std::cout;
using std::endl;
using std::string;

template<typename T>

class MyVector
{

	T* m_Data = nullptr;
	size_t m_Size = 0;
	size_t m_Capacity = 0;

public:
	void allocate(size_t newCapacity)
	{
		cout << "allocate called" << endl; 
		T* newBlock = new T[newCapacity];

		if (newCapacity < m_Size)
		{
			m_Size = newCapacity;
		}

		for (size_t i = 0; i < m_Size; i++)
		{
			newBlock[i] = m_Data[i];
		}

		delete[] m_Data;
		m_Data = newBlock;
		m_Capacity = newCapacity;
	}

	MyVector()
	{
		//cout << "constructor called" << endl;
		allocate(2);
	}

	size_t getSize()
	{
		return m_Size;
	}

	size_t getCapacity()
	{
		return m_Capacity;
	}

	/// <summary>
	/// Note that return by reference 
	/// must be used if assigning 
	/// -not just retrieving- values
	/// </summary>
	/// <param name="index"></param>
	/// <returns>a REFERENCE (lvalue) to element at indexed position</returns>
	T& operator[] (int index)
	{
		assert(index <= m_Capacity - 1);
		return m_Data[index];
	}

	T getElementAt(int index)
	{
		return m_Data[index];
	}

	void pushBack(const T& value)
	{
		if (m_Size >= m_Capacity)
		{
			//cout << "Increasing capacity to " << m_Capacity*2 << endl; 
			allocate(m_Capacity * 2);
		}

		m_Data[m_Size] = value;

		m_Size++;
	}


	T popBack()
	{
		assert(m_Size > 0);
		m_Size--;

		T poppedElement = m_Data[m_Size];

		m_Data[m_Size].~T();

		return poppedElement;
	}

	void clear()
	{
		while (m_Size > 0)
		{
			popBack();
		}
	}




	T* getVector()
	{
		return m_Data;
	};

	void print()
	{
		for (int i = 0; i < m_Size; i++) {
			cout << m_Data[i] << endl;
		}
	}



	~MyVector()
	{
		clear();
		delete[] m_Data;
	}

	MyVector(const MyVector& otherVector) //& is mandatory here 
	{
		m_Size = otherVector.m_Size;
		m_Capacity = otherVector.m_Capacity;
		m_Data = new T[m_Capacity]; //copies empty/garbage positions also
		for (int i = 0; i < m_Size; i++)
		{
			m_Data[i] = otherVector.m_Data[i];
		}
	}

};