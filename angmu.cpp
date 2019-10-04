#include <cstdlib> //����Լ�. C�� stdio.h�� ���
#include <iostream> //C++�� ����Լ�

using namespace std;


const int MAX_STACK_SIZE = 100; //�迭�� �ִ�ũ�� 100
typedef int ItemType; //int�� �ڷ���

class Stack{ //stack Ŭ����
	int top; //������ ���� ��ġ
	ItemType data[MAX_STACK_SIZE]; //ũ�⸦ 100���� ������ int�� �迭

public:
	Stack(); //������
	~Stack(); //�Ҹ���
	bool is_empty(); //stack�� ����ִ��� Ȯ��
	bool is_full(); //stack�� ���ִ��� Ȯ��
	void push(ItemType item); //stack�� item�� ����
	ItemType pop(); //���� �ֱٿ� ���� �� ����
};

Stack::Stack(){ //������
	top = -1; //�ʱ� �����Ͱ� ��ġ�� -1. �迭�� �ε����� 0���� �����ϱ� ����
}

Stack::~Stack(){} //�Ҹ���

bool Stack::is_empty(){ //stack�� ����ִ��� Ȯ��
	return top == -1; //�����Ͱ��� ��ġ�� -1 = ������ �������. true ��ȯ
}

bool Stack::is_full(){ //stack�� �������ִ��� Ȯ��
	return top==MAX_STACK_SIZE-1; //�����Ͱ��� ��ġ�� �迭�ε��� -1=�迭�� ��������. ture ��ȯ
}

void Stack::push(ItemType item){ //stack��  item�� ����
	if(is_full()){ //stack�� �� ���ִ� ���
		cout << "���� ��ȭ ����" << endl;
		exit(1); //�������� ����� ����
	}
	else //stack�� ������ �ִ� ���
		data[++top] = item; //�����Ͱ� ��ĭ ������Ų�� �� ����
}

ItemType Stack::pop(){ //���� �ֱٿ� ���� ������ ����
	if(is_empty()){ //������ ����ִ� ���
		cout << "���� ������� ����" << endl;
		exit(1); //�������� ����� ����
	}
	else{ //������ ������� ���� ���
		ItemType item = data[top]; //item�� �ֱٿ� ���Դ� ������ ��
		top--; //�����Ͱ� ��ĭ ����
		return item; //�ֱٿ� ���Դ� �� ��ȯ
		//return data[top--]; ->�̷��� ���ٷ� �� �� ����
	}
}

int main(){ //�����Լ�
	Stack s; //��ȣ�� ������ ���� s

	bool balanced = true; //�ʱ� balanced���� true
	char symbol; //�Է¹��� ������ ������ ����
	char open_symbol; //���� ��ȣ�� �������� ���ÿ� �ִ� ������ȣ�� ������ ����

	while(cin.get(symbol) && balanced) { //cin.get ��  �� ���ھ� �޾ƿ��� ��. ����� ctrl+z
		if(symbol == '(' || symbol == '{' || symbol == '[') //���� ��ȣ�� ���ö�
			s.push(symbol); //���ÿ� ����
		else if(symbol == ')' || symbol == '}' || symbol == ']'){ //������ȣ�� ���ö�
			if(s.is_empty()){ //������ ����ִ� ���
				balanced = false; //while�� ����
			}
			else{ //������ ������� ���� ���
				open_symbol = s.pop(); //�ֱٿ� ����� ������ȣ pop
				balanced = ((open_symbol == '(' && symbol == ')') || (open_symbol == '{' && symbol == '}') || (open_symbol == '[' && symbol == ']'));
			} //��ȣ�� �˻�
		}
	}

	if(!balanced) //balanced = false�϶�
		cout << "-1" << endl; //-1���
	else if(s.is_empty() && balanced) //stack�� ����ְ� balanced = ture�϶�
		cout << "1" << endl; //1 ���
	else //������ ������� ������
		cout << "-1" << endl; //-1 ���

	return 0; //���α׷�����
}
