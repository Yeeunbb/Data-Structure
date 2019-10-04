#include <cstdlib> //����Լ�. C�� stdio.h�� ���
#include <iostream> //C++�� ����Լ�

using namespace std;


const int MAX_STACK_SIZE = 100; //�迭�� �ִ�ũ�� 100
typedef int ItemType; //int�� �ڷ���

struct Node //Node ����ü
{
	ItemType info; //���� ���� ����
	Node *next; //���� ��带 ������ ������
};

class Stack{ //stack Ŭ����
	Node *topPtr; //������ ž�� ����Ű�� ������

public:
	Stack(); //������
	~Stack(); //�Ҹ���
	bool is_empty() const; //stack�� ����ִ��� Ȯ��
	//bool is_full() const; //stack�� ���ִ��� Ȯ��
	void push(ItemType item); //stack�� item�� ����
	ItemType pop(); //���� �ֱٿ� ���� �� ����
};

Stack::Stack(){ //������
	topPtr = NULL; //�ʱ� ž ���� NULL
}

Stack::~Stack(){
	Node *tempPtr;// �ӽ� ���

	while(topPtr != NULL) //topPtr�� �������� �ݺ�
	{
		tempPtr = topPtr;
		topPtr = topPtr->next;
		delete tempPtr; //������ �ݳ�
	}
} //�Ҹ���

bool Stack::is_empty() const{ //stack�� ����ִ��� Ȯ��
	return topPtr == NULL; //�����Ͱ��� ��ġ�� -1 = ������ �������. true ��ȯ
}

void Stack::push(ItemType item){ //stack��  item�� ����
		Node *newNode; //���ο� ���
		newNode = new Node; //�����Ҵ�
		newNode->info = item; //�Է¹��� item�� ����
		newNode->next = topPtr; //���� ���� ����
		topPtr = newNode; //�������� ���� ���� ����
}

ItemType Stack::pop(){ //���� �ֱٿ� ���� ������ ����
	if(is_empty()){ //������ ����ִ� ���
		cout << "���� ������� ����" << endl;
		exit(1); //�������� ����� ����
	}
	else{
		ItemType item;
		Node *tempPtr;
		item = topPtr->info; //item�� ��忡 ������ִ� ����
		tempPtr = topPtr; //�ӽó�忡 ���� ��� ����
		topPtr = topPtr->next; //��� ����
		delete tempPtr; //��� ����
		return item; //�� ��ȯ
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


