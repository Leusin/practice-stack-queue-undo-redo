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
	}

	bool Pop()
	{
		if (IsEmpty())
		{
			std::cout << "스택이 비어있어 요소를 제거할 수 없음\n";
			return false;
		}

		data[back--] = 0;

		return true;
	}

	bool Pop(T& outElement)
	{
		if (!Top(outElement))
		{
			return false;
		}

		return Pop();
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

	bool IsEmpty()
	{
		return back == 0;
	}

	bool IsFull() const
	{
		return back == Size;
	}

	void Display()
	{
		std::cout << "스택 내용:";

		for (int ix = 0; ix < back; ++ix)
		{
			std::cout << " " << data[ix];
		}

		std::cout << std::endl;
	}

private:
	// 앞은 닫혀있고 뒤는 열린 [) 인덱스
	int back = 0; // 가장 마지막 위치를 가리킨다

	T data[Size];
};