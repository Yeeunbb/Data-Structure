#include <iostream>
#include <string>

using namespace std;

class Student{ //�л������� ������ class
	string id;
	string name;
	string dept;

public:
	void set(string id, string name, string dept){ //������ ������ set�Լ�
		this->id = id; //�й�
		this->name = name; //�̸�
		this->dept = dept; //�а�
	}

	string get_id(){ //�й��� ��ȯ
		return id;
	}

	string get_name(){ //�̸��� ��ȯ
		return name;
	}

	string get_dept(){ //�а��� ��ȯ
		return dept;
	}
};

struct TreeNode{ //BST ���
	Student data; //value ��
	TreeNode* left_child; //�ڱ⺸�� ���� ���� ���ö� ������ �ڽĳ��
	TreeNode* right_child; //�ڱ⺸�� ū ���� ���� �� ������ �ڽ� ���
};

class StudentList{ //������û�� ������ Ŭ����
	TreeNode* root; //BST�� ���.��

public:
	StudentList(); //������
	~StudentList(); //�Ҹ���
	void sign_up(Student st); //�����Լ�
	void print_all(); //�й������� ���
	int size(); //������ �� �ο�
	bool search(string id, Student &st); //�����ߴ��� Ȯ��
	bool withdraw(string id); //�����Լ�
	bool change_info(Student st); //�������� �Լ�
};

bool recur_withdraw(TreeNode* &tree, string id); //�����Լ� ����̿�
bool recur_change(TreeNode* &tree, Student st); //���������Լ� ����̿�
int recur_size(TreeNode* tree); //���л��� ����̿��ؼ� ����
void recur_remove(TreeNode* tree); //�Ҹ��ڿ� �� remove����̿�

using namespace std;

int main(){ //�����Լ�
	StudentList st_list; //�л�����Ʈ
	Student st; //�л������Է¹���
	string id;
	string name;
	string dept;
	string command; //��ɾ�

	while(cin>>command){
		if(command == "Q")
			break; //Q�� �Է¹����� ���α׷� ����
		if(command == "N"){ //������û. �ݺ��̿�.
			cin >> id >> name >> dept;
			st.set(id, name, dept); //�л����� zip
			if(st_list.search(st.get_id(),st)) //�̹� �ִ� �������� Ȯ��
				cout << "error1" << endl; //�ִٸ� error1
			else
				st_list.sign_up(st); //���ٸ�, ����Ʈ�� �л� �߰�
		}
		else if(command == "W"){ //�������. ����̿�
			cin >> id;
			if(!st_list.withdraw(id)){ //�л������� �ִ��� ã��, �ִٸ� ����, ���ٸ�
				cout << "error2" << endl; //error2 ���

			}
		}
		else if(command == "R"){ //�����л� �������
			cin >> id;
			if(st_list.search(id, st)){ //id�� �л��� ã�� st�� ���� �־���
				cout << st.get_id() << " " << st.get_name() << " " << st.get_dept() << endl;
			} //���� ���
			else { //�л������� ���ٸ�
				cout << "error2" << endl; //error2���
			}
		}
		else if(command == "C"){ //�����л� ��������. ����̿�
			cin >> id >> name >> dept;

			st.set(id, name, dept);
			if(!st_list.change_info(st)){ //�л��� �ִٸ�, ��������, ���ٸ�
				cout << "error2" << endl; //error2 ���
			}
		}
		else if(command == "P"){ //�����л� �й��� ���
			st_list.print_all(); //inorder traversal
		}
		else if(command == "S"){ //�����л����� ���
			cout << st_list.size() << endl;
		}
	}
	return 0;
}

StudentList::StudentList(){ //������
	root = NULL; //�ʱⰪ�� NULL
}

StudentList::~StudentList(){ //�Ҹ���
	recur_remove(root); //root���� ��͸� �̿��ؼ� Ʈ����� ����
}

