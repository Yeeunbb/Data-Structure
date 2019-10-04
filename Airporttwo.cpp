<<<<<<< HEAD
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

#define MAX_QUEUE_SIZE 1000 //배열의 최대 크기는 1000

typedef struct Information { //공항에 온 사람들의 시간 정보
	int arrive_time; //도착한 시간
	int service_time; //상담받는 시간
	int real_arrive; //진짜로 도착한 시간

} Information;

class Queue { //원형 큐
	int front; //처음 인덱스를 가리킴
	int rear; //마지막 인덱스를 가리킴
	Information data[MAX_QUEUE_SIZE]; //구조체형 데이타 배열

public:
	Queue(); //생성자
	void enqueue(Information man); //새로운 자료 저장
	Information dequeue(); //처음에 들어온 원소 삭제 및 반환
	Information peek(); //처음에 들어온 원소 반환
	bool isEmpty(); //비어있는지 확인
	bool isFull(); //가득차있는지 확인
	void display(); //큐내부 출력
};

int main() { //메인함수
	Queue Allpeople; //공항에 오는 모든 사람들의 정보
	Queue Arrivepeople; //심사받기전 대기하는 공간. 공항에 도착한 사람들만 들어감
	struct Information Customer; //정보를 입력받을 변수
	int waiting_time=0; //대기하는 총 시간
	int service_All=0; //상담받는 총 시간
	float result; //대기총시간 나누기 사람 수
	int customer; //총 사람 수

	cin >> customer; //몇명이 오는지 입력받음

	for(int i = 0; i< customer; i++) { //사람수만큼 반복
		cin >> Customer.arrive_time >> Customer.service_time; //시간정보 입력받음
		Customer.real_arrive += Customer.arrive_time; //진짜 도착한시간을 누적으로 계산하여, 개개인의 진짜 도착시간정보 입력
		Allpeople.enqueue(Customer); //Allpeople큐에 저장
		service_All += Customer.service_time + Customer.arrive_time; //총 서비스 시간은 고객 개개인의 도착시간+상담시간
	}

	Information now = Allpeople.dequeue(); //상담대에 들어갈 사람
	Information s1 = {.arrive_time=0, .service_time=0, .real_arrive=0}; //상담대 1
	Information s2 = {.arrive_time=0, .service_time=0, .real_arrive=0}; //상담대 2

	for(int i=0; i<service_All; i++) { //모든 사람의 상담이 끝나는 시간보다 더 충분한 시간 service_All 시간 만큼 반복. i는 시간을 의미
		if(now.real_arrive == i){ //심사대의 들어갈 사람의 진짜 도착시간이 i 일 때
			Arrivepeople.enqueue(now); //대기실에 그 사람 들여보냄
			if(!Allpeople.isEmpty()){ //Allpeople큐가 비어있지 않다면
				now = Allpeople.dequeue(); //다음 순서로 올 사람 now에 저장
			}
		}

		if( s1.service_time == 0 && !Arrivepeople.isEmpty()){ //심사대1에 있는 사람의 상담시간이 끝났고, 대기실에 사람이 있는 경우
			s1 = Arrivepeople.dequeue(); //심사대 1에 대기실에 있는 사람중 먼저 온 사람 넣음
			waiting_time += i - s1.real_arrive; //대기시간은 현재시간 - 지금 상담대에 들어간 사람의 실제 도착 시간
		}

		if( s2.service_time == 0 && !Arrivepeople.isEmpty()){ //심사대2에 있는 사람의 상담시간이 끝났고, 대기실에 사람이 있는 경우
			s2 = Arrivepeople.dequeue(); //심사대2에 대기실에 있는 사람중 먼저 온 사람 넣음
			waiting_time += i - s2.real_arrive; //대기시간은 현재시간 - 지금 상담대에 들어간 사람의 실제 도착 시간
		}

		s1.service_time--; //for문이 반복된다는건 시간이 흐른다는 의미. s1에 있는 사람의 상담시간 또한 감소
		s2.service_time--; //s1과 같은 맥락
		if(s1.service_time < 0) //s1에 사람이 없는경우에 service_time--조건에 의해 값이 음수가 되는경우
			s1.service_time = 0; //다시 0으로 초기화
		else if(s2.service_time < 0) //s1과 같은 맥락
			s2.service_time = 0;
	}

	result = (float)waiting_time / customer; //총 대기시간을 사람수로 나눈 결과 값
	cout << fixed << setprecision(2) << result << endl; //소수점 아래 두자리까지 결과 출력

	return 0; //프로그램 종료

}

