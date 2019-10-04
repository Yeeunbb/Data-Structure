#include <iostream>

using namespace std;

template <typename ItemType>
struct Node{
	ItemType data;
	Node<ItemType>* next;
};

template <typename ItemType>
class List{
	Node<ItemType>* head;

public:
	List();
	void insert_front(ItemType i);
	void print_list();
};

template <typename ItemType>
List<ItemType>::List(){
	head = NULL;
}

template <typename ItemType>
void List<ItemType>::insert_front(ItemType i) {
	Node<ItemType>* tmp = new Node<ItemType>;
	tmp->data = i;
	tmp->next = head;
	head = tmp;
}

template <typename ItemType>
void List<ItemType>::print_list() {
	Node<ItemType>* tmp = head;
	while (tmp != NULL) {
		cout << tmp->data << endl;
		tmp = tmp->next;
	}
}

int main(){
	int count;
	float n;
	List<float> lt;

	cin >> count;

	for(int i = 0; i < count; i++){
		cin >> n;
		lt.insert_front(n);
	}

	lt.print_list();

	return 0;
}

