#include "KeyInputManager.h"

bool KeyInputManager::AddInput(char input)
{
	return inputMessages.AddRear(input);
}

bool KeyInputManager::CancleInput()
{
	return inputMessages.DeleteRear();
}

void KeyInputManager::Display() const
{
	std::cout << "Input 대기";
	inputMessages.Display();
}