Queue::Queue() { //생성자
	front = rear = 0; //0으로 인덱스 초기화
}

bool Queue::isEmpty() { //비어있는지 확인하는 함수
	return front == rear; //front와 rear의 값이 같을 때 원형큐는 비어있음
}

bool Queue::isFull() { //가득차있는지 확인하는 함수
	return (rear+1)%MAX_QUEUE_SIZE == front;
} //front는 한칸 비어두므로, rear+1이 front와 같은 값일때 큐는 가득 차있음.

void Queue::enqueue(Information man){//새로운 원소 삽입
	if(isFull()) { //가득 차있을 때
		cout << "error: 큐가 포화상태입니다."<< endl;
		exit(1); //에러 메시지 출력 후 종료
	}
	else{
		rear = (rear+1) % MAX_QUEUE_SIZE; //마지막 인덱스 증가해줌
		data[rear] = man; //마지막 위치에 새로운 원소 저장
	}
}

Information Queue::dequeue() { //원소 삭제 및 반환
	if(isEmpty()){ //비어있을 때
		cout << "error: 큐가 공백상태입니다." << endl;
		exit(1); //에러메시지 출력 후 종료
	}
	else {
		front = (front+1) % MAX_QUEUE_SIZE; //처음에 들어온 원소 위치 = front
		return data[front]; //front값 반환. 처음 들어온 원소값은 무시됨
	}
}

Information Queue::peek() { //원소 반환
	if(isEmpty()) { //비어있을 때
		cout << "error: 큐가 공백상태입니다." << endl;
		exit(1); //에러 메시지 출력 후 종료
	}
	else
		return data[(front+1) % MAX_QUEUE_SIZE];
} //처음에 들어온 원소의 위치 front+1 의 데이터 값 반환
=======
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

#define MAX_QUEUE_SIZE 1000 //배열의 최대 크기는 1000

typedef struct Information { //공항에 온 사람들의 시간 정보
	int arrive_time; //도착한 시간
	int service_time; //상담받는 시간
	int real_arrive; //진짜로 도착한 시간

} Information;

class Queue { //원형 큐
	int front; //처음 인덱스를 가리킴
	int rear; //마지막 인덱스를 가리킴
	Information data[MAX_QUEUE_SIZE]; //구조체형 데이타 배열

public:
	Queue(); //생성자
	void enqueue(Information man); //새로운 자료 저장
	Information dequeue(); //처음에 들어온 원소 삭제 및 반환
	Information peek(); //처음에 들어온 원소 반환
	bool isEmpty(); //비어있는지 확인
	bool isFull(); //가득차있는지 확인
	void display(); //큐내부 출력
};

