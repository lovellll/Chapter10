// Chapter10.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <initializer_list>
#include <cassert>

class IntArray
{
	int m_length;
	int *m_array;

public:
	IntArray() :m_length(0),m_array(nullptr)
	{
	}

	IntArray(int length) :m_length(length)
	{
		m_array = new int[length] {0};
	}

	IntArray(const std::initializer_list<int> &list):IntArray(list.size())
	{
		int count = 0;
		for (const auto &element : list)
		{
			m_array[count] = element;
			++count;
		}
	}

	IntArray& operator=(const std::initializer_list<int> &list)
	{
		if (m_array != 0)
		{
			delete[] m_array;
		}
		m_length = list.size();
		m_array = new int[m_length];
		int count = 0;
		for (const auto &element : list)
		{
			m_array[count] = element;
			++count;
		}
		return *this;
	}

	int& operator[](const int index)
	{
		assert(index >= 0 && index < m_length);
		return m_array[index];
	}


	~IntArray()
	{
		delete[] m_array;
	}

	void erase()
	{
		if (m_length == 0)
			return;  //no need to erase
		delete[] m_array;
		m_array = nullptr;
		m_length = 0;
	}

	int getLength()
	{
		return m_length;
	}


};


int main()
{
	IntArray array { 5, 4, 3, 2, 1 }; // initializer list
	for (int count = 0; count < array.getLength(); ++count)
		std::cout << array[count] << ' ';

	std::cout << '\n';

	array = { 1, 3, 5, 7, 9, 11 };

	for (int count = 0; count < array.getLength(); ++count)
		std::cout << array[count] << ' ';

	return 0;
}
