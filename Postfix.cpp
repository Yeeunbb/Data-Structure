/*
 * Postfix.cpp
 *
 *  Created on: 2019. 3. 29.
 *      Author: ykoou
 */

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

const int MAX_STACK_SIZE = 100;
typedef int ItemType;

class Stack{
	int top;
	ItemType data[MAX_STACK_SIZE];

public:
	Stack();
	~Stack();
	bool is_empty();
	bool is_full();
	void push(ItemType item);
	ItemType pop();
};

Stack::Stack(){
	top = -1;
}

Stack::~Stack(){}

bool Stack::is_empty(){
	return top == -1;
}

bool Stack::is_full(){
	return top==MAX_STACK_SIZE-1;
}

void Stack::push(ItemType item){
	if(is_full()){
		cout << "스택 포화 오류" << endl;
		exit(1);
	}
	else
		data[++top] = item;
}

ItemType Stack::pop(){
	if(is_empty()){
		cout << "스택 비어있음 오류" << endl;
		exit(1);
	}
	else{
		ItemType item = data[top];
		top--;
		return item;
		//return data[top--];
	}
}

int main() {
	string token;
	Stack s;

	while (cin >> token) { //50 60 + 10 - ;
		if(token == ";")
			break;

		else if(isdigit(token[0])) {
			s.push(atoi(token.c_str()));
		}
		//음수 입력을 받아오기 위해서는 이곳에 else if로. ..
		else if (token == "+") {
			if (s.is_empty()) {
				cout << "error" << endl;
				return 1;
			}
			ItemType second = s.pop();

			if (s.is_empty()) {
				cout << "error" << endl;
				return 1;
			}
			ItemType first = s.pop();
			s.push(first + second);
		}

		else if( token == "-") {
			if(s.is_empty()){
				cout <<"error" <<endl;
				return 1;
			}
			ItemType second = s.pop();

			if(s.is_empty()) {
				cout <<"error" <<endl;
				return 1;
			}
			ItemType first = s.pop();
			s.push(first - second);
		}

		else if(token =="*") {
			if(s.is_empty()) {
				cout << "error" << endl;
				return 1;
			}
			ItemType second = s.pop();

			if(s.is_empty()) {
				cout << "error" << endl;
				return 1;
			}
			ItemType first = s.pop();
			s.push(first * second);
		}

		else if(token == "/") {
			if(s.is_empty()) {
				cout<< "error" <<endl;
				return 1;
			}
			ItemType second = s.pop();

			if(s.is_empty()) {
				cout << "error" <<endl;
				return 1;
			}
			ItemType first = s.pop();
			s.push(first / second);
		}

		else if(token == "%") {
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
		}
	}
	ItemType result = s.pop();
	cout << result << endl;

	return 0;
}

