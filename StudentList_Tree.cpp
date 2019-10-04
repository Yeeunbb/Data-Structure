#include "StudentList.h"
#include <iostream>

using namespace std;


struct TreeNode{
	Student data;
	TreeNode* left_child;
	TreeNode* right_child;
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
	TreeNode* root;
public:
	StudentList();
	~StudentList();
	void remove_all();
	int height();
	void sign_up(Student st);
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
			st_list.sign_up(st);
		}

		else if(command == "P"){
			st_list.print_all();
		}
		else if(command == "S"){
			cout << st_list.height() << endl;
		}
	}
	return 0;
}

int recur_height(TreeNode* tree);
void recur_insert(TreeNode* &tree, Student st);

StudentList::StudentList(){
	root = NULL;
}

StudentList::~StudentList(){
	//remove_all();
}

/*int recur_remove(TreeNode* tree){
	if(tree->left_child == NULL & tree->right_child == NULL)
		return 0;
}

void StudentList::remove_all(){
	recur_remove(root);
}*/
int StudentList::height(){
	return recur_height(root);
}

int recur_height(TreeNode* tree){
	if(tree == NULL)
		return 0;
	else{
		int h_L = recur_height(tree->left_child);
		int h_R = recur_height(tree->right_child);
		if(h_L < h_R)
			return h_R + 1;
		else
			return h_L + 1;
	}

}

void StudentList::sign_up(Student st) {
	return recur_insert(root, st);
}

void recur_insert(TreeNode* &tree, Student st) {
	if(tree == NULL){
	tree = new TreeNode;
	tree->data = st;
	tree->left_child = tree->right_child = NULL;
	}
	else{
		if(tree->data.get_id()< st.get_id()){
			recur_insert(tree->right_child, st);
		}
		else
			recur_insert(tree->left_child, st);
	}

}
void recur_print(TreeNode* tree){
	if(tree != NULL){
		recur_print(tree->left_child);
		cout << tree->data.get_id() << " " << tree->data.get_name()
				<< " " << tree->data.get_dept() << endl;
		recur_print(tree->right_child);
	}
}

void StudentList::print_all(){
	return recur_print(root);
}