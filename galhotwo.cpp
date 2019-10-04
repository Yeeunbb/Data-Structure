#include <cstdlib> //헤더함수. C의 stdio.h와 비슷
#include <iostream> //C++의 헤더함수

using namespace std;


const int MAX_STACK_SIZE = 100; //배열의 최대크기 100
typedef int ItemType; //int형 자료형

struct Node //Node 구조체
{
	ItemType info; //값을 넣을 변수
	Node *next; //다음 노드를 연결할 포인터
};

class Stack{ //stack 클래스
	Node *topPtr; //스택의 탑을 가리키는 포인터

public:
	Stack(); //생성자
	~Stack(); //소멸자
	bool is_empty() const; //stack이 비어있는지 확인
	//bool is_full() const; //stack이 차있는지 확인
	void push(ItemType item); //stack에 item값 저장
	ItemType pop(); //가장 최근에 들어온 값 삭제
};

Stack::Stack(){ //생성자
	topPtr = NULL; //초기 탑 노드는 NULL
}

Stack::~Stack(){
	Node *tempPtr;// 임시 노드

	while(topPtr != NULL) //topPtr이 빌때까지 반복
	{
		tempPtr = topPtr;
		topPtr = topPtr->next;
		delete tempPtr; //데이터 반납
	}
} //소멸자

bool Stack::is_empty() const{ //stack이 비어있는지 확인
	return topPtr == NULL; //데이터값의 위치가 -1 = 스택이 비어있음. true 반환
}

void Stack::push(ItemType item){ //stack에  item값 저장
		Node *newNode; //새로운 노드
		newNode = new Node; //동적할당
		newNode->info = item; //입력받은 item값 저장
		newNode->next = topPtr; //다음 노드와 연결
		topPtr = newNode; //마지막에 들어온 노드로 저장
}

ItemType Stack::pop(){ //가장 최근에 들어온 데이터 삭제
	if(is_empty()){ //스택이 비어있는 경우
		cout << "스택 비어있음 오류" << endl;
		exit(1); //오류문구 출력후 종료
	}
	else{
		ItemType item;
		Node *tempPtr;
		item = topPtr->info; //item은 노드에 저장되있던 정보
		tempPtr = topPtr; //임시노드에 지울 노드 저장
		topPtr = topPtr->next; //노드 삭제
		delete tempPtr; //노드 삭제
		return item; //값 반환
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


