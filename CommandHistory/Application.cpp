#include "Application.h"

#include "Command/AddInputCommand.h"


void Application::Run()
{
	std::cout << "1) 추가 가능한 문자: 'A', 'B', 'C', 'D', 'E', 'F'\n";
	std::cout << "2) 실행 가능한 명령어: 'undo', 'redo', 'show'\n";
	std::cout << "3) 프로그램 종료: 'q' or 'Q'\n";

	while (true)
	{
		char input[100];
		std::cout << ": ";
		std::cin >> input;

		if (strcmp(input, "q") == 0 || strcmp(input, "Q") == 0)
		{
			break;
		}

		//
		// 문자 입력 처리
		// 

		bool result = false;
		for (const char& c : availableInputs)
		{
			char str[2] = { c, '\0' };
			result = strcmp(input, str) == 0;
			if (result)
			{
				GetInput(input[0]);
				break;
			}
		}

		if (result)
		{
			continue;
		}

		//
		// 명령어 처리
		//

		if (strcmp(input, "undo") == 0)
		{
			invoker.UndoCommand();
			continue;
		}

		else if (strcmp(input, "redo") == 0)
		{
			invoker.RedoCommand();
			continue;
		}

		else if (strcmp(input, "show") == 0)
		{
			std::cout << "-------------------------------------------\n";
			invoker.Show();
			keyInputManager.Display();
			std::cout << "-------------------------------------------\n";
			continue;
		}

		std::cout << "[오류] 입력을 처리하지 못함\n";
	}
}

void Application::GetInput(char input)
{
	invoker.ExecuteCommand(new AddInputCommand(input, keyInputManager));
}
