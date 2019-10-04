#include <iostream> //iostream 헤더함수  포함
#include <string> //string 헤더함수 포함

using namespace std;
//계산기 프로그램
class Calculator{ //Calculator 클래스
	int c_value; //현재 값을 저장하는 변수
	int m_value; //메모리에 저장한 값을 저장하는 변수

public:
	Calculator(int initial); //생성자
	void set_value(int value); //현재 값을 설정해주는 함수
	int get_value(); //현재 값을 반환하는 함수
	void add(int value); //더하기 연산을 실행하는 함수
	void sub(int value); //빼기 연산을 실행하는 함수
	void multiply(int value); //곱하기 연산을 실행하는 함수
	void divide(int value); //나누기 연산을 실행하는 함수
	void mod(int value); //나누기의 나머지 값을 구하는 함수
	void change_sign(); //현재 값의 부호를 바꾸는 함수
	void clear(); //현재 값을 0으로 바꿔주는 함수
	void memory_save(); //현재 값을 메모리에 저장하는 함수
	void memory_read(); //메모리에 있는 값을 현재 값으로 설정하는 함수
	void memory_clear(); //메모리에 저장된 값을 0으로 바꾸는 함수
	void memory_add(); //메모리에 저장되어 있는 값에 현재 값을 더하여 그 값을 저장하는 함수
	void memory_sub(); //메모리에 저장되어 있는 값에 현재 값을 빼서 그 값을 저장하는 함수

};

Calculator::Calculator(int initial){
	c_value = initial;	//현재 값에 initial 값을 저장
	m_value = initial; //메모리 값에 initial 값을 저장
}

void Calculator::set_value(int value){
	c_value = value; //현재 값을 value로 바꿈
}

int Calculator::get_value(){
	return c_value; //현재 값 반환
}

void Calculator::add(int value){
	c_value += value; //현재 값에 value값을 더하여 저장
}

void Calculator::sub(int value){
	c_value -= value; //현재 값에 value값을 뺀 후 저장
}

void Calculator::multiply(int value){
	c_value *= value; //현재 값에 value값을 곱한 후 저장
}

void Calculator::divide(int value){
	c_value /= value; //현재 값에 value값을 나눈 후 몫을 저장
}

void Calculator::mod(int value){
	c_value %= value; //현재 값에 value를 나눈 후 나머지를 저장
}

void Calculator::change_sign(){
	c_value = -c_value; //현재 값의 부호를 바꾼 후 저장
}

void Calculator::clear(){
	c_value = 0; //현재 값을 0으로 설정
}

void Calculator::memory_save(){
	m_value = c_value; //메모리 값에 현재 값을 저장
}

void Calculator::memory_read(){
	c_value = m_value; //현재 값에 메모리 값을 저장
}

void Calculator::memory_clear(){
	m_value = 0; //메모리 값을 0으로 설정
}

void Calculator::memory_add(){
	m_value += c_value; //메모리값에 현재값을 더한 후 저장
}

void Calculator::memory_sub(){
	m_value -= c_value; //메모리값에 현재 값을 뺀 후 저장
}

int main() //메인함수
{
	Calculator cal(0); //Calculator클래스 cal생성. 초기값 0설정
	string EXITCMD = "exit"; //프로그램 종료문구 설정
	string command; //입력받을 명령어 변수

	int operand; //계산할 숫자 변수

	cin >> command; //명령어 입력

	while (command != EXITCMD){ //프로그램 종료문구 입력 전까지 반복되는 반복문
		if(command == "clear") //명령어가 clear일 때
			cal.clear(); //cal클래스에 clear함수 실행

		else if(command == "cs") //명령어가 cs일 떄
			cal.change_sign(); //cal클래스에 change_sign함수 실행

		else if(command == "MS") //명령어가 MS일 때
			cal.memory_save(); //cal클래스에 memory_save함수 실행

		else if(command == "MR") //명령어가 MR일 떄
			cal.memory_read(); //cal클래스에 memory_read함수 실행

		else if(command == "M+") //명령어가 M+일 때
			cal.memory_add(); //cal클래스에 memory_add함수 실행

		else if(command == "M-") //명령어가 M-일 때
			cal.memory_sub(); //cal클래스에 memory_sub함수 실행

		else if(command == "MC") //명령어가 MC일 때
			cal.memory_clear(); //cal클래스에 memory_clear함수 실행

		else
		{ //명령어 + 계산할 숫자를 입력받음
			cin >> operand;
			if (command == "add") { //명령어가 add일 때
				cal.add(operand); //cal클래스에 add함수 실행
			}

			else if (command == "sub") { //명령어가 sub일 때
				cal.sub(operand); //cal클래스에 sub함수 실행
			}

			else if (command == "mul") { //명령어가 mul일 때
				cal.multiply(operand); //cal클래스에 multiply함수 실행
			}

			else if (command == "div") { //명령어가 div일 때
				cal.divide(operand); //cal클래스에 divide함수 실행
			}

			else if (command == "mod") { //명령어가 mod일 때
				cal.mod(operand); //cal클래스에 mod함수 실행
			}

			else if (command == "setValue") { //명령어가setValue일 때
				cal.set_value(operand); //cal클래스에 set_value함수 실행
			}
		}

		cout << cal.get_value() << endl; //cal클래스의 현재값 반환
		cin >> command; // 계산기 명령어 다시 입력받음
	}

	return 0; //메인함수 종료
}
