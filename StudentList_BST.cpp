#include <iostream>
#include <string>

using namespace std;

class Student{ //학생정보를 저장할 class
	string id;
	string name;
	string dept;

public:
	void set(string id, string name, string dept){ //정보를 저장할 set함수
		this->id = id; //학번
		this->name = name; //이름
		this->dept = dept; //학과
	}

	string get_id(){ //학번을 반환
		return id;
	}

	string get_name(){ //이름을 반환
		return name;
	}

	string get_dept(){ //학과를 반환
		return dept;
	}
};

struct TreeNode{ //BST 노드
	Student data; //value 값
	TreeNode* left_child; //자기보다 작은 값이 들어올때 저장할 자식노드
	TreeNode* right_child; //자기보다 큰 값이 들어올 때 저장할 자식 노드
};

class StudentList{ //수강신청을 관리할 클래스
	TreeNode* root; //BST를 사용.ㅇ

public:
	StudentList(); //생성자
	~StudentList(); //소멸자
	void sign_up(Student st); //삽입함수
	void print_all(); //학번순으로 출력
	int size(); //수강자 총 인원
	bool search(string id, Student &st); //수강했는지 확인
	bool withdraw(string id); //삭제함수
	bool change_info(Student st); //정보변경 함수
};

bool recur_withdraw(TreeNode* &tree, string id); //삭제함수 재귀이용
bool recur_change(TreeNode* &tree, Student st); //정보변경함수 재귀이용
int recur_size(TreeNode* tree); //총학생수 재귀이용해서 구함
void recur_remove(TreeNode* tree); //소멸자에 쓸 remove재귀이용

using namespace std;

int main(){ //메인함수
	StudentList st_list; //학생리스트
	Student st; //학생정보입력받음
	string id;
	string name;
	string dept;
	string command; //명령어

	while(cin>>command){
		if(command == "Q")
			break; //Q를 입력받으면 프로그램 종료
		if(command == "N"){ //수강신청. 반복이용.
			cin >> id >> name >> dept;
			st.set(id, name, dept); //학생정보 zip
			if(st_list.search(st.get_id(),st)) //이미 있는 정보인지 확인
				cout << "error1" << endl; //있다면 error1
			else
				st_list.sign_up(st); //없다면, 리스트에 학생 추가
		}
		else if(command == "W"){ //수강취소. 재귀이용
			cin >> id;
			if(!st_list.withdraw(id)){ //학생정보가 있는지 찾고, 있다면 삭제, 없다면
				cout << "error2" << endl; //error2 출력

			}
		}
		else if(command == "R"){ //수강학생 정보출력
			cin >> id;
			if(st_list.search(id, st)){ //id로 학생을 찾고 st에 정보 넣어줌
				cout << st.get_id() << " " << st.get_name() << " " << st.get_dept() << endl;
			} //정보 출력
			else { //학생정보가 없다면
				cout << "error2" << endl; //error2출력
			}
		}
		else if(command == "C"){ //수강학생 정보변경. 재귀이용
			cin >> id >> name >> dept;

			st.set(id, name, dept);
			if(!st_list.change_info(st)){ //학생이 있다면, 정보변경, 없다면
				cout << "error2" << endl; //error2 출력
			}
		}
		else if(command == "P"){ //수강학생 학번순 출력
			st_list.print_all(); //inorder traversal
		}
		else if(command == "S"){ //수강학생수를 출력
			cout << st_list.size() << endl;
		}
	}
	return 0;
}

StudentList::StudentList(){ //생성자
	root = NULL; //초기값은 NULL
}

StudentList::~StudentList(){ //소멸자
	recur_remove(root); //root부터 재귀를 이용해서 트리노드 삭제
}

void recur_remove(TreeNode* tree){ //트리노드 삭제 함수
	if(tree!=NULL){ //노드가 NULL일때까지
		recur_remove(tree->left_child); //왼쪽 자식노드로 이동
		recur_remove(tree->right_child); //오른쪽 자식노드로 이동
		delete tree; //노드 삭제
	}
}

int StudentList::size(){ //총 수강학생 수
	return recur_size(root); //재귀를 이용
}

int recur_size(TreeNode* tree){ //재귀를 이용하여 총 수강생 수 구하는 함수
	if(tree==NULL) //노드가 NULL 일때
		return 0; //0반환
	else{ //노드가 비어있지 않다면
		return recur_size(tree->left_child) + recur_size(tree->right_child) + 1;
	} //나의 왼쪽 자식노드 + 오른쪽 자식노드 + 나 자신
}

bool StudentList::search(string id, Student &st){ //수강했는지 찾는 함수
	TreeNode* location = root; //위치를 움직일 TreeNode location
	while(location != NULL) { //location이 NULL일 때 까지 반복
		if(location->data.get_id() == id) { //찾아야 하는 학생을 찾았을때
			st = location->data; //st에 학생 정보 모두 저장
			return true; //true 반환
		}
		else if(location->data.get_id() < id){ //현재노드 id가 찾아야할 id보다 작을때
			location = location->right_child; //오른쪽 자식노드로 이동
		}
		else{//현재노드 id가 찾아야할 id보다 클 때
			location = location->left_child; //왼쪽 자식노드로 이동
		}
	}
	return false; //찾아야할 학생이 없으므로 false 반환
}

bool StudentList::withdraw(string id){ //학생정보 삭제 함수
	return recur_withdraw(root, id); //재귀를 이용
}

