<<<<<<< HEAD
/*
 * main.cpp
 *
 *  Created on: 2019. 5. 3.
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
	~List();
	void insert_front(int item);
	void print_list() const;
	void remove(int k);
	//삭제하려는 노드 순서 k를 입력 받아 k번째 노드를 삭제
	//1-2-3-4-5 일 때 3번째 노드인 3 노드 삭제
	int get_size() const;
	void recur_remove(NodeType* &ptr, int k);
	int recur_size(NodeType* ptr) const;
};

List::List(){
	head = NULL;
}

List::~List(){
	NodeType* tmp;
	while(head != NULL){
		tmp = head;
		head = head->next;
		delete tmp;
	}
}

void List::insert_front(int item) {
	NodeType* tmp = new NodeType;
	tmp->value = item;
	tmp->next = head;
	head = tmp;
}

void List::print_list() const {
	NodeType* tmp = head;
	while (tmp != NULL) {
		cout << tmp->value << endl;
		tmp = tmp->next;
	}
}

void List::remove(int k) {
	recur_remove(head, k);
}

void List::recur_remove(NodeType* &ptr, int k) {
	if(k ==1) {
		NodeType* tmp;
		tmp = ptr;
		ptr = ptr->next;
		delete tmp;
	}
	else {
		recur_remove(ptr->next, k-1);
	}
}

int List::get_size() const {
	recur_size(head);
}

int List::recur_size(NodeType *ptr) const {
	if(ptr == NULL)
		return 0;
	else
		return recur_size(ptr->next) + 1;
}



=======
/*
 * main.cpp
 *
 *  Created on: 2019. 5. 3.
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
	~List();
	void insert_front(int item);
	void print_list() const;
	void remove(int k);
	//삭제하려는 노드 순서 k를 입력 받아 k번째 노드를 삭제
	//1-2-3-4-5 일 때 3번째 노드인 3 노드 삭제
	int get_size() const;
	void recur_remove(NodeType* &ptr, int k);
	int recur_size(NodeType* ptr) const;
};

List::List(){
	head = NULL;
}

List::~List(){
	NodeType* tmp;
	while(head != NULL){
		tmp = head;
		head = head->next;
		delete tmp;
	}
}

void List::insert_front(int item) {
	NodeType* tmp = new NodeType;
	tmp->value = item;
	tmp->next = head;
	head = tmp;
}

void List::print_list() const {
	NodeType* tmp = head;
	while (tmp != NULL) {
		cout << tmp->value << endl;
		tmp = tmp->next;
	}
}

void List::remove(int k) {
	recur_remove(head, k);
}

void List::recur_remove(NodeType* &ptr, int k) {
	if(k ==1) {
		NodeType* tmp;
		tmp = ptr;
		ptr = ptr->next;
		delete tmp;
	}
	else {
		recur_remove(ptr->next, k-1);
	}
}

int List::get_size() const {
	recur_size(head);
}

int List::recur_size(NodeType *ptr) const {
	if(ptr == NULL)
		return 0;
	else
		return recur_size(ptr->next) + 1;
}



>>>>>>> 703c4cd30b5df7fc525d0c1e7238cdd23ea21d06
