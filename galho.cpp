#include <cstdlib> //����Լ�. C�� stdio.h�� ���
#include <iostream> //c++�� ����Լ�

using namespace std;


const int MAX_STACK_SIZE = 100; //������ �ִ� ũ��
typedef int ItemType; //ItemType�� int�� ����

class Stack{ //stack Ŭ����
	int top; //����Ÿ ���� ��ġ�� ��Ÿ�� ����
	ItemType data[MAX_STACK_SIZE]; //ũ�⸦ 100���� ������ int�� �迭

public:
	Stack(); //������
	~Stack(); //�Ҹ���
	bool is_empty(); //������ ����ִ��� Ȯ���� �Լ�
	bool is_full(); //������ ���� ���ִ��� Ȯ���� �Լ�
	void push(ItemType item); //���ÿ� ���� �����ϴ� �Լ�
	ItemType pop(); //������ ����� ���� �����ϴ� �Լ�
};

Stack::Stack(){ //������
	top = -1; //�ʱ� ���õ���Ÿ ���� ��ġ�� -1. �迭�� �ε����� 0���� �����̹Ƿ�
}

Stack::~Stack(){} //�Ҹ���

bool Stack::is_empty(){ //������ ����ִ��� Ȯ��
	return top == -1; //����Ÿ�� ���� ��� true�� ��ȯ
}

bool Stack::is_full(){ //������ ���� ���ִ��� Ȯ��
	return top==MAX_STACK_SIZE-1; //����Ÿ�� �������ִ� ��� true�� ��ȯ
}

void Stack::push(ItemType item){ //���ÿ� ���� �����ϴ� �Լ�
	if(is_full()){ //������ ���� ���ִ� ���
		//cout << "���� ��ȭ ����" << endl;
		return; //�ƹ��͵� ��ȯ���� ����
	}
	else //������ ������ ���� ���
		data[++top] = item; //�Է¹��� item�� ���ÿ� ����
}

ItemType Stack::pop(){ //���� �ֱٿ� ���� ���� �����ϴ� �Լ�
	if(is_empty()){ //������ ����ִ� ���
		//cout << "���� ������� ����" << endl;
		return 1; //1����ȯ
	}
	else{ //������ ������� ���� ���
		ItemType item = data[top]; //���� ��ȯ�ϱ����� �ӽ÷� item�� ����
		top--; //�ֱٿ� �Է¹޾Ҵ� �����Ͱ� ����
		return item; //�ӽ÷� �����س��� �� ��ȯ
		//return data[top--]; ->�̷��� ���ٷ� �� �� ����
	}
}

int main(){ //�����Լ�
	Stack s; //���°�ȣ�� ������  ����
	Stack l; //��ȣ�� ���° �ٿ� �ִ��� ������ ����

	bool balanced = true; //�뷱�� �ʱⰪ�� true
	int line_num=1; //line �ʱⰪ�� 1
	int error_num=0; //error �ʱⰪ 0
	int error_line=0; //error 1,2,3 �� ����� line ����
	char symbol; //�Է¹޴� symbol ����
	char open_symbol; //���� ��ȣ�� ���ö� ���� ��ȣ�� ������ ����
	char close_symbol; //error 4,5,6�� ó���� ����

	while(cin.get(symbol) && balanced) { //cin.get ��  �� ���ھ� �޾ƿ��� ��. ����� ctrl+z
		if(symbol == '(' || symbol == '{' || symbol == '['){ //������ȣ�� �Է¹޾�����
			s.push(symbol); //����s�� ����
			l.push(line_num); //������ȣ�� ���° �ٿ� �ִ��� ����
			}
		else if(symbol =='\n') { //�ٳѱ��� �Է����� ���ö�
			line_num++; //line �� ����
		 }
		else if(symbol == ')' || symbol == '}' || symbol == ']'){ //������ȣ�� �Է¹޾��� ��
			if(s.is_empty()){ //������ ����ִ� ���
				if(symbol == ')') { //�Է��� ')' ��ȣ�� ���
					error_num=1; //error��ȣ�� 1
					error_line = line_num; } //error�� �߻��� line�� ���� ������ line
				else if(symbol == '}') { //�Է��� '}' ��ȣ�� ���
					error_num=2; //error��ȣ�� 2
					error_line = line_num; } //error�� �߻��� line�� ���� ������ line
				else if(symbol == ']') { //�Է��� ']' ��ȣ�� ���
					error_num=3; //error��ȣ�� 3
					error_line = line_num; } //error�� �߻��� line�� ���� ������ line
				balanced = false; //�뷱���� false�� �Ǹ鼭 �ݺ��� ����
				}

			else{ //������ ������� ���� ���
				open_symbol = s.pop(); //���� �ֱٿ� �Է¹��� ������ȣ�� open_symbol�� ����

				if(symbol == ')' && open_symbol != '('){ //��ȣ�� '()'�� �ƴҶ�
					error_num=1; //error��ȣ�� 1
					error_line = line_num; } //error�� �߻��� line�� ���� ������ line
				else if(symbol == '}' && open_symbol != '{'){ //��ȣ�� '{}'�� �ƴҶ�
					error_num=2; //error��ȣ�� 2
					error_line = line_num; } //error�� �߻��� line�� ���� ������ line
				else if(symbol == ']' && open_symbol != '['){ //��ȣ�� '[]'�� �ƴҶ�
					error_num=3; //error��ȣ�� 3
					error_line = line_num; } //error�� �߻��� line�� ���� ������ line

				balanced = ((open_symbol == '(' && symbol == ')') || (open_symbol == '{' && symbol == '}') || (open_symbol == '[' && symbol == ']'));
			} //�뷱���� �ǹٸ� ��ȣ���� �Էµ��� ��� true.
			l.pop(); //���� ��ȣ�� ���ͼ� ������ȣ�� pop�ǹǷ� ���° �ٿ��־������� ���� ������ pop
		}
	}

	if(!balanced) { //balanced = false �϶�
		switch(error_num) { //error_num�� ���� switch��
			case 1: cout << "error 1 at line " << error_line << endl;
				break; //error_num = 1�� ���
			case 2: cout << "error 2 at line " << error_line << endl;
				break; //error_num = 2�� ���
			case 3: cout << "error 3 at line " << error_line << endl;
				break; //error_num = 3�� ���
		}
	}
	else if(!s.is_empty()) { //����s�� ������� ���� ���
		close_symbol = s.pop(); //���� ���� symbol�� ���� close_symbol�� ����
		switch(close_symbol) { //clse_symbol�� ���� switch��
			case '(': cout << "error 4 at line " << l.pop() << endl;
				break; //'('��ȣ�� ������ ��� error��ȣ�� 4
			case '{': cout << "error 5 at line " << l.pop() << endl;
				break; //'{'��ȣ�� ������ ��� error��ȣ�� 5
			case '[': cout << "error 6 at line " << l.pop() << endl;
				break; //'['��ȣ�� ������ ��� error��ȣ�� 6
			}
	}
	else //balanced=true �� ��
	{
		cout << "1" << endl; //1���
	}

	return 0; //���α׷� ����
}
