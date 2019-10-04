<<<<<<< HEAD
/*
 * Stack.cpp
 *
 *  Created on: 2019. 3. 29.
 *      Author: ykoou
 */

#include <cstdlib>
#include <iostream>

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

int main(){
	Stack s;

	bool balanced = true;
	char symbol;
	char open_symbol;

	while(cin.get(symbol) && balanced) { //cin.get 은  한 문자씩 받아오는 것. 종료는 ctrl+z
		if(symbol == '(')
			s.push(symbol);
		else if(symbol == ')'){
			if(s.is_empty()){
				balanced = false;
			}
			else{
				open_symbol = s.pop();
				balanced = (open_symbol == '(' && symbol == ')');
			}
		}
	}

	if(!balanced)
		cout << "unbalanced" << endl;
	else if(s.is_empty())
		cout << "balanced" << endl;
	else
		cout << "unbalanced" << endl;

	return 0;
}
=======
/*
 * Stack.cpp
 *
 *  Created on: 2019. 3. 29.
 *      Author: ykoou
 */

#include <cstdlib>
#include <iostream>

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

int main(){
	Stack s;

	bool balanced = true;
	char symbol;
	char open_symbol;

	while(cin.get(symbol) && balanced) { //cin.get 은  한 문자씩 받아오는 것. 종료는 ctrl+z
		if(symbol == '(')
			s.push(symbol);
		else if(symbol == ')'){
			if(s.is_empty()){
				balanced = false;
			}
			else{
				open_symbol = s.pop();
				balanced = (open_symbol == '(' && symbol == ')');
			}
		}
	}

	if(!balanced)
		cout << "unbalanced" << endl;
	else if(s.is_empty())
		cout << "balanced" << endl;
	else
		cout << "unbalanced" << endl;

	return 0;
}
>>>>>>> 703c4cd30b5df7fc525d0c1e7238cdd23ea21d06
