#pragma once

using std::cout;
using std::cin;
using std::string;
using std::endl;

template <typename T>
class MyVector
{
private:
	T* m_Data = nullptr; // smart pointer
	size_t m_Size = 0; // number elements
	size_t m_Capacity = 0; //allocated memory

public:
	void allocate(size_t newCapacity)
	{
		T* newBlock = new T[newCapacity]; //returns an address and allocated (newCapacity)

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

	T& operator[](size_t index)
	{
		assert(index <= m_Capacity - 1);
		return m_Data[index];
	}

	T* getVector()
	{
		return m_Data;
	}

	void pushBack(const T& value)
	{
		if (m_Size >= m_Capacity)
		{
			allocate(2 * m_Capacity);
			cout << "Inceasing capacity to " << m_Capacity * 2 << endl;

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

	~MyVector()
	{
		clear();
		delete[] m_Data;
	}
};