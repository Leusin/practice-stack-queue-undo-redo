#pragma once

#include "Queue.h"
#include "Stack.h"

class Application
{
public:
	void GetInput(char input);

private:
	Queue<char> eventQueue;
	Stack<char> undo;
	Stack<char> redo;
};
