#include <iostream> //iostream ��� �Լ� ����
#include <string> //string ��� �Լ� ����

using namespace std;
//�� ������ �ּ��̵� ���α׷�
const int MAX_SIZE = 50;
//const �� ���. ������ �ʴ� ����.
class Web_browser //Web_browser Ŭ���� ����
{
	string addr_arr[MAX_SIZE]; //ũ�⸦ 50���� ������ �ּҸ� �����ϴ� �迭
	string history_addr[MAX_SIZE]; //ũ�⸦ 50���� ������ �湮�ߴ� ��� �ּҵ��� �����ϴ� �迭
	string home_addr="http://ces.hufs.ac.kr"; //�⺻ home �ּ� ��
	int current; //���� �������� ��Ÿ�� ����
	int history_current; //�湮�� �������� ��Ÿ�� ����
	int length; //�̵������� �ּҵ��� ����
	int history_length; //�湮�ߴ� �ּҵ��� ����

public:
	Web_browser(); //������
	void go(string addr); //������ �̵��Լ�
	void forward(); //���������� �̵��Լ�
	void backward(); //���������� �̵��Լ�
	void home(); //home���� �̵��Լ�
	void set_home(string addr); //home�ּҸ� �����ϴ� �Լ�
	void history(); //�湮�ߴ� �ּҵ��� ��� ����ϴ� �Լ�
	string get_current_addr(); //���� �ּҸ� ��ȯ�ϴ� �Լ�
	void print_addr_arr(); //�湮�ߴ� �ּҵ��� �����ִ� �Լ�
};

Web_browser::Web_browser(){ //������
	current = 0; //���� �ּҸ� ��Ÿ���� �迭�� 0
	history_current = 0; //���� �ּҸ� ��Ÿ���� �迭�� 0
	history_addr[history_current] = home_addr; //�迭�� ù��° ���� home �ּ�
	addr_arr[current] = home_addr; //�迭�� ù��° ���� home �ּ�
	length = 1; //���� �湮�� �ּ��� ������  1
	history_length = 1; //�湮�� �ּ��� ������ 1
	cout << get_current_addr() << endl; //ces.hufs.ac.kr ���
}

void Web_browser::go(string addr) { //addr_arr���� ���� �ּ� ������ �ִ� �ּҵ��� �����ϰ� ���ּ� ���� �ּҿ� addr�� �߰��ϰ� addr�� ���ּҰ� �ȴ�.
	if(current < MAX_SIZE - 1){ //�����ּҰ� addr_arr�迭�� �ִ븦 ���� ���� �� ����
		current++; //���ּ� �����ּҷ� �̵��̹Ƿ� current ������
		addr_arr[current] = addr; //���ּ� ���� �ּҴ� �Է¹��� addr
		length = current+1; //���̴� ���ּҿ� + 1 �� ��. current�� 0���� ���������Ƿ�.
	}
	history_current++; //�湮����� ������ġ�� ����
	history_addr[history_current] = addr; //addr�� ������ġ ����
	history_length++; //�湮����� �� ���� ����
}

void Web_browser::forward() { //���ּ��� ���ּҷ� �̵�
	if(current < length - 1) { //������ġ�� �̵������� ��� �ּ��� ���̺��� ���� ��
		current ++;//���� �ּ���ġ�� ���� = ���������� �̵�
	}
}

void Web_browser::backward() { //���ּ��� ���ּҷ� �̵�
	if(current != 0) { //������ġ�� �迭�� ù��°�� �ƴ� ��
		current --; //���� �ּ��� ��ġ�� ���� = ���������� �̵�
	}
}

void Web_browser::home() { //home����. go�Լ��� ����.
	if(current < MAX_SIZE - 1) { //current�� MAX_SIZE-1�����϶�
		current++; //���� �ּ� ��ġ�� ����
		addr_arr[current] = home_addr; //������ ���ּ� �� = home�ּ�
		length = current + 1; //���� �ּ� ��ġ�� + 1
	}
	history_current++; //�湮�� ������ġ�� ����
	history_addr[history_current] = home_addr; //���� ��ġ �ּ� = home
	history_length++; //�湮�� �� �ּҰ� ����
}

void Web_browser::set_home(string addr) { //Ȩ �ּҰ� ����
	home_addr = addr; //Ȩ �ּҰ� �Է¹��� addr�� ����
}

void Web_browser::history() { //�湮�� �ּ� ���
	if(history_length <= 10) { //�湮�� �ּҵ��� 10���� ���� ���� ���
		for(int i=0; i<history_length; i++) //i�� 0���� �湮�� �ּҰ�������
			cout << history_addr[i] << endl; //�湮�� �ּ� ���������� ���
	}
	else { //�湮�� �ּҵ��� 10���� �Ѵ� ���
		for(int i=history_length-10; i<history_length; i++) //�ֱ� �湮�� �ּ� 10���� ����Ѵ�
			cout << history_addr[i] << endl; //�湮�� �ּ� ���������� ���
	}
}

string Web_browser::get_current_addr() { //������ �ּڰ� ��������
	return addr_arr[current]; //���� �ּҰ��� ��ȯ�Ѵ�
}

void Web_browser::print_addr_arr() { //�湮�� �ּҵ��� ���ٷ� �����ִ� �Լ�
	for(int i=0; i<length; i++) //i�� 0���� length ����
		if(i == length - 1) //i�� ���������� �湮�� �ּ��϶�
			cout << addr_arr[i] << endl; //�ּ� ����� ����
		else
			cout << addr_arr[i] << " - "; //�ּ� ����� - �ٿ���
}

int main() //�����Լ�
{
	Web_browser wb; //Web_browser Ŭ���� wb ����
	string command; //string ��ü command. ��ɾ �Է¹�����
	string addr; //�Է¹��� �ּ� ��ü
	string EXITCMD = "exit"; //���� ��ɾ�

	while(cin >> command) { //��ɾ ����ؼ� �Է¹޴� ���ѷ���
		if(command == EXITCMD) { //���� ��ɾ� �Է¹��� ��
			break; //���ѷ��� ����
		}
		else if(command == "go") { //go ��ɾ� �Է¹��� ��
			cin >> addr; //�ּҰ� �Է�
			wb.go(addr); //go�Լ� ����
			cout << wb.get_current_addr() << endl; //���簪 ��ȯ
		}
		else if(command == "forward") { //forward��ɾ� �Է¹��� ��
			wb.forward(); //forward�Լ� ����
			cout << wb.get_current_addr() << endl; //���簪 ��ȯ
		}
		else if(command == "backward") { //backward��ɾ� �Է¹��� ��
			wb.backward(); //backward�Լ� ����
			cout << wb.get_current_addr() << endl; //���簪 ��ȯ
		}
		else if(command == "home") { //home��ɾ� �Է¹��� ��
			wb.home(); //home�Լ� ����
			cout << wb.get_current_addr() << endl; //���簪 ��ȯ
		}
		else if(command == "set_home") { //set_home ��ɾ� �Է¹��� ��
			cin >> addr; //�ּҰ� �Է�
			wb.set_home(addr); //set_home �Լ� ����
		}
		else if(command == "history") { //history��ɾ� �Է¹��� ��
			wb.history(); //history �Լ� ����
		}
	}

	return 0; //�����Լ� ����
}
