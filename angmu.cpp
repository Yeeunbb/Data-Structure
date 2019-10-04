#include <cstdlib> //헤더함수. C의 stdio.h와 비슷
#include <iostream> //C++의 헤더함수

using namespace std;


const int MAX_STACK_SIZE = 100; //배열의 최대크기 100
typedef int ItemType; //int형 자료형

class Stack{ //stack 클래스
	int top; //데이터 값의 위치
	ItemType data[MAX_STACK_SIZE]; //크기를 100으로 가지는 int형 배열

public:
	Stack(); //생성자
	~Stack(); //소멸자
	bool is_empty(); //stack이 비어있는지 확인
	bool is_full(); //stack이 차있는지 확인
	void push(ItemType item); //stack에 item값 저장
	ItemType pop(); //가장 최근에 들어온 값 삭제
};

Stack::Stack(){ //생성자
	top = -1; //초기 데이터값 위치는 -1. 배열의 인덱스가 0부터 시작하기 떄문
}

Stack::~Stack(){} //소멸자

bool Stack::is_empty(){ //stack이 비어있는지 확인
	return top == -1; //데이터값의 위치가 -1 = 스택이 비어있음. true 반환
}

bool Stack::is_full(){ //stack이 가득차있는지 확인
	return top==MAX_STACK_SIZE-1; //데이터값의 위치가 배열인덱스 -1=배열이 꽉차있음. ture 반환
}

void Stack::push(ItemType item){ //stack에  item값 저장
	if(is_full()){ //stack이 꽉 차있는 경우
		cout << "스택 포화 오류" << endl;
		exit(1); //오류문구 출력후 종료
	}
	else //stack에 공간이 있는 경우
		data[++top] = item; //데이터값 한칸 증가시킨뒤 값 저장
}

ItemType Stack::pop(){ //가장 최근에 들어온 데이터 삭제
	if(is_empty()){ //스택이 비어있는 경우
		cout << "스택 비어있음 오류" << endl;
		exit(1); //오류문구 출력후 종료
	}
	else{ //스택이 비어있지 않은 경우
		ItemType item = data[top]; //item은 최근에 들어왔던 데이터 값
		top--; //데이터값 한칸 삭제
		return item; //최근에 들어왔던 값 반환
		//return data[top--]; ->이렇게 한줄로 쓸 수 있음
	}
}

int main(){ //메인함수
	Stack s; //괄호를 저장할 스택 s

	bool balanced = true; //초기 balanced값은 true
	char symbol; //입력받을 문구를 저장할 변수
	char open_symbol; //닫힌 괄호가 들어왔을때 스택에 있던 열린괄호를 저장할 변수

	while(cin.get(symbol) && balanced) { //cin.get 은  한 문자씩 받아오는 것. 종료는 ctrl+z
		if(symbol == '(' || symbol == '{' || symbol == '[') //닫힌 괄호가 들어올때
			s.push(symbol); //스택에 저장
		else if(symbol == ')' || symbol == '}' || symbol == ']'){ //열린괄호가 들어올때
			if(s.is_empty()){ //스택이 비어있는 경우
				balanced = false; //while문 종료
			}
			else{ //스택이 비어있지 않은 경우
				open_symbol = s.pop(); //최근에 저장된 열린괄호 pop
				balanced = ((open_symbol == '(' && symbol == ')') || (open_symbol == '{' && symbol == '}') || (open_symbol == '[' && symbol == ']'));
			} //괄호쌍 검사
		}
	}

	if(!balanced) //balanced = false일때
		cout << "-1" << endl; //-1출력
	else if(s.is_empty() && balanced) //stack이 비어있고 balanced = ture일때
		cout << "1" << endl; //1 출력
	else //스택이 비어있지 않을때
		cout << "-1" << endl; //-1 출력

	return 0; //프로그램종료
}
