#pragma once

#include <iostream>

template <typename T, size_t Size = 10>
class Deque
{
public: // RAII

public: // Message
	bool AddFront(const T& element)
	{
		if (IsFull())
		{
			std::cout << "덱이 가득 차 요소를 추가할 수 없음\n";
			return false;
		}
		
		front = (front - 1 + capacity) % capacity;
		data[front] = element;
		return true;
	}

	bool DeleteFront()
	{
		if (IsEmpty())
		{
			std::cout << "덱이 비어있어 요소를 제거할 수 없음\n";
			return false;
		}
		data[front] = 0;
		front = (front + 1) % capacity;
		return true;
	}

	bool AddRear(const T& element)
	{
		if (IsFull())
		{
			std::cout << "덱이 가득 차 요소를 추가할 수 없음\n";
			return false;
		}
		data[rear] = element;
		rear = (rear + 1) % capacity;
		return true;
	}

	bool DeleteRear()
	{
		if (IsEmpty())
		{
			std::cout << "덱이 비어있어 요소를 제거할 수 없음\n";
			return false;
		}
		rear = (rear - 1 + capacity) % capacity;
		data[rear] = 0;
		return true;
	}

	bool GetFront(T& outElement) const
	{
		if (IsEmpty())
		{
			std::cout << "덱이 비어있어 요소를 가져올 수 없음\n";
			return false;
		}
		outElement = data[front];
		return true;
	}

	bool GetRear(T& outElement) const
	{
		if (IsEmpty())
		{
			std::cout << "덱이 비어있어 요소를 가져올 수 없음\n";
			return false;
		}
		outElement = data[(rear - 1 + capacity) % capacity];
		return true;
	}

	// 비어있지 않으면 true, 비어 있지 않으면 false 를 반환
	bool IsEmpty() const
	{
		return front == rear;
	}

	bool IsFull() const
	{
		//  0  1  2  3  4  5
		// [f][-][-][-][-][r]
		// [-][-][r][f][-][-]

		return front == (rear + 1) % capacity;
	}

	size_t GetSize() const
	{
		// front가 rear 보다 뒤에 있는 경우도 고려

		//  0  1  2  3  4  5
		// [ ][f][-][-][r][ ]
		// [-][r][ ][ ][f][-]

		// 1) front가 rear 보다 앞에 있는 경우
		// (4 - 1 + 6) % 6 = 3

		// 2) front가 rear 보다 뒤에 있는 경우
		// (1 - 4 + 6) % 6 = 3
		return (rear - front + capacity) % capacity;
	}

	void Display()
	{
		std::cout << "덱 내용:";

		size_t max = (front < rear) ? rear : rear + capacity;
		for (int ix = front; ix < max; ++ix)
		{
			std::cout << " " << data[ix % capacity];
		}

		std::cout << std::endl;
	}

private:
	// 앞은 닫혀있고 뒤는 열린 [) 인덱스
	int front = 0; // 가장 앞 순서를 가리킨다.
	int rear = 0; // 가장 마지막의 다음을 가리킨다

	size_t capacity; // 실제 자료형의 크기. 최대 수용량보다 1 크다

	T data[Size + 1];
};