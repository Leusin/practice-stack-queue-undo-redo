#include "AddInputCommand.h"

#include "KeyInputManager.h"

size_t AddInputCommand::count = 0;

AddInputCommand::AddInputCommand(char input, KeyInputManager& manager)
	: input(input)
	, keyInputManager(manager)
	, index(count)
{
	count++;
}

bool AddInputCommand::Execute()
{
	return keyInputManager.AddInput(input);
}

bool AddInputCommand::Undo()
{
	return keyInputManager.CancleInput();
}

void AddInputCommand::Print(std::ostream& os) const
{
	os << input << "(" << index << ")" ;
}