void recur_remove(TreeNode* tree){ //Ʈ����� ���� �Լ�
	if(tree!=NULL){ //��尡 NULL�϶�����
		recur_remove(tree->left_child); //���� �ڽĳ��� �̵�
		recur_remove(tree->right_child); //������ �ڽĳ��� �̵�
		delete tree; //��� ����
	}
}

int StudentList::size(){ //�� �����л� ��
	return recur_size(root); //��͸� �̿�
}

int recur_size(TreeNode* tree){ //��͸� �̿��Ͽ� �� ������ �� ���ϴ� �Լ�
	if(tree==NULL) //��尡 NULL �϶�
		return 0; //0��ȯ
	else{ //��尡 ������� �ʴٸ�
		return recur_size(tree->left_child) + recur_size(tree->right_child) + 1;
	} //���� ���� �ڽĳ�� + ������ �ڽĳ�� + �� �ڽ�
}

bool StudentList::search(string id, Student &st){ //�����ߴ��� ã�� �Լ�
	TreeNode* location = root; //��ġ�� ������ TreeNode location
	while(location != NULL) { //location�� NULL�� �� ���� �ݺ�
		if(location->data.get_id() == id) { //ã�ƾ� �ϴ� �л��� ã������
			st = location->data; //st�� �л� ���� ��� ����
			return true; //true ��ȯ
		}
		else if(location->data.get_id() < id){ //������ id�� ã�ƾ��� id���� ������
			location = location->right_child; //������ �ڽĳ��� �̵�
		}
		else{//������ id�� ã�ƾ��� id���� Ŭ ��
			location = location->left_child; //���� �ڽĳ��� �̵�
		}
	}
	return false; //ã�ƾ��� �л��� �����Ƿ� false ��ȯ
}

bool StudentList::withdraw(string id){ //�л����� ���� �Լ�
	return recur_withdraw(root, id); //��͸� �̿�
}

bool recur_withdraw(TreeNode* &tree, string id){ //��͸� �̿��� ���� �Լ�
	if(tree == NULL){ //tree �� NULL �϶�
		return false; //false ��ȯ
	}
	else{ //tree�� NULL�� �ƴ� ��
		if(tree->data.get_id() == id){ //������ �л��� ã���� ��
			TreeNode* temp; //�ӽó�� temp
			if(tree->left_child==NULL&&tree->right_child!=NULL){ //Ʈ���� ������ �ڽĳ�带 ���� ��
				temp = tree; //temp�� tree����
				tree = tree->right_child; //tree�� ������ �ڽĳ��� �̵�
				delete temp; //temp ����
				return true; //true ��ȯ
			}
			else if(tree->right_child==NULL&&tree->left_child!=NULL){ //Ʈ���� ���� �ڽ� ��带 ���� ��
				temp = tree; //temp�� tree����
				tree = tree->left_child; //tree�� ���� �ڽĳ��� �̵�
				delete temp; //temp ����
				return true; //true ��ȯ
			}
			else if(tree->left_child!=NULL&&tree->right_child!=NULL){ //Ʈ���� ����,������ �ڽĳ�带 �� �� ���� ��
				temp = tree->right_child; //temp�� tree�� ������ �ڽ�
				while(temp->left_child != NULL) //temp�� ���� �ڽĳ�尡 NULL�϶�����
					temp = temp->left_child; //temp �������� �̵�
				tree->data = temp->data; //tree�� temp �� ����. == ������ ��� ��ġ���� ���� ���� �� ã�Ƽ� ����
				recur_withdraw(tree->right_child, temp->data.get_id()); //temp ����
				return true; //true ��ȯ
			}
			else{ //������ ��尡 �ܸ������ ���
				temp = tree; //temp �� tree ����
				tree = NULL; //tree�� NULL�� �ʱ�ȭ
				delete temp; //temp ����
				return true; //true ��ȯ
			}
		}
		else if(tree->data.get_id() < id){//������ �л��� ���̵� ���� �����̵𺸴� Ŭ ��
			return recur_withdraw(tree->right_child, id); //������ �ڽĳ��� �Լ� ��ȣ��
		}
		else{ //������ �л��� ���̵� ���� ����� ���̵𺸴� ���� ��
			return recur_withdraw(tree->left_child, id); //���� �ڽĳ��� �Լ� ��ȣ��
		}
	}
}

