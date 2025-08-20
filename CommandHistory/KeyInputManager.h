#pragma once

#include "Container/Deque.h"

/// <summary>
/// 요청된 동작을 실제로 수행하는 객체
/// </summary>
class KeyInputManager
{
public: // MESSAGE
	bool AddInput(char input);
	bool CancleInput();
	void Display() const;

private: // DATA
	Deque<char, 100> inputMessages; // 입력 큐
};