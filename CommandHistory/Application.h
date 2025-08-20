#pragma once

#include <iostream>

#include "CommandInvoker.h"
#include "KeyInputManager.h"

/// <summary>
/// - 진입점
/// - Command 패턴의 Client 로써 ConcreteCommand를 생성하고 Invoker에 전달하는 객체
/// </summary>
class Application
{
public: // RAII
	Application() = default;
	~Application() = default;

public: // MESSAGE
	void Run();

	void GetInput(char input);

private:
	char availableInputs[6] = { 'A', 'B', 'C', 'D', 'E', 'F' };

	CommandInvoker invoker; // CommandInvoker 객체, 명령 실행 기록을 관리하는 Invoker
	KeyInputManager keyInputManager; // 입력받은 키들의 큐 관리
};