#include <iostream> //C++�������
#include <string> //���ڿ� �������
#include <algorithm> //sort�Լ� ����� ����

using namespace std;

class Student{ //�л��� ���� Ŭ����
	string id; //�й�
	string name; //�̸�
	string dept; //�а�

public:
	void set(string id, string name, string dept){ //�����Է¹޴��Լ�
		this->id = id; //�й�
		this->name = name; //�̸�
		this->dept = dept; //�а�
	}

	string get_id(){ //private���� id�� �ҷ����� �Լ�
		return id;
	}

	string get_name(){ //private���� name�� �ҷ����� �Լ�
		return name;
	}

	string get_dept(){ //private���� dept�� �ҷ����� �Լ�
		return dept;
	}
};

struct Node{ //���Ḯ��Ʈ�� ����� Node����ü
	Student data; //���� ������ ����
	Node* next; //���� ����� ��ġ�� ����
};

class StudentList{ //������ ���� ���� ����Ʈ
	Node* head; //����Ʈ�� ���
	int length; //����Ʈ ����
public:
	StudentList(); //������
	~StudentList(); //�Ҹ���
	int size(); //����Ʈ���̹�ȯ�Լ�
	void sign_up(Student st); //�Է¹����л�������Ʈ������
	bool search(string id, Student &st); //����Ʈ�����л���ã���Լ�
	bool withdraw(string id); //����Ʈ�����л���������Լ�
	bool change_info(Student st); //����Ʈ�����л��������������ϴ��Լ�
	void print_all(); //�� �����л��� �й������� ���
};

bool recur_search(Node* ptr, string id, Student &st); //search�Լ��� ����Լ� �Լ�����
bool recur_changeinfo(Node* ptr, Student st); //change_info�Լ��� ����Լ� �Լ�����
bool compare(Student &a, Student &b); //sort�Լ����� ����ϱ� ���� ������ �������Լ� �Լ�����

int main(){ //�����Լ�
	StudentList st_list; //�л�����Ʈ
	Student st; //�л�����
	string id; //�й�
	string name; //�̸�
	string dept; //�а�
	string command; //������ɾ��Է�

	while(cin >> command){ //break������ ������ ��ɾ ����ؼ� �Է¹���
		if(command == "Q")//������
			break;
		if(command == "N"){ //������û
			cin >> id >> name >> dept; //�����Է�
			if(st_list.search(id,st)) //�̹� ������û ���ִ� ���
				cout<< "error1" <<endl; //error���
			else{ //������û�� �ȵ��ִ� ���
				st.set(id, name, dept); //�л�����zip
				st_list.sign_up(st); //����Ʈ�� ����
			}
		}
		else if(command == "W"){ //�������
			cin >> id; //�й��Է�
			if(!st_list.withdraw(id)){ //�ش��л� ����
				cout << "error2" << endl; //�л������� ���°�� error���
			}
		}
		else if(command == "R"){ //�����л� ���� ���
			cin >> id; //�й��Է�
			if(st_list.search(id,st)){ //�ش��л� ã��
				cout << st.get_id() << " " << st.get_name() << " " << st.get_dept() << endl;
			} //�ش��л� ���� ���
			else{ //�л��� ���� ���
				cout << "error2" << endl; //error ���
			}
		}
		else if(command == "C"){ //�����л� ���� ����
			cin >> id >> name >> dept; //���ο����� �Է�
			st.set(id, name, dept); //�л�������zip
			if(!st_list.change_info(st)){ //�ش��л���������
				cout << "error2" << endl; //����Ʈ�� �л��̾��°�� error���
			}
		}
		else if(command == "P"){ //���� �л����� �й�������� ���
			st_list.print_all();
		}
		else if(command == "S"){ //�����л� ���� ���
			cout << st_list.size() << endl;
		}
	}
	return 0;
}

StudentList::StudentList() { //������
	length = 0; //���� �ʱ�ȭ
	head = NULL; //��� �ʱ�ȭ
}

