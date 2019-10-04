/*
 * main.cpp
 *
 *  Created on: 2019. 4. 12.
 *      Author: ykoou
 */

#include <iostream>

using namespace std;
struct NodeType {
	int value;
	NodeType* next;
};

class List{
	NodeType* head;

public:
	List();
	void insert_front(int i);
	void print_list();
};
int main() {
	int count, n;
	List l;

	cin >> count;

	for(int i=0; i<count; i++) {
		cin>>n;
		l.insert_front(n);
	}

	l.print_list();

	return 0;
}

List::List(){
	head=NULL;
}

void List::insert_front(int i) {
	NodeType* tmp = new NodeType;
	tmp->value = i;
	tmp->next = head;
	head = tmp;
}

void List::print_list() {
	NodeType* tmp = head;
	while (tmp!=NULL) {
		cout << tmp->value << endl;
		tmp = tmp->next;
	}
}
