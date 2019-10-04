#include <iostream>
#include <string>

using namespace std;

struct DoubleNode{
	string web_addr;
	DoubleNode* back;
	DoubleNode* next;
};

class Web_browser{
	string home_addr;
	DoubleNode* head;
	DoubleNode* current;

public:
	Web_browser();
	~Web_browser();
	void go(string addr);
	void forward();
	void backward();
	void display();
	void delete_all(DoubleNode* ptr);
};

Web_browser::Web_browser(){
	home_addr = "http://ces.hufs.ac.kr";

	head = new DoubleNode;
	head->web_addr = home_addr;
	head->next = head->back = NULL;

	current = head;
	cout << current->web_addr << endl;
}

Web_browser::~Web_browser(){
	delete_all(head);
}

void Web_browser::go(string addr) {
	delete_all(current->next);

	DoubleNode* location;
	location = new DoubleNode;
	location->web_addr = addr;
	location->next = NULL;

	location->back = current;
	current->next = location;
	current = location;

	cout << current->web_addr << endl;
}

void Web_browser::forward() {
	if(current->next != NULL)
		current = current->next;
	cout << current->web_addr << endl;
}

void Web_browser::backward() {
	if(current->back != NULL)
		current = current->back;
	cout << current->web_addr << endl;
}

void Web_browser::display() {
	DoubleNode* tmp;
	while(head != NULL){
		tmp = head;
		head = head->next;
		cout << tmp->web_addr << endl;
		delete tmp;
	}
}

void Web_browser::delete_all(DoubleNode* ptr) {
	DoubleNode* tmp;
	while(ptr != NULL) {
		tmp = ptr;
		ptr = ptr->next;
		delete tmp;
	}
}

int main() {
	Web_browser wb;
	string addr;
	string command;

	while(1) {
		cin >> command;
		if(command == "exit" )
			break;
		if (command == "go" ) {
			cin >> addr;
			wb.go(addr);
		}

		else if(command == "forward" )
			wb.forward();
		else if(command == "backward" )
			wb.backward();
	}

	wb.display();

	return 0;
}