bool StudentList::change_info(Student st){ //�л����� �����Լ�
	return recur_change(root, st); //��͸� �̿��Ͽ� �л����� ����
}

bool recur_change(TreeNode* &tree, Student st){ //��͸� �̿��� ���� ����
	if(tree == NULL){ //tree �� NULL �϶�. == �л������� �������� ���� ��
		return false; //false��ȯ
	}
	else if(tree->data.get_id()<st.get_id()){ //�л� id�� ������ id���� Ŭ ��
		return recur_change(tree->right_child, st); //������ �ڽĳ��� �Լ� ��ȣ��
	}
	else if(tree->data.get_id() == st.get_id()){ //������ �л��� ã���� ��
		tree->data = st; //tree�� data�� �����Է¹��� ������ ����
		return true; //true ��ȯ
	}
	else{//�л� id�� ������ id���� ���� ��
		return recur_change(tree->left_child, st); //���� �ڽĳ��� �Լ� ��ȣ��
	}
}

void StudentList::sign_up(Student st){//�л��� ����Ʈ�� �����ϴ� �Լ�
    if(root == NULL){ //root�� NULL�϶�
        root = new TreeNode; //�����Ҵ�
        root->data = st; //�Է¹��� ���� ����
        root->left_child = root->right_child = NULL; //�� �ڽĳ��� NULL�ʱ�ȭ
    }
    else{ //������ ����� �л��� ���� �� ��
        TreeNode* tree = root; //�ӽ� tree��� ����
        while(tree!=NULL){ //tree��尡 NULL�� ������
            if(tree->data.get_id()< st.get_id()){ //���� ���id�� ���� �Է¹��� id���� ���� ��
                if(tree->right_child!=NULL) //���� ����� ������ �ڽĳ�尡 ������ ���
                    tree = tree->right_child; //���� ��带 ������ �ڽĳ��� �̵�
                else{ //���� ����� ������ �ڽĳ�尡 ������� ��
                    tree->right_child = new TreeNode; //�����Ҵ�
                    tree->right_child->data = st; //�Է¹��� ���� ����
                    tree->right_child->left_child = NULL; //�� ����� �ڽĳ��� NULL �ʱ�ȭ
                    tree->right_child->right_child = NULL;
                    break; //while�� ����
                }
            }
            else{ //���� ��� id�� ���� �Է¹��� id���� Ŭ ��
                if(tree->left_child!=NULL) //���� ����� ���� �ڽĳ�尡 ������ ���
                    tree = tree->left_child; //���� ��带 ���� �ڽĳ��� �̵�
                else{ //���� ����� ���� �ڽĳ�尡 ���������
                    tree->left_child = new TreeNode; //�����Ҵ�
                    tree->left_child->data = st; //�Է¹��� ���� ����
                    tree->left_child->left_child = NULL; //�� ����� �ڽĳ��� NULL �ʱ�ȭ
                    tree->left_child->right_child = NULL;
                    break; //while�� ����
                }
            }
        }
    }
}

void recur_print(TreeNode* tree){//��͸� �̿��� inorder traversal
	if(tree != NULL){ //tree�� NULL�� �ƴ� ��
		recur_print(tree->left_child); //���� �ڽĳ�� ȣ��
		cout << tree->data.get_id() << " " << tree->data.get_name()
				<< " " << tree->data.get_dept() << endl; //���� ���
		recur_print(tree->right_child); //������ �ڽĳ�� ȣ��
	}
}

void StudentList::print_all(){ //inorder traversal
	return recur_print(root); //����̿�
}
