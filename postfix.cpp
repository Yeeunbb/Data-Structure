#include <iostream> //����Լ�
#include <cstdlib> //����Լ�. atof �Լ����
#include <string> //����Լ�. string ��ü ���
#include <iomanip> //����Լ�. �Ҽ������

using namespace std;

const int MAX_STACK_SIZE = 100; //���� dataũ��
typedef float ItemType; //�Ǽ��� Ÿ��������

class Stack{ //stack class
	int top; //stack����Ÿ�� ��ġ
	ItemType data[MAX_STACK_SIZE]; //stack�� data�� �����ϴ� �����迭

public:
	Stack(); //������
	~Stack(); //�Ҹ���
	bool is_empty(); //������ ������� Ȯ���ϴ� �Լ�
	bool is_full(); //������ �� ���ִ��� Ȯ���ϴ� �Լ�
	void push(ItemType item); //���ÿ� ���� �Է��ϴ� �Լ�
	ItemType pop(); //���� �ֱٰ��� ��ȯ�ѵ� �����ϴ� �Լ�
};

Stack::Stack(){ //������
	top = -1; //������ �ʱ� ��ġ���� -1. �迭�� �ε��� ù��° ���� 0�̴ϱ�
}

Stack::~Stack(){} //�Ҹ���

bool Stack::is_empty(){
	return top == -1; //������ ����ִٸ� top���� -1�� ���̰� true�� ��ȯ��.
}

bool Stack::is_full(){
	return top==MAX_STACK_SIZE-1; //������ �ִ밪 ��ŭ ���ִٸ� top���� 99�� ���̰� true�� ��ȯ��.
}

void Stack::push(ItemType item){
	if(is_full()){
		//cout << "���� ��ȭ ����" << endl;
		//exit(1);
		return; //���ο��� ���������� ���� ���ֹǷ� push���� ���� ������� ��������.
	}
	else
		data[++top] = item; //������ �������� ���� ��� �Է¹��� �� item�� data�� ����.
}

ItemType Stack::pop(){
	if(is_empty()){
		//cout << "���� ������� ����" << endl;
		//exit(1);
		return 0; //���ο��� ���������� ���� ���ֹǷ� pop���� ���� ������� ��������.
	}
	else{ //������ ������� ���� ���
		ItemType item = data[top]; //���� ��ȯ�ϱ����� ���� item�� data�� top ���� ����
		top--; //top�� ����Ǿ��ִ� �� ����
		return item; //�̸� �����صξ��� top�� ��ȯ
		//return data[top--]; �̷������� ���ٷ� �� �� ����
	}
}

int main() { //�����Լ�
	string token; //�Է¹��� �����ڿ� �ǿ����ڸ� ������ ����
	Stack s; //������ ���� ������ ����

	while (cin >> token) { //break�� ������ ������ ����ؼ� token�� �Է¹���
		if(token == ";")
			break; //token�� ';'�϶� �ݺ��� ����

		else if(isdigit(token[0])) { //�Է¹��� token�� ����(���ǽǼ�)�϶�
			s.push(atof(token.c_str())); //����s�� ���ڷ� �Է¹��� token�� ���� �Ǽ��� ����
		}

		else if(token[0] == '-' && isdigit(token[1])) { //�Է¹��� token�� �����϶�
			s.push(atof(token.c_str())); //����s�� ���ڷ� �Է¹��� ������ �Ǽ������� ����
		}

		else if (token == "+") { //+ �����϶�
			if (s.is_empty()) { //�ǿ����ڰ� ���� ���
				cout << "error 1" << endl; //error1 ���
				return 0; //����
			}
			ItemType second = s.pop(); //���߿� ���� ���� second�� ����

			if (s.is_empty()) { //�ǿ����ڰ� ���� ���
				cout << "error 1" << endl; //error 1 ���
				return 0; //����
			}
			ItemType first = s.pop(); //���� �Է¹��� ���� first�� ����
			s.push(first + second); //�Է¹��� ���� ���� ���ϱ� ���갪 ����
		}

		else if( token == "-") { //- �����϶�
			if(s.is_empty()){ //�ǿ����ڰ� ���� ���
				cout <<"error 1" <<endl; //error 1 ���
				return 0; //����
			}
			ItemType second = s.pop(); //���߿� ���� ���� second�� ����

			if(s.is_empty()) { //�ǿ����ڰ� ���� ���
				cout <<"error 1" <<endl; //error 1 ���
				return 0; //����
			}
			ItemType first = s.pop(); //���� �Է¹޾Ҵ� ���� first�� ����
			s.push(first - second); //�Է¹��� �ǿ����ڵ鿡 ���� -���� ����� ����
		}

		else if(token =="*") { //* �����϶�
			if(s.is_empty()) { //�ǿ����ڰ� ���� ���
				cout << "error 1" << endl; //error 1 ���
				return 0; //����
			}
			ItemType second = s.pop(); //���߿� ���� ���� second�� ����

			if(s.is_empty()) { //�ǿ����ڰ� ���� ���
				cout << "error 1" << endl; //error 1 ���
				return 0; //����
			}
			ItemType first = s.pop(); //���� ���� �� first�� ����
			s.push(first * second); //�ǿ����ڵ鿡 ���� *���� ����� ����
		}

		else if(token == "/") { //������ ������ ��
			if(s.is_empty()) { //�ǿ����ڰ� ���� ���
				cout<< "error 1" <<endl; //error 1 ���
				return 0; //����
			}
			ItemType second = s.pop(); //���߿� ���� �� second�� ����

			if(s.is_empty()) { //�ǿ����ڰ� ���� ���
				cout << "error 1" <<endl; //error 1 ���
				return 0; //����
			}
			ItemType first = s.pop(); //���� ���� �� first�� ����
			s.push(first / second); //�ǿ����ڵ鿡 ���� ������ ���갪 ����
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

	ItemType result = s.pop(); //������ ���� ����� ����

	if(!s.is_empty()) { //�ǿ����ڿ� ���� �����ڰ� ���°��. = �ǿ����ڰ� ���� ���
		cout << "error 2" << endl; //error 2 ���
		return 0; //����
	}

	cout << fixed << setprecision(2) << result << endl; //�� ������� �Ҽ��� 2�ڸ����� ���

	return 0; //����
}