bool recur_withdraw(TreeNode* &tree, string id){ //재귀를 이용한 삭제 함수
	if(tree == NULL){ //tree 가 NULL 일때
		return false; //false 반환
	}
	else{ //tree가 NULL이 아닐 때
		if(tree->data.get_id() == id){ //삭제할 학생을 찾았을 때
			TreeNode* temp; //임시노드 temp
			if(tree->left_child==NULL&&tree->right_child!=NULL){ //트리가 오른쪽 자식노드를 가질 때
				temp = tree; //temp에 tree저장
				tree = tree->right_child; //tree는 오른쪽 자식노드로 이동
				delete temp; //temp 삭제
				return true; //true 반환
			}
			else if(tree->right_child==NULL&&tree->left_child!=NULL){ //트리가 왼쪽 자식 노드를 가질 때
				temp = tree; //temp에 tree저장
				tree = tree->left_child; //tree는 왼쪽 자식노드로 이동
				delete temp; //temp 삭제
				return true; //true 반환
			}
			else if(tree->left_child!=NULL&&tree->right_child!=NULL){ //트리가 왼쪽,오른쪽 자식노드를 둘 다 가질 때
				temp = tree->right_child; //temp는 tree의 오른쪽 자식
				while(temp->left_child != NULL) //temp의 왼쪽 자식노드가 NULL일때까지
					temp = temp->left_child; //temp 왼쪽으로 이동
				tree->data = temp->data; //tree에 temp 값 저장. == 삭제할 노드 위치에서 가장 작은 값 찾아서 저장
				recur_withdraw(tree->right_child, temp->data.get_id()); //temp 삭제
				return true; //true 반환
			}
			else{ //삭제할 노드가 단말노드인 경우
				temp = tree; //temp 에 tree 저장
				tree = NULL; //tree는 NULL로 초기화
				delete temp; //temp 삭제
				return true; //true 반환
			}
		}
		else if(tree->data.get_id() < id){//삭제할 학생의 아이디가 현재 노드아이디보다 클 때
			return recur_withdraw(tree->right_child, id); //오른쪽 자식노드로 함수 재호출
		}
		else{ //삭제할 학생의 아이디가 현재 노드의 아이디보다 작을 때
			return recur_withdraw(tree->left_child, id); //왼쪽 자식노드로 함수 재호출
		}
	}
}

bool StudentList::change_info(Student st){ //학생정보 변경함수
	return recur_change(root, st); //재귀를 이용하여 학생정보 변경
}

bool recur_change(TreeNode* &tree, Student st){ //재귀를 이용한 정보 변경
	if(tree == NULL){ //tree 가 NULL 일때. == 학생정보가 존재하지 않을 때
		return false; //false반환
	}
	else if(tree->data.get_id()<st.get_id()){ //학생 id가 현재노드 id보다 클 때
		return recur_change(tree->right_child, st); //오른쪽 자식노드로 함수 재호출
	}
	else if(tree->data.get_id() == st.get_id()){ //변경할 학생을 찾았을 때
		tree->data = st; //tree의 data는 새로입력받은 정보로 변경
		return true; //true 반환
	}
	else{//학생 id가 현재노드 id보다 작을 때
		return recur_change(tree->left_child, st); //왼쪽 자식노드로 함수 재호출
	}
}

void StudentList::sign_up(Student st){//학생을 리스트에 삽입하는 함수
    if(root == NULL){ //root가 NULL일때
        root = new TreeNode; //동적할당
        root->data = st; //입력받은 정보 저장
        root->left_child = root->right_child = NULL; //양 자식노드들 NULL초기화
    }
    else{ //기존에 저장된 학생이 존재 할 때
        TreeNode* tree = root; //임시 tree노드 생성
        while(tree!=NULL){ //tree노드가 NULL일 때까지
            if(tree->data.get_id()< st.get_id()){ //현재 노드id가 새로 입력받은 id보다 작을 때
                if(tree->right_child!=NULL) //현재 노드의 오른쪽 자식노드가 존재할 경우
                    tree = tree->right_child; //현재 노드를 오른쪽 자식노드로 이동
                else{ //현재 노드의 오른쪽 자식노드가 비어있을 때
                    tree->right_child = new TreeNode; //동적할당
                    tree->right_child->data = st; //입력받은 정보 저장
                    tree->right_child->left_child = NULL; //현 노드의 자식노드들 NULL 초기화
                    tree->right_child->right_child = NULL;
                    break; //while문 종료
                }
            }
            else{ //현재 노드 id가 새로 입력받은 id보다 클 때
                if(tree->left_child!=NULL) //현재 노드의 왼쪽 자식노드가 존재할 경우
                    tree = tree->left_child; //현재 노드를 왼쪽 자식노드로 이동
                else{ //현재 노드의 왼쪽 자식노드가 비어있을때
                    tree->left_child = new TreeNode; //동적할당
                    tree->left_child->data = st; //입력받은 정보 저장
                    tree->left_child->left_child = NULL; //현 노드의 자식노드들 NULL 초기화
                    tree->left_child->right_child = NULL;
                    break; //while문 종료
                }
            }
        }
    }
}

void recur_print(TreeNode* tree){//재귀를 이용한 inorder traversal
	if(tree != NULL){ //tree가 NULL이 아닐 때
		recur_print(tree->left_child); //왼쪽 자식노드 호출
		cout << tree->data.get_id() << " " << tree->data.get_name()
				<< " " << tree->data.get_dept() << endl; //정보 출력
		recur_print(tree->right_child); //오른쪽 자식노드 호출
	}
}

void StudentList::print_all(){ //inorder traversal
	return recur_print(root); //재귀이용
}
