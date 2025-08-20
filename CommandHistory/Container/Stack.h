#pragma once

#include <iostream>

template <typename T, size_t Size = 10>
class Stack
{
public:
	Stack()
		: back(0)
	{
		memset(data, 0, Size);
	}

	bool Push(const T& element)
	{
		if (IsFull())
		{
			std::cout << "스택이 가득 차 요소를 추가할 수 없음\n";
			return false;
		}

		data[back++] = element;

		return true;
	}

	bool Pop(T& outElement)
	{
		if (IsEmpty())
		{
			return false;
		}
		outElement = data[--back];
		return true;
	}

	bool Top(T& outElement)
	{
		if (IsEmpty())
		{
			std::cout << "스택이 비어있어 요소를 가져올 수 없음\n";
			return false;
		}

		outElement = data[back];
		
		return true;
	}

	bool IsEmpty() const
	{
		return back == 0;
	}

	bool IsFull() const
	{
		return back == Size;
	}

	void Display() const
	{
		std::cout << "스택 내용:";
		if (IsEmpty())
		{
			std::cout << " 비어있음" << std::endl;
			return;
		}

		for (int ix = 0; ix < back; ++ix)
		{
			std::cout << " " << *data[ix];
		}

		std::cout << std::endl;
	}

private:
	int back = 0; // 가장 마지막 위치를 가리킨다

	T data[Size];
};