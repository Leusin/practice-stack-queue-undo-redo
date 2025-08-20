#pragma once

class ICommand
{
public:
	virtual ~ICommand() = default;
	virtual bool Execute() abstract;
};
