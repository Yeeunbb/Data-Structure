#include "StudentList.h"
#include <iostream>

using namespace std;

struct Node{
	Student data;
	Node* next;
};

class StudentList{
	Node* head;
	int length;
public:
	StudentList();
	~StudentList();
	int size();
	void sign_up(Student st);
	bool search(string id, Student &st);
	bool withdraw(string id);
	bool change_info(Student st);
	void print_all();
};

int main(){
	StudentList st_list;
	Student st;
	string id;
	string name;
	string dept;
	string command;

	while(cin >> command){
		if(command == "exit")
			break;
		if(command == "수강신청"){
			cin >> id >> name >> dept;
			st.set(id, name, dept);
			st_list.sign_up(st);
		}
		else if(command == "수강취소"){
			cin >> id;
			if(!st_list.withdraw(id)){
				cout << "Id Not Found" << endl;
			}
		}
		else if(command == "검색"){
			cin >> id;
			if(st_list.search(id,st)){
				cout << st.get_id() << " " << st.get_name() << " " << st.get_dept() << endl;
			}
			else{
				cout << "Id Not Found" << endl;
			}
		}
		else if(command == "정보변경"){
			cin >> id >> name >> dept;

			st.set(id, name, dept);
			if(!st_list.change_info(st)){
				cout << "Id Not Found" << endl;
			}
		}
		else if(command == "수강자출력"){
			st_list.print_all();
		}
		else if(command == "size"){
			cout << st_list.size() << endl;
		}
	}
	return 0;
}

bool recur_search(Node* ptr, string id, Student &st);
void recur_print(Node* ptr);

StudentList::StudentList() {
	/*max_size = 100;
	student_arr = new Student[max_size];
	n = 0;*/
	length = 0;
	head = NULL;
}

StudentList::~StudentList() {
	Node* tmp = NULL;
	while (head!= NULL) {
		tmp = head;
		head = head->next;
		delete tmp;
	}
}

int StudentList::size() {
	return length;
}

void StudentList::sign_up(Student st) {
	/*if (n!=max_size) {
		student_arr[n] = st;
		n++;
	}*/
	Node* location = new Node;
	location->data = st;
	location->next = head;
	head = location;
	length++;
}

/*bool StudentList::search(string id, Student &st) {
	Node* location = head;
	while(location != NULL) {
		if(location->data.get_id() == id) {
			st = location->data;
			return true;
		}
		location = location->next;
	}
	return false;
}*/

bool StudentList::search(string id, Student &st) {
	return recur_search(head, id, st);
}

bool recur_search(Node* ptr, string id, Student &st) {
	if (ptr==NULL)
		return false;
	else{
		if (ptr->data.get_id() == id) {
			st = ptr->data;
			return true;
		}
		else
			return recur_search(ptr->next, id, st);
	}
}
bool StudentList::withdraw(string id) {
	if(head->data.get_id() == id) {
		Node* tmp = head;
		head = head->next;
		delete tmp;
		return true;
	}
	else{
		Node* location = head;
		while(location->next != NULL){
			if(location->next->data.get_id() == id){
				Node* tmp = location->next;
				location->next = tmp->next;
				delete tmp;
				return true;
			}
		}
		return false;
	}
}

bool StudentList::change_info(Student st) {
	Node* ptr = head;
	while(ptr!=NULL){
		if(ptr->data.get_id() == st.get_id()){
			ptr->data = st;
			return true;
		}
		ptr=ptr->next;
	}
	return false;
}

void StudentList::print_all(){
/*	Node* location = head;
	while(location != NULL){
		cout << location->data.get_id() << " " << location->data.get_name() << " " << location->data.get_dept() << endl;
		location = location->next;
	} */
	recur_print(head);
}

void recur_print(Node* ptr){
	if(ptr != NULL) {
		cout<<ptr->data.get_id() << " " << ptr->data.get_name() << " " << ptr->data.get_dept() << endl;
		recur_print(ptr->next);
	}
}