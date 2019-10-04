#include <iostream> //iostream 헤더 함수 포함
#include <string> //string 헤더 함수 포함

using namespace std;
//웹 브라우저 주소이동 프로그램
const int MAX_SIZE = 50;
//const 는 상수. 변하지 않는 숫자.
class Web_browser //Web_browser 클래스 정의
{
	string addr_arr[MAX_SIZE]; //크기를 50으로 가지는 주소를 저장하는 배열
	string history_addr[MAX_SIZE]; //크기를 50으로 가지는 방문했던 모든 주소들을 저장하는 배열
	string home_addr="http://ces.hufs.ac.kr"; //기본 home 주소 값
	int current; //현재 페이지를 나타낼 변수
	int history_current; //방문한 페이지를 나타낼 변수
	int length; //이동가능한 주소들의 갯수
	int history_length; //방문했던 주소들의 갯수

public:
	Web_browser(); //생성자
	void go(string addr); //페이지 이동함수
	void forward(); //앞페이지로 이동함수
	void backward(); //뒷페이지로 이동함수
	void home(); //home으로 이동함수
	void set_home(string addr); //home주소를 설정하는 함수
	void history(); //방문했던 주소들을 모두 출력하는 함수
	string get_current_addr(); //현재 주소를 반환하는 함수
	void print_addr_arr(); //방문했던 주소들을 보여주는 함수
};

Web_browser::Web_browser(){ //생성자
	current = 0; //현재 주소를 나타내는 배열값 0
	history_current = 0; //현재 주소를 나타내는 배열값 0
	history_addr[history_current] = home_addr; //배열의 첫번째 값은 home 주소
	addr_arr[current] = home_addr; //배열의 첫번째 값은 home 주소
	length = 1; //현재 방문한 주소의 갯수는  1
	history_length = 1; //방문한 주소의 갯수는 1
	cout << get_current_addr() << endl; //ces.hufs.ac.kr 출력
}

void Web_browser::go(string addr) { //addr_arr에서 현재 주소 다음에 있는 주소들은 무시하고 현주소 다음 주소에 addr을 추가하고 addr이 현주소가 된다.
	if(current < MAX_SIZE - 1){ //현재주소가 addr_arr배열의 최대를 넘지 않을 때 실행
		current++; //현주소 다음주소로 이동이므로 current 값증가
		addr_arr[current] = addr; //현주소 다음 주소는 입력받은 addr
		length = current+1; //길이는 현주소에 + 1 한 값. current는 0부터 시작했으므로.
	}
	history_current++; //방문기록의 현재위치값 증가
	history_addr[history_current] = addr; //addr로 현재위치 저장
	history_length++; //방문기록의 총 갯수 증가
}

void Web_browser::forward() { //현주소의 앞주소로 이동
	if(current < length - 1) { //현재위치가 이동가능한 모든 주소의 길이보다 작을 떄
		current ++;//현재 주소위치값 증가 = 앞페이지로 이동
	}
}

void Web_browser::backward() { //현주소의 뒷주소로 이동
	if(current != 0) { //현재위치가 배열의 첫번째가 아닐 떄
		current --; //현재 주소의 위치값 감소 = 뒷페이지로 이동
	}
}

void Web_browser::home() { //home설정. go함수랑 유사.
	if(current < MAX_SIZE - 1) { //current가 MAX_SIZE-1이하일때
		current++; //현재 주소 위치값 증가
		addr_arr[current] = home_addr; //증가한 현주소 값 = home주소
		length = current + 1; //현재 주소 위치값 + 1
	}
	history_current++; //방문한 현재위치값 증가
	history_addr[history_current] = home_addr; //현재 위치 주소 = home
	history_length++; //방문한 총 주소값 증가
}

void Web_browser::set_home(string addr) { //홈 주소값 변경
	home_addr = addr; //홈 주소값 입력받은 addr로 변경
}

void Web_browser::history() { //방문한 주소 출력
	if(history_length <= 10) { //방문한 주소들이 10개를 넘지 않을 경우
		for(int i=0; i<history_length; i++) //i는 0부터 방문한 주소갯수까지
			cout << history_addr[i] << endl; //방문한 주소 순차적으로 출력
	}
	else { //방문한 주소들이 10개를 넘는 경우
		for(int i=history_length-10; i<history_length; i++) //최근 방문한 주소 10개를 출력한다
			cout << history_addr[i] << endl; //방문한 주소 순차적으로 출력
	}
}

string Web_browser::get_current_addr() { //현재의 주솟값 가져오기
	return addr_arr[current]; //현재 주소값을 반환한다
}

void Web_browser::print_addr_arr() { //방문한 주소들을 한줄로 보여주는 함수
	for(int i=0; i<length; i++) //i는 0부터 length 까지
		if(i == length - 1) //i가 마지막으로 방문한 주소일때
			cout << addr_arr[i] << endl; //주소 출력후 종료
		else
			cout << addr_arr[i] << " - "; //주소 출력후 - 붙여줌
}

int main() //메인함수
{
	Web_browser wb; //Web_browser 클래스 wb 생성
	string command; //string 객체 command. 명령어를 입력받을것
	string addr; //입력받을 주소 객체
	string EXITCMD = "exit"; //종료 명령어

	while(cin >> command) { //명령어를 계속해서 입력받는 무한루프
		if(command == EXITCMD) { //종료 명령어 입력받을 시
			break; //무한루프 종료
		}
		else if(command == "go") { //go 명령어 입력받을 시
			cin >> addr; //주소값 입력
			wb.go(addr); //go함수 수행
			cout << wb.get_current_addr() << endl; //현재값 반환
		}
		else if(command == "forward") { //forward명령어 입력받을 시
			wb.forward(); //forward함수 수행
			cout << wb.get_current_addr() << endl; //현재값 반환
		}
		else if(command == "backward") { //backward명령어 입력받을 시
			wb.backward(); //backward함수 수행
			cout << wb.get_current_addr() << endl; //현재값 반환
		}
		else if(command == "home") { //home명령어 입력받을 시
			wb.home(); //home함수 수행
			cout << wb.get_current_addr() << endl; //현재값 반환
		}
		else if(command == "set_home") { //set_home 명령어 입력받을 시
			cin >> addr; //주소값 입력
			wb.set_home(addr); //set_home 함수 수행
		}
		else if(command == "history") { //history명령어 입력받을 시
			wb.history(); //history 함수 수행
		}
	}

	return 0; //메인함수 종료
}
