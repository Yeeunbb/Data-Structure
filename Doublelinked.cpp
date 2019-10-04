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
	int get_size() const;
};

List::List(){
	head = NULL;
}

List::~List(){
	NodeType* tmp;
	while(head != NULL) {
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
	NodeType* ptr = head;

	if( k==1 ) {
		head = head->next;
		delete ptr;
	}
	else {
		for (int i = 1; i < k-1; i++) {
			ptr = ptr->next;
		}

		NodeType* tmp = ptr->next;
		ptr->next = tmp->next;
		delete tmp;
	}
}

int List::get_size() const {
	NodeType* tmp = head;
	int count = 0;
	while (tmp != NULL) {
		count ++;
		tmp = tmp->next;
	}
	return count;
}

int main(){
	int count, n;
	List l;

	cin >> count;

	for(int i = 0; i < count; i++){
		cin >> n;
		l.insert_front(n);
	}

	cout << "size: " << l.get_size() << endl;
	l.remove(4);
	l.print_list();
	cout << "size: " << l.get_size() << endl;

	return 0;
}

