#pragma once

#include <iostream>

/// <summary>
/// 내부는 환형 큐처로서 동작한다
/// </summary>
/// <typeparam name="T">최대 크기</typeparam>
template <typename T, size_t Size = 10>
class Queue
{
public:
	Queue()
		: front{ 0 }
		, rear{ 0 }
		, capacity{ Size + 1 }
	{
		memset(data, 0, capacity);
	}

	bool Enqueue(const T& element)
	{
		// 가득차 있는지부터 확인하고 전달된 요소를 맨 뒤에 추가한다.

		if (IsFull())
		{
			std::cout << "큐가 가득 차 요소를 추가할 수 없음\n";
			return false;
		}

		data[rear] = element;
		rear = (rear + 1) % capacity;

		return true;
	}

	bool Dequeue()
	{
		// 큐가 비어 있지 않으면 맨 앞 요소를 삭제한다.

		if (IsEmpty())
		{
			std::cout << "큐가 비어있어 요소를 제거할 수 없음\n";
			return false;
		}

		data[front] = 0;
		front = (front + 1) % capacity;

		return true;
	}

	bool Dequeue(T& outElement)
	{
		if (!Peek(outElement))
		{
			return false;
		}

		return Dequeue();
	}

	bool Peek(T& outElement) const
	{
		if (IsEmpty())
		{
			std::cout << "큐가 비어있어 요소를 가져올 수 없음\n";
			return false;
		}

		outElement = data[front];
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

		//return Size() == maxSize;
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
		std::cout << "큐 내용:";

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
