#include "CommandInvoker.h"
#include "Command/ICommand.h"

CommandInvoker::~CommandInvoker()
{
	ClearUndo();
	ClearRedo();
	
}

void CommandInvoker::ExecuteCommand(ICommand* concreteCommand)
{
	// 명령 실행 기록 스택에 명령을 추가
	concreteCommand->Execute();
	undoStack.AddRear(concreteCommand);

	// Redo 스택은 명령을 실행할 때마다 비워야 함
	ClearRedo();
}

void CommandInvoker::UndoCommand()
{
	if(undoStack.IsEmpty())
	{
		std::cout << "Undo 스택이 비어 있음\n";
		return;
	}

	ICommand* command = nullptr;
	if(undoStack.GetRear(command))
	{
		if (command->Undo()) // 실행 취소
		{
			undoStack.DeleteRear(); // 실행 취소가 성공하면 스택에서 제거

			while(!redoStack.AddRear(command))
			{
				ICommand* discardOldCommand = nullptr;
				redoStack.GetFront(discardOldCommand);
				delete discardOldCommand; // 오래된 명령 제거
			}
		}
	}
	else
	{
		std::cout << "Undo 스택에서 명령을 꺼내는 데 실패\n";
	}
}

void CommandInvoker::RedoCommand()
{
	if (redoStack.IsEmpty())
	{
		std::cout << "Redo 스택이 비어 있음\n";
		return;
	}

	ICommand* command = nullptr;
	if (redoStack.GetRear(command))
	{
		if (command->Execute()) // 다시 실행
		{
			redoStack.DeleteRear();

			while (!undoStack.AddRear(command))
			{
				ICommand* discardOldCommand = nullptr;
				undoStack.GetFront(discardOldCommand);
				delete discardOldCommand; // 오래된 명령 제거
			}
		}
	}
	else
	{
		std::cout << "Redo 스택에서 명령을 꺼내는 데 실패\n";
	}
}

void CommandInvoker::Show() const
{
	std::cout << "Undo 스택";
	undoStack.Display();

	std::cout << "Redo 스택";
	redoStack.Display();
}

void CommandInvoker::ClearUndo()
{
	while (!undoStack.IsEmpty())
	{
		ICommand* command = nullptr;
		if (undoStack.GetFront(command))
		{
			delete command;
			command = nullptr;
			undoStack.DeleteFront();
		}
	}
}

void CommandInvoker::ClearRedo()
{
	while (!redoStack.IsEmpty())
	{
		ICommand* command = nullptr;
		if (redoStack.GetFront(command))
		{
			delete command;
			command = nullptr;
			redoStack.DeleteFront();
		}
	}
}
