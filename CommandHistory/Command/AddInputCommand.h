#pragma once

#include "ICommand.h"

class AddInputCommand : public ICommand
{
public:
	AddInputCommand(char input, class KeyInputManager& receiver);

	virtual bool Execute() override;
	virtual bool Undo() override;

protected:
	virtual void Print(std::ostream& os) const override;

private: // DATA
	class KeyInputManager& keyInputManager;
	char input;

	size_t index; // 몇 번째 명령인지 추적하기 위한 변수
	static size_t count;
};