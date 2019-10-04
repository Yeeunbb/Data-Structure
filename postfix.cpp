#include <iostream> //헤더함수
#include <cstdlib> //헤더함수. atof 함수사용
#include <string> //헤더함수. string 객체 사용
#include <iomanip> //헤더함수. 소수점출력

using namespace std;

const int MAX_STACK_SIZE = 100; //스택 data크기
typedef float ItemType; //실수형 타입지정자

class Stack{ //stack class
	int top; //stack데이타의 위치
	ItemType data[MAX_STACK_SIZE]; //stack의 data를 저장하는 정적배열

public:
	Stack(); //생성자
	~Stack(); //소멸자
	bool is_empty(); //스택이 비었는지 확인하는 함수
	bool is_full(); //스택이 다 차있는지 확인하는 함수
	void push(ItemType item); //스택에 값을 입력하는 함수
	ItemType pop(); //가장 최근값을 반환한뒤 삭제하는 함수
};

Stack::Stack(){ //생성자
	top = -1; //스택의 초기 위치값은 -1. 배열의 인덱스 첫번째 값이 0이니까
}

Stack::~Stack(){} //소멸자

bool Stack::is_empty(){
	return top == -1; //스택이 비어있다면 top값은 -1일 것이고 true를 반환함.
}

bool Stack::is_full(){
	return top==MAX_STACK_SIZE-1; //스택이 최대값 만큼 차있다면 top값은 99일 것이고 true를 반환함.
}

void Stack::push(ItemType item){
	if(is_full()){
		//cout << "스택 포화 오류" << endl;
		//exit(1);
		return; //메인에서 오류설정을 따로 해주므로 push에서 따로 오류출력 하지않음.
	}
	else
		data[++top] = item; //스택이 꽉차있지 않은 경우 입력받은 값 item을 data에 저장.
}

ItemType Stack::pop(){
	if(is_empty()){
		//cout << "스택 비어있음 오류" << endl;
		//exit(1);
		return 0; //메인에서 오류설정을 따로 해주므로 pop에서 따로 오류출력 하지않음.
	}
	else{ //스택이 비어있지 않은 경우
		ItemType item = data[top]; //값을 반환하기위해 변수 item에 data의 top 값을 저장
		top--; //top에 저장되어있던 값 삭제
		return item; //미리 저장해두었던 top값 반환
		//return data[top--]; 이런식으로 한줄로 쓸 수 있음
	}
}

int main() { //메인함수
	string token; //입력받을 연산자와 피연산자를 저장할 변수
	Stack s; //연산한 값을 저장할 공간

	while (cin >> token) { //break를 만나기 전까지 계속해서 token을 입력받음
		if(token == ";")
			break; //token이 ';'일때 반복문 종료

		else if(isdigit(token[0])) { //입력받은 token이 숫자(양의실수)일때
			s.push(atof(token.c_str())); //스택s에 문자로 입력받은 token의 값을 실수로 저장
		}

		else if(token[0] == '-' && isdigit(token[1])) { //입력받은 token이 음수일때
			s.push(atof(token.c_str())); //스택s에 문자로 입력받은 음수를 실수값으로 저장
		}

		else if (token == "+") { //+ 연산일때
			if (s.is_empty()) { //피연산자가 없는 경우
				cout << "error 1" << endl; //error1 출력
				return 0; //종료
			}
			ItemType second = s.pop(); //나중에 들어온 값을 second에 저장

			if (s.is_empty()) { //피연산자가 없는 경우
				cout << "error 1" << endl; //error 1 출력
				return 0; //종료
			}
			ItemType first = s.pop(); //먼저 입력받은 값을 first에 저장
			s.push(first + second); //입력받은 값에 대한 더하기 연산값 저장
		}

		else if( token == "-") { //- 연산일때
			if(s.is_empty()){ //피연산자가 없는 경우
				cout <<"error 1" <<endl; //error 1 출력
				return 0; //종료
			}
			ItemType second = s.pop(); //나중에 들어온 값을 second에 저장

			if(s.is_empty()) { //피연산자가 없는 경우
				cout <<"error 1" <<endl; //error 1 출력
				return 0; //종료
			}
			ItemType first = s.pop(); //먼저 입력받았던 값을 first에 저장
			s.push(first - second); //입력받은 피연산자들에 대한 -연산 결과값 저장
		}

		else if(token =="*") { //* 연산일때
			if(s.is_empty()) { //피연산자가 없는 경우
				cout << "error 1" << endl; //error 1 출력
				return 0; //종료
			}
			ItemType second = s.pop(); //나중에 들어온 값을 second에 저장

			if(s.is_empty()) { //피연산자가 없는 경우
				cout << "error 1" << endl; //error 1 출력
				return 0; //종료
			}
			ItemType first = s.pop(); //먼저 들어온 값 first에 저장
			s.push(first * second); //피연산자들에 대한 *연산 결과값 저장
		}

		else if(token == "/") { //나누기 연산일 떄
			if(s.is_empty()) { //피연산자가 없는 경우
				cout<< "error 1" <<endl; //error 1 출력
				return 0; //종료
			}
			ItemType second = s.pop(); //나중에 들어온 값 second에 저장

			if(s.is_empty()) { //피연산자가 없는 경우
				cout << "error 1" <<endl; //error 1 출력
				return 0; //종료
			}
			ItemType first = s.pop(); //먼저 들어온 값 first에 저장
			s.push(first / second); //피연산자들에 대한 나누기 연산값 저장
		}

		/*else if(token == "%") {
			if(s.is_empty()) {
				cout << "error" << endl;
				return 1;
			}
			ItemType second = s.pop();

			if(s.is_empty()) {
				cout << "error" <<endl;
				return 1;
			}
			ItemType first = s.pop();
			s.push(first % second);
		} */
	}

	ItemType result = s.pop(); //연산의 최종 결과값 저장

	if(!s.is_empty()) { //피연산자에 대한 연산자가 없는경우. = 피연산자가 남는 경우
		cout << "error 2" << endl; //error 2 출력
		return 0; //종료
	}

	cout << fixed << setprecision(2) << result << endl; //총 결과값을 소수점 2자리까지 출력

	return 0; //종료
}



