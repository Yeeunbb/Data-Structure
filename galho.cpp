#include <cstdlib> //헤더함수. C의 stdio.h와 비슷
#include <iostream> //c++의 헤더함수

using namespace std;


const int MAX_STACK_SIZE = 100; //스택의 최대 크기
typedef int ItemType; //ItemType은 int형 변수

class Stack{ //stack 클래스
	int top; //데이타 값의 위치를 나타낼 변수
	ItemType data[MAX_STACK_SIZE]; //크기를 100으로 가지는 int형 배열

public:
	Stack(); //생성자
	~Stack(); //소멸자
	bool is_empty(); //스택이 비어있는지 확인할 함수
	bool is_full(); //스택이 가득 차있는지 확인할 함수
	void push(ItemType item); //스택에 값을 저장하는 함수
	ItemType pop(); //스택의 저장된 값을 삭제하는 함수
};

Stack::Stack(){ //생성자
	top = -1; //초기 스택데이타 값의 위치는 -1. 배열의 인덱스는 0부터 시작이므로
}

Stack::~Stack(){} //소멸자

bool Stack::is_empty(){ //스택이 비어있는지 확인
	return top == -1; //데이타가 없는 경우 true를 반환
}

bool Stack::is_full(){ //스택이 가득 차있는지 확인
	return top==MAX_STACK_SIZE-1; //데이타가 가득차있는 경우 true를 반환
}

void Stack::push(ItemType item){ //스택에 값을 저장하는 함수
	if(is_full()){ //스택이 가득 차있는 경우
		//cout << "스택 포화 오류" << endl;
		return; //아무것도 반환하지 않음
	}
	else //스택이 차있지 않은 경우
		data[++top] = item; //입력받은 item을 스택에 저장
}

ItemType Stack::pop(){ //가장 최근에 들어온 값을 삭제하는 함수
	if(is_empty()){ //스택이 비어있는 경우
		//cout << "스택 비어있음 오류" << endl;
		return 1; //1을반환
	}
	else{ //스택이 비어있지 않은 경우
		ItemType item = data[top]; //값을 반환하기위해 임시로 item에 저장
		top--; //최근에 입력받았던 데이터값 삭제
		return item; //임시로 저장해놨던 값 반환
		//return data[top--]; ->이렇게 한줄로 쓸 수 있음
	}
}

int main(){ //메인함수
	Stack s; //여는괄호를 저장할  스택
	Stack l; //괄호가 몇번째 줄에 있는지 저장할 스택

	bool balanced = true; //밸런스 초기값은 true
	int line_num=1; //line 초기값은 1
	int error_num=0; //error 초기값 0
	int error_line=0; //error 1,2,3 에 사용할 line 변수
	char symbol; //입력받는 symbol 변수
	char open_symbol; //닫힌 괄호가 들어올때 열린 괄호를 저장할 변수
	char close_symbol; //error 4,5,6을 처리할 변수

	while(cin.get(symbol) && balanced) { //cin.get 은  한 문자씩 받아오는 것. 종료는 ctrl+z
		if(symbol == '(' || symbol == '{' || symbol == '['){ //열린괄호를 입력받았을때
			s.push(symbol); //스택s에 저장
			l.push(line_num); //열린괄호가 몇번째 줄에 있는지 저장
			}
		else if(symbol =='\n') { //줄넘김이 입력으로 들어올때
			line_num++; //line 값 증가
		 }
		else if(symbol == ')' || symbol == '}' || symbol == ']'){ //닫힌괄호를 입력받았을 때
			if(s.is_empty()){ //스택이 비어있는 경우
				if(symbol == ')') { //입력이 ')' 괄호인 경우
					error_num=1; //error번호는 1
					error_line = line_num; } //error가 발생한 line의 값은 현재의 line
				else if(symbol == '}') { //입력이 '}' 괄호인 경우
					error_num=2; //error번호는 2
					error_line = line_num; } //error가 발생한 line의 값은 현재의 line
				else if(symbol == ']') { //입력이 ']' 괄호인 경우
					error_num=3; //error번호는 3
					error_line = line_num; } //error가 발생한 line의 값은 현재의 line
				balanced = false; //밸런스가 false가 되면서 반복문 종료
				}

			else{ //스택이 비어있지 않은 경우
				open_symbol = s.pop(); //가장 최근에 입력받은 열린괄호를 open_symbol에 저장

				if(symbol == ')' && open_symbol != '('){ //괄호쌍 '()'이 아닐때
					error_num=1; //error번호는 1
					error_line = line_num; } //error가 발생한 line의 값은 현재의 line
				else if(symbol == '}' && open_symbol != '{'){ //괄호쌍 '{}'이 아닐때
					error_num=2; //error번호는 2
					error_line = line_num; } //error가 발생한 line의 값은 현재의 line
				else if(symbol == ']' && open_symbol != '['){ //괄호쌍 '[]'이 아닐때
					error_num=3; //error번호는 3
					error_line = line_num; } //error가 발생한 line의 값은 현재의 line

				balanced = ((open_symbol == '(' && symbol == ')') || (open_symbol == '{' && symbol == '}') || (open_symbol == '[' && symbol == ']'));
			} //밸런스는 옳바른 괄호쌍이 입력됐을 경우 true.
			l.pop(); //닫힌 괄호가 들어와서 열린괄호가 pop되므로 몇번째 줄에있었는지에 대한 정보도 pop
		}
	}

	if(!balanced) { //balanced = false 일때
		switch(error_num) { //error_num에 따른 switch문
			case 1: cout << "error 1 at line " << error_line << endl;
				break; //error_num = 1인 경우
			case 2: cout << "error 2 at line " << error_line << endl;
				break; //error_num = 2인 경우
			case 3: cout << "error 3 at line " << error_line << endl;
				break; //error_num = 3인 경우
		}
	}
	else if(!s.is_empty()) { //스택s가 비어있지 않은 경우
		close_symbol = s.pop(); //남은 열린 symbol이 뭔지 close_symbol에 저장
		switch(close_symbol) { //clse_symbol에 따른 switch문
			case '(': cout << "error 4 at line " << l.pop() << endl;
				break; //'('괄호가 남았을 경우 error번호는 4
			case '{': cout << "error 5 at line " << l.pop() << endl;
				break; //'{'괄호가 남았을 경우 error번호는 5
			case '[': cout << "error 6 at line " << l.pop() << endl;
				break; //'['괄호가 남았을 경우 error번호는 6
			}
	}
	else //balanced=true 일 때
	{
		cout << "1" << endl; //1출력
	}

	return 0; //프로그램 종료
}
