#include <iostream>

using namespace std;

struct NodeType{
   int value;
   NodeType* next;
};

void insert_front(NodeType* &head, int i);
void print_list(NodeType* head);

int main(){
   NodeType* head;
   head = NULL;
   int n;
   cin >> n;

   for(int i=n; i>0; i--){
	   insert_front(head, i);
   }

   print_list(head);
   return 0;
}

void insert_front(NodeType* &head, int i)
{
	NodeType* tmp;
	tmp = new NodeType;
	tmp->value = i;
	tmp->next = head;
	head = tmp;
}

void print_list(NodeType* head)
{
	NodeType* tmp;
	tmp=head;
	while(tmp!=NULL){
	cout<< tmp->value<<endl;
	tmp=tmp->next;
	}
}


