#include <iostream> //C++헤더파일
#include <string> //문자열 헤더파일
#include <algorithm> //sort함수 사용을 위해

using namespace std;

class Student{ //학생의 정보 클래스
	string id; //학번
	string name; //이름
	string dept; //학과

public:
	void set(string id, string name, string dept){ //정보입력받는함수
		this->id = id; //학번
		this->name = name; //이름
		this->dept = dept; //학과
	}

	string get_id(){ //private변수 id를 불러오는 함수
		return id;
	}

	string get_name(){ //private변수 name을 불러오는 함수
		return name;
	}

	string get_dept(){ //private변수 dept를 불러오는 함수
		return dept;
	}
};

struct Node{ //연결리스트에 사용할 Node구조체
	Student data; //값을 저장할 변수
	Node* next; //다음 노드의 위치를 저장
};

class StudentList{ //수강자 관리 연결 리스트
	Node* head; //리스트의 헤드
	int length; //리스트 길이
public:
	StudentList(); //생성자
	~StudentList(); //소멸자
	int size(); //리스트길이반환함수
	void sign_up(Student st); //입력받은학생을리스트에저장
	bool search(string id, Student &st); //리스트에서학생을찾는함수
	bool withdraw(string id); //리스트에서학생을지우는함수
	bool change_info(Student st); //리스트내의학생의정보를변경하는함수
	void print_all(); //총 수강학생을 학번순으로 출력
};

bool recur_search(Node* ptr, string id, Student &st); //search함수의 재귀함수 함수원형
bool recur_changeinfo(Node* ptr, Student st); //change_info함수의 재귀함수 함수원형
bool compare(Student &a, Student &b); //sort함수에서 사용하기 위한 연산자 재정의함수 함수원형

int main(){ //메인함수
	StudentList st_list; //학생리스트
	Student st; //학생정보
	string id; //학번
	string name; //이름
	string dept; //학과
	string command; //수강명령어입력

	while(cin >> command){ //break만나기 전까지 명령어를 계속해서 입력받음
		if(command == "Q")//끝내기
			break;
		if(command == "N"){ //수강신청
			cin >> id >> name >> dept; //정보입력
			if(st_list.search(id,st)) //이미 수강신청 되있는 경우
				cout<< "error1" <<endl; //error출력
			else{ //수강신청이 안되있는 경우
				st.set(id, name, dept); //학생정보zip
				st_list.sign_up(st); //리스트에 저장
			}
		}
		else if(command == "W"){ //수강취소
			cin >> id; //학번입력
			if(!st_list.withdraw(id)){ //해당학생 삭제
				cout << "error2" << endl; //학생정보가 없는경우 error출력
			}
		}
		else if(command == "R"){ //수강학생 정보 출력
			cin >> id; //학번입력
			if(st_list.search(id,st)){ //해당학생 찾음
				cout << st.get_id() << " " << st.get_name() << " " << st.get_dept() << endl;
			} //해당학생 정보 출력
			else{ //학생이 없는 경우
				cout << "error2" << endl; //error 출력
			}
		}
		else if(command == "C"){ //수강학생 정보 변경
			cin >> id >> name >> dept; //새로운정보 입력
			st.set(id, name, dept); //학생정보로zip
			if(!st_list.change_info(st)){ //해당학생정보변경
				cout << "error2" << endl; //리스트에 학생이없는경우 error출력
			}
		}
		else if(command == "P"){ //수강 학생들을 학번순서대로 출력
			st_list.print_all();
		}
		else if(command == "S"){ //수강학생 수를 출력
			cout << st_list.size() << endl;
		}
	}
	return 0;
}

StudentList::StudentList() { //생성자
	length = 0; //길이 초기화
	head = NULL; //헤드 초기화
}

StudentList::~StudentList() { //소멸자
	Node* tmp = NULL; //임시노드생성
	while (head!= NULL) {
		tmp = head;
		head = head->next;
		delete tmp; //노드 하나씩 삭제
	}
}

int StudentList::size() { //리스트길이반환
	return length; //length = 리스트의 길이
}

void StudentList::sign_up(Student st) { //수강신청한 학생 저장
	Node* location = new Node; //새로운 노드
	location->data = st; //입력받은 학생의 정보
	location->next = head; //노드끼리 연결
	head = location; //헤드변경
	length++; //길이 증가
}

bool StudentList::search(string id, Student &st) { //학생찾는함수
	return recur_search(head, id, st); //재귀함수호출
}

bool recur_search(Node* ptr, string id, Student &st) {//search의 재귀함수
	if (ptr==NULL) //해당학생이 없는 경우
		return false; //false반환
	else{
		if (ptr->data.get_id() == id) { //해당학생을 찾은 경우
			st = ptr->data; //이름,학번,학과 정보 st에 저장
			return true; //true반환
		}
		else //해당학생을 찾는중
			return recur_search(ptr->next, id, st); //재귀다시호출
	}
}

bool StudentList::withdraw(string id) { //학생지우는함수
	if(head == NULL) //리스트가 비었을때
		return false; //false반환

	else if(head->data.get_id() == id) { //첫번째학생이 해당자일때
		Node* tmp = head; //빈노드생성
		head = head->next; //head이동
		delete tmp; //해당학생 삭제
		length--; //리스트 전체길이 감소
		return true; //true 반환
	}
	else{ //그 이후 학생이 해당자일때
		Node* location = head; //새로운 노드
		while(location->next != NULL){ //두번째학생부터 끝학생까지 살펴봄
			if(location->next->data.get_id() == id){ //해당학생을 찾는다면
				Node* tmp = location->next; //빈노드 생성
				location->next = tmp->next; //노드끼리 앞뒤 연결
				delete tmp; //해당학생 삭제
				length--; //리스트 전체 길이 감소
				return true; //true 반환
			}
			location= location->next; //다음학생정보 살펴봄
		}
		return false; //해당학생이 없는경우 false반환
	}
}

bool StudentList::change_info(Student st) { //학생정보변경
	return recur_changeinfo(head, st); //정보변경 재귀함수호출
}

bool recur_changeinfo(Node* ptr, Student st){ //change_info의 재귀함수
	if (ptr==NULL) //해당학생이 없는 경우
		return false; //false반환
	else{ //비어있지 않을때
		if (ptr->data.get_id() == st.get_id()) { //해당학생을 찾은 경우
			ptr->data = st; //새로입력받은 학생의 정보로 업데이트
			return true; //true반환
		}
		else //학생을 아직못찾은경우
			return recur_changeinfo(ptr->next, st); //재귀함수 다시호출
	}
}

bool compare(Student &a, Student &b) { //학생간의 학번 비교함수
	return a.get_id() < b.get_id(); //학번순으로 정리
}
void StudentList::print_all(){ //학번순으로 학생모두를 출력하는 함수
	Node* fin = head; //새로운 노드
	Student* arr = new Student [length]; //학생들을 저장할 배열
	for(int i=0; i<length; i++) { //반복문
		arr[i]=fin->data; //학생정보를 각각 배열에 저장
		fin = fin->next; //다음학생
	}

	sort(arr, arr+length, compare); //학생들을 학번순으로 순차정렬

	for(int i=0; i<length; i++) { //모든 학생들의 정보 출력
		cout<<arr[i].get_id()<<" "<<arr[i].get_name()<<" "<<arr[i].get_dept()<<endl;
	}

	delete[] arr; //동적할당 받은 배열 반환
}
