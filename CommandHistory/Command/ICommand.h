#pragma once

#include <ostream>

/// <summary>
/// Command 패턴에서 명령을 실행하기 위한 추상 클래스이자 인터페이스
/// </summary>
class ICommand
{
	friend std::ostream& operator<<(std::ostream& os, const ICommand& obj)
	{
		obj.Print(os);
		return os;
	}

public:// RAII
	virtual ~ICommand() = default;

public:// INTERFACE
	virtual bool Execute() abstract;
	virtual bool Undo() abstract;

protected:
	virtual void Print(std::ostream& os) const abstract;
};