StudentList::~StudentList() { //�Ҹ���
	Node* tmp = NULL; //�ӽó�����
	while (head!= NULL) {
		tmp = head;
		head = head->next;
		delete tmp; //��� �ϳ��� ����
	}
}

int StudentList::size() { //����Ʈ���̹�ȯ
	return length; //length = ����Ʈ�� ����
}

void StudentList::sign_up(Student st) { //������û�� �л� ����
	Node* location = new Node; //���ο� ���
	location->data = st; //�Է¹��� �л��� ����
	location->next = head; //��峢�� ����
	head = location; //��庯��
	length++; //���� ����
}

bool StudentList::search(string id, Student &st) { //�л�ã���Լ�
	return recur_search(head, id, st); //����Լ�ȣ��
}

bool recur_search(Node* ptr, string id, Student &st) {//search�� ����Լ�
	if (ptr==NULL) //�ش��л��� ���� ���
		return false; //false��ȯ
	else{
		if (ptr->data.get_id() == id) { //�ش��л��� ã�� ���
			st = ptr->data; //�̸�,�й�,�а� ���� st�� ����
			return true; //true��ȯ
		}
		else //�ش��л��� ã����
			return recur_search(ptr->next, id, st); //��ʹٽ�ȣ��
	}
}

bool StudentList::withdraw(string id) { //�л�������Լ�
	if(head == NULL) //����Ʈ�� �������
		return false; //false��ȯ

	else if(head->data.get_id() == id) { //ù��°�л��� �ش����϶�
		Node* tmp = head; //�������
		head = head->next; //head�̵�
		delete tmp; //�ش��л� ����
		length--; //����Ʈ ��ü���� ����
		return true; //true ��ȯ
	}
	else{ //�� ���� �л��� �ش����϶�
		Node* location = head; //���ο� ���
		while(location->next != NULL){ //�ι�°�л����� ���л����� ���캽
			if(location->next->data.get_id() == id){ //�ش��л��� ã�´ٸ�
				Node* tmp = location->next; //���� ����
				location->next = tmp->next; //��峢�� �յ� ����
				delete tmp; //�ش��л� ����
				length--; //����Ʈ ��ü ���� ����
				return true; //true ��ȯ
			}
			location= location->next; //�����л����� ���캽
		}
		return false; //�ش��л��� ���°�� false��ȯ
	}
}

bool StudentList::change_info(Student st) { //�л���������
	return recur_changeinfo(head, st); //�������� ����Լ�ȣ��
}

bool recur_changeinfo(Node* ptr, Student st){ //change_info�� ����Լ�
	if (ptr==NULL) //�ش��л��� ���� ���
		return false; //false��ȯ
	else{ //������� ������
		if (ptr->data.get_id() == st.get_id()) { //�ش��л��� ã�� ���
			ptr->data = st; //�����Է¹��� �л��� ������ ������Ʈ
			return true; //true��ȯ
		}
		else //�л��� ������ã�����
			return recur_changeinfo(ptr->next, st); //����Լ� �ٽ�ȣ��
	}
}

bool compare(Student &a, Student &b) { //�л����� �й� ���Լ�
	return a.get_id() < b.get_id(); //�й������� ����
}
void StudentList::print_all(){ //�й������� �л���θ� ����ϴ� �Լ�
	Node* fin = head; //���ο� ���
	Student* arr = new Student [length]; //�л����� ������ �迭
	for(int i=0; i<length; i++) { //�ݺ���
		arr[i]=fin->data; //�л������� ���� �迭�� ����
		fin = fin->next; //�����л�
	}

	sort(arr, arr+length, compare); //�л����� �й������� ��������

	for(int i=0; i<length; i++) { //��� �л����� ���� ���
		cout<<arr[i].get_id()<<" "<<arr[i].get_name()<<" "<<arr[i].get_dept()<<endl;
	}

	delete[] arr; //�����Ҵ� ���� �迭 ��ȯ
}
