#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

#define MAX_QUEUE_SIZE 1000 //배열의 최대크기 1000

typedef struct Information { //심사를 받을 사람들의 정보를 저장할 구조체
	int arrive_time; //도착한 시간을 저장할 변수
	int service_time; //심사시간을 저장할 변수
} Information;

class Queue { //원형큐
	int front; //제일 처음에 들어온 값을 가리킴
	int rear; //제일 마지막에 들어온 값을 가리킴
	Information data[MAX_QUEUE_SIZE]; //구조체 배열을 가지는 data

public:
	Queue(); //생성자
	void enqueue(Information man); //man값을 큐에 저장
	Information dequeue(); //처음에 들어온 값부터 삭제 및 반환
	Information peek(); //처음에 들어온 값 반환
	bool isEmpty(); //큐가 비어있는지 확인
	bool isFull(); //큐가 꽉 차있는지 확인
	void display(); // 큐 값을 보여주는 함수
};

int main() { //메인함수
	Queue people; //사람들의 정보를 저장할 큐
	struct Information Customer; //사람들의 정보를 입력받을 구조체
	int waiting_time=0; //대기시간을 모두 합칠 변수
	int all_service=0; //입력받은 사람들의 모든 상담시간 합
	int all_arrive=0; //입력받은 사람들의 모든 도착시간 합
	float result; //총 대기시간 평균 결과값
	int customer; //공항에 오는 사람들의 수
	cin >> customer; //공항에 오는 사람의 수 입력받음

	for(int i = 0; i< customer; i++) { //사람 수 만큼 for문 반복
		cin >> Customer.arrive_time >> Customer.service_time; //도착시간, 상담시간 구조체에 저장
		people.enqueue(Customer); //people에 모든 사람들 저장
	}

	while(!people.isEmpty()) { //people큐가 빌때까지 while문 반복
		Information before = people.dequeue(); //before구조체에 공항에 도착한 순서로 사람들 대입

		if(before.arrive_time == 0) { //맨처음에 도착한 사람일때
			all_service += before.service_time; //상담시간만 + 해줌
		}
		else { //이후에 온 사람들일때
			all_arrive += before.arrive_time; //도착시간 + 해줌
			if((all_service - all_arrive)>0) { // 모든 상담시간이 모든 도착시간보다 클 때
				waiting_time += all_service - all_arrive; //대기시간은 모든 상담시간 - 모든 도착시간
			}
			else{ //모든 상담시간이 모든 도착시간보다 작을 때
				all_service += all_arrive - all_service; //모든 상담시간은 모든 도착시간 - 모든 상담시간
			}
			all_service += before.service_time; // 모든 상담시간에 지금 상담대에 들어간 사람의 상담시간 누적
		}
	}

	result = (float)waiting_time / customer; // 결과는 모든 대기시간 나누기 고객의 수

	cout << fixed << setprecision(2) << result << endl; //결과값을 소수점 아래 두자리까지 출력

	return 0; //프로그램 종료

}

Queue::Queue() { //큐생성자
	front = rear = 0; //배열의 인덱스 0 으로 초기화
}

bool Queue::isEmpty() { //비어있는지 확인하는 함수
	return front == rear; //원형큐이므로 값이 같을때는 비어있는 것이다.
}

bool Queue::isFull() { //가득차있는지 확인하는 함수
	return (rear+1)%MAX_QUEUE_SIZE == front; //꽉차있는지 확인하기 위해서 front를 한칸 비워두고 구현함. 그래서 rear+1을 해서 확인
}

void Queue::enqueue(Information man){ //새로운 원소 삽입
	if(isFull()) { // 큐가 가득 차있다면
		cout << "error: 큐가 포화상태입니다."<< endl;
		exit(1); //에러 메시지 출력 후 종료
	}
	else{ //큐가 가득 차있지 않을 때
		rear = (rear+1) % MAX_QUEUE_SIZE; //배열의 가장 마지막 인덱스 +1 해줌
		data[rear] = man; //그 위치에 원소 삽입
	}
}

Information Queue::dequeue() { //배열에 가장 먼저 들어온 원소 삭제 및 반환
	if(isEmpty()){ //배열이 비어있을 때
		cout << "error: 큐가 공백상태입니다." << endl;
		exit(1); //에러 메시지 출력 후 종료
	}
	else { //배열이 차있을 때
		front = (front+1) % MAX_QUEUE_SIZE; //front는 한칸 비어있으므로 front+1한 인덱스에 저장되어있는게 가장 처음 들어온 원소임
		return data[front]; // 가장 처음 들어온 원소 반환 & 값이 있으나 무시
	}
}

Information Queue::peek() { //가장 처음에 들어온 원소 반환
	if(isEmpty()) { //큐가 비어있을 때
		cout << "error: 큐가 공백상태입니다." << endl;
		exit(1); //오류메시지 출력 후 종료
	}
	else //큐에 값이 있을 떄
		return data[(front+1) % MAX_QUEUE_SIZE]; //원소 반환만 실행.
}

/* void Queue::display() { 큐의 내용을 보여주는 함수
	cout << "큐 내용 : " << endl;
	int length = (rear - front > 0) ? rear - front : (rear - front) + MAX_QUEUE_SIZE;
	for(int i = front+1; i <= front + 1 + length; i++)
		cout << "<" << data[i%MAX_QUEUE_SIZE] << ">" << endl;
} */

