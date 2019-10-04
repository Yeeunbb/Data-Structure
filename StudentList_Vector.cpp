<<<<<<< HEAD

#include <iostream>

using namespace std;
struct Node{
	Student data;
	Node* next;
};

class Student{
	string id;
	string name;
	string dept;

public:
	void set(string id, string name, string dept){
		this->id = id;
		this->name = name;
		this->dept = dept;
	}

	string get_id(){
		return id;
	}

	string get_name(){
		return name;
	}

	string get_dept(){
		return dept;
	}
};

class StudentList{
	vector<Student> student_arr;
public:

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

	while(cin>>command){
		if(command == "Q")
			break;
		if(command == "N"){
			cin >> id >> name >> dept;
			st.set(id, name, dept);
			if(st_list.search(st.get_id(),st))
				cout << "error1" << endl;
			else
				st_list.sign_up(st);
		}
		else if(command == "W"){
			cin >> id;
			if(!st_list.withdraw(id)){
				cout << "error2" << endl;
			}
		}
		else if(command == "R"){
			cin >> id;
			if(st_list.search(id, st)){
				cout << st.get_id() << " " << st.get_name() << " " << st.get_dept() << endl;
			}
			else {
				cout << "error2" << endl;
			}
		}
		else if(command == "C"){
			cin >> id >> name >> dept;

			st.set(id, name, dept);
			if(!st_list.change_info(st)){
				cout << "error2" << endl;
			}
		}
		else if(command == "P"){
			st_list.print_all();
		}
		else if(command == "S"){
			cout << st_list.size() << endl;
		}
	}
	return 0;
}


int StudentList::size() {
	return student_arr.size();
}

void StudentList::sign_up(Student st) {
	student_arr.push_back(st);
	//student_arr[student_arr.size()] = st;
}

bool StudentList::search(string id, Student &st) {
	if(!student_arr.empty()){
		for(int i=0; i<student_arr.size(); i++){
			if(student_arr[i].get_id() == id){
				st=student_arr[i];
				return true;
			}
		}
	}
	return false;
}


bool StudentList::withdraw(string id) {
	int index = -1;
	if(student_arr.empty())
		return false;
	else{
		for(int i=0; i<student_arr.size(); i++){
			if(student_arr[i].get_id() == id){
				index = i;
			}
		}
		if(index == -1)
			return false;
		else{
			student_arr[index] = student_arr.back();
			student_arr.pop_back();
			return true;
		}
	}
}

bool StudentList::change_info(Student st) {
	for(int i=0; i<student_arr.size(); i++){
		if(student_arr[i].get_id() == st.get_id()){
			student_arr[i] = st;
			return true;
		}
	}
	return false;
}

void StudentList::print_all(){
	for(int i=0; i<student_arr.size(); i++){
		cout << student_arr[i].get_id() << " " << student_arr[i].get_name() << " " << student_arr[i].get_dept() << endl;
	}
}

=======

#include <iostream>

using namespace std;
struct Node{
	Student data;
	Node* next;
};

class Student{
	string id;
	string name;
	string dept;

public:
	void set(string id, string name, string dept){
		this->id = id;
		this->name = name;
		this->dept = dept;
	}

	string get_id(){
		return id;
	}

	string get_name(){
		return name;
	}

	string get_dept(){
		return dept;
	}
};

class StudentList{
	vector<Student> student_arr;
public:

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

	while(cin>>command){
		if(command == "Q")
			break;
		if(command == "N"){
			cin >> id >> name >> dept;
			st.set(id, name, dept);
			if(st_list.search(st.get_id(),st))
				cout << "error1" << endl;
			else
				st_list.sign_up(st);
		}
		else if(command == "W"){
			cin >> id;
			if(!st_list.withdraw(id)){
				cout << "error2" << endl;
			}
		}
		else if(command == "R"){
			cin >> id;
			if(st_list.search(id, st)){
				cout << st.get_id() << " " << st.get_name() << " " << st.get_dept() << endl;
			}
			else {
				cout << "error2" << endl;
			}
		}
		else if(command == "C"){
			cin >> id >> name >> dept;

			st.set(id, name, dept);
			if(!st_list.change_info(st)){
				cout << "error2" << endl;
			}
		}
		else if(command == "P"){
			st_list.print_all();
		}
		else if(command == "S"){
			cout << st_list.size() << endl;
		}
	}
	return 0;
}


int StudentList::size() {
	return student_arr.size();
}

void StudentList::sign_up(Student st) {
	student_arr.push_back(st);
	//student_arr[student_arr.size()] = st;
}

bool StudentList::search(string id, Student &st) {
	if(!student_arr.empty()){
		for(int i=0; i<student_arr.size(); i++){
			if(student_arr[i].get_id() == id){
				st=student_arr[i];
				return true;
			}
		}
	}
	return false;
}


bool StudentList::withdraw(string id) {
	int index = -1;
	if(student_arr.empty())
		return false;
	else{
		for(int i=0; i<student_arr.size(); i++){
			if(student_arr[i].get_id() == id){
				index = i;
			}
		}
		if(index == -1)
			return false;
		else{
			student_arr[index] = student_arr.back();
			student_arr.pop_back();
			return true;
		}
	}
}

bool StudentList::change_info(Student st) {
	for(int i=0; i<student_arr.size(); i++){
		if(student_arr[i].get_id() == st.get_id()){
			student_arr[i] = st;
			return true;
		}
	}
	return false;
}

void StudentList::print_all(){
	for(int i=0; i<student_arr.size(); i++){
		cout << student_arr[i].get_id() << " " << student_arr[i].get_name() << " " << student_arr[i].get_dept() << endl;
	}
}

>>>>>>> 703c4cd30b5df7fc525d0c1e7238cdd23ea21d06
