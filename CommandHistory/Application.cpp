#include "Application.h"

void Application::GetInput(char input)
{
	eventQueue.Enqueue(input);
}
