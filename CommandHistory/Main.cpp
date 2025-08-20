/*
* - 요구 사항
* [] 입력 Queue 직접 구현: 키보드 이벤트를 저장할 수 있는 입력 큐를 직접 작성
* [] Stack 직접 구현: Undo 목록을 저장할 스택 / Redo 목록을 저장할 스택을 직접 작성
* [] 명령 패턴을 활용해 구현하기
*	[] Command 패턴을 찾아 학습하고 이를 활용해 구현
*	[] (제안): Undo/Redo 기록 시스템을 구현하는 다른 방법론도 함께 살펴보기
* - 동작
* [] ‘A’, ‘B’, ‘C’, ‘D’, ‘E’ 키를 입력 받기
* [] 들어온 입력을 입력 Queue에 넣기
* [] 입력 Queue에 들어온 순서대로 Undo 스택에 기록
* [] “undo” 명령어를 입력하면 undo 실행
* [] “redo” 명령어를 입력하면 redo 실행
* [] “show” 명령어를 입력하면 undo 스택과 redo 스택에 저장된 명령 내용 출력
*/

#include <iostream>

#include "Queue.h"
#include "Stack.h"

int main()
{
	char inputs[] = { 'A', 'B', 'C', 'D', 'E', 'F'};

	Queue<char> q;
	Stack<char> s;

	for (const auto& e : inputs)
	{
		q.Enqueue(e);
		s.Push(e);
	}

	for (const auto& e : inputs)
	{
		q.Enqueue(e);
		s.Push(e);
	}
	
	s.Display();

	char out;
	s.Pop(out);
	s.Pop(out);
	s.Display();

	s.Pop(out);
	s.Pop(out);
	s.Pop(out);
	s.Display();


	std::cin.get();

	return 0;
}