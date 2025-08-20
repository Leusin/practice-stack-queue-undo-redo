# Command 패턴 메모

## 사용 목적
- 일련의 특정 행동 추적
- 실행 취소/재실행 또는 입력 내역이 필요한 경우 사용 
- ex) 여러 턴을 실행 하기 전에 계획할 수 있는 전략 게임

## 특징
- 특정 행동을 캡슐화
- 캡슐화한 객체들을 큐 또는 스택같은 자료구조에 저장
- 구현 방법이 어려가지 버전이 존재

## 주요 요소
- Command: 특정 행동을 캡슐화하는 추상 클래스 또는 인터페이스
- ConcreteCommand: Receiver 객체의 특정 메서드를 호출하는 구체 클래스
- Receiver: 요청을 실제로 수행하는 객체
- Invoker: Command 객체의 동작을 실행하는 객체
- Client: ConcreteCommand를 생성하고 Invoker에 전달하는 객체

### 객체간의 관계
- Invoker는 Command 객체에 의존하지만 ConcreteCommand 클래스와 Receiver 클래스에 대해 알지 못함
- Receiver는 Command 객체를 알지 못함

# 참고
- https://unity.com/kr/resources/level-up-your-code-with-game-programming-patterns