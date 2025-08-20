#pragma once

#include "Container/Deque.h"

/// <summary>
/// 디자인 패턴의 Command 패턴에서 Command 객체의 동작을 실행하는 Invoker 객체
/// </summary>
class CommandInvoker
{
public: // RAII
	CommandInvoker() = default;
	~CommandInvoker();

public: // MESSAGE
	void ExecuteCommand(class ICommand* concreteCommand);
	void UndoCommand();
	void RedoCommand();
	void Show() const;

private: // METHOD
	void ClearUndo();
	void ClearRedo();

private: // DATA
	// 스택처럼 작동하지만 입력이 수용량 보다 많을 경우 가장 오래된 명령 제거
	// Undo 스택
	Deque<class ICommand*, 6> undoStack;
	// Redo 스택
	Deque<class ICommand*, 6> redoStack;

};