int main() { //메인함수
	Queue Allpeople; //공항에 오는 모든 사람들의 정보
	Queue Arrivepeople; //심사받기전 대기하는 공간. 공항에 도착한 사람들만 들어감
	struct Information Customer; //정보를 입력받을 변수
	int waiting_time=0; //대기하는 총 시간
	int service_All=0; //상담받는 총 시간
	float result; //대기총시간 나누기 사람 수
	int customer; //총 사람 수

	cin >> customer; //몇명이 오는지 입력받음

	for(int i = 0; i< customer; i++) { //사람수만큼 반복
		cin >> Customer.arrive_time >> Customer.service_time; //시간정보 입력받음
		Customer.real_arrive += Customer.arrive_time; //진짜 도착한시간을 누적으로 계산하여, 개개인의 진짜 도착시간정보 입력
		Allpeople.enqueue(Customer); //Allpeople큐에 저장
		service_All += Customer.service_time + Customer.arrive_time; //총 서비스 시간은 고객 개개인의 도착시간+상담시간
	}

	Information now = Allpeople.dequeue(); //상담대에 들어갈 사람
	Information s1 = {.arrive_time=0, .service_time=0, .real_arrive=0}; //상담대 1
	Information s2 = {.arrive_time=0, .service_time=0, .real_arrive=0}; //상담대 2

	for(int i=0; i<service_All; i++) { //모든 사람의 상담이 끝나는 시간보다 더 충분한 시간 service_All 시간 만큼 반복. i는 시간을 의미
		if(now.real_arrive == i){ //심사대의 들어갈 사람의 진짜 도착시간이 i 일 때
			Arrivepeople.enqueue(now); //대기실에 그 사람 들여보냄
			if(!Allpeople.isEmpty()){ //Allpeople큐가 비어있지 않다면
				now = Allpeople.dequeue(); //다음 순서로 올 사람 now에 저장
			}
		}

		if( s1.service_time == 0 && !Arrivepeople.isEmpty()){ //심사대1에 있는 사람의 상담시간이 끝났고, 대기실에 사람이 있는 경우
			s1 = Arrivepeople.dequeue(); //심사대 1에 대기실에 있는 사람중 먼저 온 사람 넣음
			waiting_time += i - s1.real_arrive; //대기시간은 현재시간 - 지금 상담대에 들어간 사람의 실제 도착 시간
		}

		if( s2.service_time == 0 && !Arrivepeople.isEmpty()){ //심사대2에 있는 사람의 상담시간이 끝났고, 대기실에 사람이 있는 경우
			s2 = Arrivepeople.dequeue(); //심사대2에 대기실에 있는 사람중 먼저 온 사람 넣음
			waiting_time += i - s2.real_arrive; //대기시간은 현재시간 - 지금 상담대에 들어간 사람의 실제 도착 시간
		}

		s1.service_time--; //for문이 반복된다는건 시간이 흐른다는 의미. s1에 있는 사람의 상담시간 또한 감소
		s2.service_time--; //s1과 같은 맥락
		if(s1.service_time < 0) //s1에 사람이 없는경우에 service_time--조건에 의해 값이 음수가 되는경우
			s1.service_time = 0; //다시 0으로 초기화
		else if(s2.service_time < 0) //s1과 같은 맥락
			s2.service_time = 0;
	}

	result = (float)waiting_time / customer; //총 대기시간을 사람수로 나눈 결과 값
	cout << fixed << setprecision(2) << result << endl; //소수점 아래 두자리까지 결과 출력

	return 0; //프로그램 종료

}

Queue::Queue() { //생성자
	front = rear = 0; //0으로 인덱스 초기화
}

bool Queue::isEmpty() { //비어있는지 확인하는 함수
	return front == rear; //front와 rear의 값이 같을 때 원형큐는 비어있음
}

bool Queue::isFull() { //가득차있는지 확인하는 함수
	return (rear+1)%MAX_QUEUE_SIZE == front;
} //front는 한칸 비어두므로, rear+1이 front와 같은 값일때 큐는 가득 차있음.

void Queue::enqueue(Information man){//새로운 원소 삽입
	if(isFull()) { //가득 차있을 때
		cout << "error: 큐가 포화상태입니다."<< endl;
		exit(1); //에러 메시지 출력 후 종료
	}
	else{
		rear = (rear+1) % MAX_QUEUE_SIZE; //마지막 인덱스 증가해줌
		data[rear] = man; //마지막 위치에 새로운 원소 저장
	}
}

Information Queue::dequeue() { //원소 삭제 및 반환
	if(isEmpty()){ //비어있을 때
		cout << "error: 큐가 공백상태입니다." << endl;
		exit(1); //에러메시지 출력 후 종료
	}
	else {
		front = (front+1) % MAX_QUEUE_SIZE; //처음에 들어온 원소 위치 = front
		return data[front]; //front값 반환. 처음 들어온 원소값은 무시됨
	}
}

Information Queue::peek() { //원소 반환
	if(isEmpty()) { //비어있을 때
		cout << "error: 큐가 공백상태입니다." << endl;
		exit(1); //에러 메시지 출력 후 종료
	}
	else
		return data[(front+1) % MAX_QUEUE_SIZE];
} //처음에 들어온 원소의 위치 front+1 의 데이터 값 반환
>>>>>>> 703c4cd30b5df7fc525d0c1e7238cdd23ea21d06
