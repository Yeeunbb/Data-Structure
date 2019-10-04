<<<<<<< HEAD
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

#define MAX_QUEUE_SIZE 1000 //�迭�� �ִ� ũ��� 1000

typedef struct Information { //���׿� �� ������� �ð� ����
	int arrive_time; //������ �ð�
	int service_time; //���޴� �ð�
	int real_arrive; //��¥�� ������ �ð�

} Information;

class Queue { //���� ť
	int front; //ó�� �ε����� ����Ŵ
	int rear; //������ �ε����� ����Ŵ
	Information data[MAX_QUEUE_SIZE]; //����ü�� ����Ÿ �迭

public:
	Queue(); //������
	void enqueue(Information man); //���ο� �ڷ� ����
	Information dequeue(); //ó���� ���� ���� ���� �� ��ȯ
	Information peek(); //ó���� ���� ���� ��ȯ
	bool isEmpty(); //����ִ��� Ȯ��
	bool isFull(); //�������ִ��� Ȯ��
	void display(); //ť���� ���
};

int main() { //�����Լ�
	Queue Allpeople; //���׿� ���� ��� ������� ����
	Queue Arrivepeople; //�ɻ�ޱ��� ����ϴ� ����. ���׿� ������ ����鸸 ��
	struct Information Customer; //������ �Է¹��� ����
	int waiting_time=0; //����ϴ� �� �ð�
	int service_All=0; //���޴� �� �ð�
	float result; //����ѽð� ������ ��� ��
	int customer; //�� ��� ��

	cin >> customer; //����� ������ �Է¹���

	for(int i = 0; i< customer; i++) { //�������ŭ �ݺ�
		cin >> Customer.arrive_time >> Customer.service_time; //�ð����� �Է¹���
		Customer.real_arrive += Customer.arrive_time; //��¥ �����ѽð��� �������� ����Ͽ�, �������� ��¥ �����ð����� �Է�
		Allpeople.enqueue(Customer); //Allpeopleť�� ����
		service_All += Customer.service_time + Customer.arrive_time; //�� ���� �ð��� �� �������� �����ð�+���ð�
	}

	Information now = Allpeople.dequeue(); //���뿡 �� ���
	Information s1 = {.arrive_time=0, .service_time=0, .real_arrive=0}; //���� 1
	Information s2 = {.arrive_time=0, .service_time=0, .real_arrive=0}; //���� 2

	for(int i=0; i<service_All; i++) { //��� ����� ����� ������ �ð����� �� ����� �ð� service_All �ð� ��ŭ �ݺ�. i�� �ð��� �ǹ�
		if(now.real_arrive == i){ //�ɻ���� �� ����� ��¥ �����ð��� i �� ��
			Arrivepeople.enqueue(now); //���ǿ� �� ��� �鿩����
			if(!Allpeople.isEmpty()){ //Allpeopleť�� ������� �ʴٸ�
				now = Allpeople.dequeue(); //���� ������ �� ��� now�� ����
			}
		}

		if( s1.service_time == 0 && !Arrivepeople.isEmpty()){ //�ɻ��1�� �ִ� ����� ���ð��� ������, ���ǿ� ����� �ִ� ���
			s1 = Arrivepeople.dequeue(); //�ɻ�� 1�� ���ǿ� �ִ� ����� ���� �� ��� ����
			waiting_time += i - s1.real_arrive; //���ð��� ����ð� - ���� ���뿡 �� ����� ���� ���� �ð�
		}

		if( s2.service_time == 0 && !Arrivepeople.isEmpty()){ //�ɻ��2�� �ִ� ����� ���ð��� ������, ���ǿ� ����� �ִ� ���
			s2 = Arrivepeople.dequeue(); //�ɻ��2�� ���ǿ� �ִ� ����� ���� �� ��� ����
			waiting_time += i - s2.real_arrive; //���ð��� ����ð� - ���� ���뿡 �� ����� ���� ���� �ð�
		}

		s1.service_time--; //for���� �ݺ��ȴٴ°� �ð��� �帥�ٴ� �ǹ�. s1�� �ִ� ����� ���ð� ���� ����
		s2.service_time--; //s1�� ���� �ƶ�
		if(s1.service_time < 0) //s1�� ����� ���°�쿡 service_time--���ǿ� ���� ���� ������ �Ǵ°��
			s1.service_time = 0; //�ٽ� 0���� �ʱ�ȭ
		else if(s2.service_time < 0) //s1�� ���� �ƶ�
			s2.service_time = 0;
	}

	result = (float)waiting_time / customer; //�� ���ð��� ������� ���� ��� ��
	cout << fixed << setprecision(2) << result << endl; //�Ҽ��� �Ʒ� ���ڸ����� ��� ���

	return 0; //���α׷� ����

}

Queue::Queue() { //������
	front = rear = 0; //0���� �ε��� �ʱ�ȭ
}

bool Queue::isEmpty() { //����ִ��� Ȯ���ϴ� �Լ�
	return front == rear; //front�� rear�� ���� ���� �� ����ť�� �������
}

bool Queue::isFull() { //�������ִ��� Ȯ���ϴ� �Լ�
	return (rear+1)%MAX_QUEUE_SIZE == front;
} //front�� ��ĭ ���ιǷ�, rear+1�� front�� ���� ���϶� ť�� ���� ������.

void Queue::enqueue(Information man){//���ο� ���� ����
	if(isFull()) { //���� ������ ��
		cout << "error: ť�� ��ȭ�����Դϴ�."<< endl;
		exit(1); //���� �޽��� ��� �� ����
	}
	else{
		rear = (rear+1) % MAX_QUEUE_SIZE; //������ �ε��� ��������
		data[rear] = man; //������ ��ġ�� ���ο� ���� ����
	}
}

Information Queue::dequeue() { //���� ���� �� ��ȯ
	if(isEmpty()){ //������� ��
		cout << "error: ť�� ��������Դϴ�." << endl;
		exit(1); //�����޽��� ��� �� ����
	}
	else {
		front = (front+1) % MAX_QUEUE_SIZE; //ó���� ���� ���� ��ġ = front
		return data[front]; //front�� ��ȯ. ó�� ���� ���Ұ��� ���õ�
	}
}

Information Queue::peek() { //���� ��ȯ
	if(isEmpty()) { //������� ��
		cout << "error: ť�� ��������Դϴ�." << endl;
		exit(1); //���� �޽��� ��� �� ����
	}
	else
		return data[(front+1) % MAX_QUEUE_SIZE];
} //ó���� ���� ������ ��ġ front+1 �� ������ �� ��ȯ
=======
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

#define MAX_QUEUE_SIZE 1000 //�迭�� �ִ� ũ��� 1000

typedef struct Information { //���׿� �� ������� �ð� ����
	int arrive_time; //������ �ð�
	int service_time; //���޴� �ð�
	int real_arrive; //��¥�� ������ �ð�

} Information;

class Queue { //���� ť
	int front; //ó�� �ε����� ����Ŵ
	int rear; //������ �ε����� ����Ŵ
	Information data[MAX_QUEUE_SIZE]; //����ü�� ����Ÿ �迭

public:
	Queue(); //������
	void enqueue(Information man); //���ο� �ڷ� ����
	Information dequeue(); //ó���� ���� ���� ���� �� ��ȯ
	Information peek(); //ó���� ���� ���� ��ȯ
	bool isEmpty(); //����ִ��� Ȯ��
	bool isFull(); //�������ִ��� Ȯ��
	void display(); //ť���� ���
};

int main() { //�����Լ�
	Queue Allpeople; //���׿� ���� ��� ������� ����
	Queue Arrivepeople; //�ɻ�ޱ��� ����ϴ� ����. ���׿� ������ ����鸸 ��
	struct Information Customer; //������ �Է¹��� ����
	int waiting_time=0; //����ϴ� �� �ð�
	int service_All=0; //���޴� �� �ð�
	float result; //����ѽð� ������ ��� ��
	int customer; //�� ��� ��

	cin >> customer; //����� ������ �Է¹���

	for(int i = 0; i< customer; i++) { //�������ŭ �ݺ�
		cin >> Customer.arrive_time >> Customer.service_time; //�ð����� �Է¹���
		Customer.real_arrive += Customer.arrive_time; //��¥ �����ѽð��� �������� ����Ͽ�, �������� ��¥ �����ð����� �Է�
		Allpeople.enqueue(Customer); //Allpeopleť�� ����
		service_All += Customer.service_time + Customer.arrive_time; //�� ���� �ð��� �� �������� �����ð�+���ð�
	}

	Information now = Allpeople.dequeue(); //���뿡 �� ���
	Information s1 = {.arrive_time=0, .service_time=0, .real_arrive=0}; //���� 1
	Information s2 = {.arrive_time=0, .service_time=0, .real_arrive=0}; //���� 2

	for(int i=0; i<service_All; i++) { //��� ����� ����� ������ �ð����� �� ����� �ð� service_All �ð� ��ŭ �ݺ�. i�� �ð��� �ǹ�
		if(now.real_arrive == i){ //�ɻ���� �� ����� ��¥ �����ð��� i �� ��
			Arrivepeople.enqueue(now); //���ǿ� �� ��� �鿩����
			if(!Allpeople.isEmpty()){ //Allpeopleť�� ������� �ʴٸ�
				now = Allpeople.dequeue(); //���� ������ �� ��� now�� ����
			}
		}

		if( s1.service_time == 0 && !Arrivepeople.isEmpty()){ //�ɻ��1�� �ִ� ����� ���ð��� ������, ���ǿ� ����� �ִ� ���
			s1 = Arrivepeople.dequeue(); //�ɻ�� 1�� ���ǿ� �ִ� ����� ���� �� ��� ����
			waiting_time += i - s1.real_arrive; //���ð��� ����ð� - ���� ���뿡 �� ����� ���� ���� �ð�
		}

		if( s2.service_time == 0 && !Arrivepeople.isEmpty()){ //�ɻ��2�� �ִ� ����� ���ð��� ������, ���ǿ� ����� �ִ� ���
			s2 = Arrivepeople.dequeue(); //�ɻ��2�� ���ǿ� �ִ� ����� ���� �� ��� ����
			waiting_time += i - s2.real_arrive; //���ð��� ����ð� - ���� ���뿡 �� ����� ���� ���� �ð�
		}

		s1.service_time--; //for���� �ݺ��ȴٴ°� �ð��� �帥�ٴ� �ǹ�. s1�� �ִ� ����� ���ð� ���� ����
		s2.service_time--; //s1�� ���� �ƶ�
		if(s1.service_time < 0) //s1�� ����� ���°�쿡 service_time--���ǿ� ���� ���� ������ �Ǵ°��
			s1.service_time = 0; //�ٽ� 0���� �ʱ�ȭ
		else if(s2.service_time < 0) //s1�� ���� �ƶ�
			s2.service_time = 0;
	}

	result = (float)waiting_time / customer; //�� ���ð��� ������� ���� ��� ��
	cout << fixed << setprecision(2) << result << endl; //�Ҽ��� �Ʒ� ���ڸ����� ��� ���

	return 0; //���α׷� ����

}

Queue::Queue() { //������
	front = rear = 0; //0���� �ε��� �ʱ�ȭ
}

bool Queue::isEmpty() { //����ִ��� Ȯ���ϴ� �Լ�
	return front == rear; //front�� rear�� ���� ���� �� ����ť�� �������
}

bool Queue::isFull() { //�������ִ��� Ȯ���ϴ� �Լ�
	return (rear+1)%MAX_QUEUE_SIZE == front;
} //front�� ��ĭ ���ιǷ�, rear+1�� front�� ���� ���϶� ť�� ���� ������.

void Queue::enqueue(Information man){//���ο� ���� ����
	if(isFull()) { //���� ������ ��
		cout << "error: ť�� ��ȭ�����Դϴ�."<< endl;
		exit(1); //���� �޽��� ��� �� ����
	}
	else{
		rear = (rear+1) % MAX_QUEUE_SIZE; //������ �ε��� ��������
		data[rear] = man; //������ ��ġ�� ���ο� ���� ����
	}
}

Information Queue::dequeue() { //���� ���� �� ��ȯ
	if(isEmpty()){ //������� ��
		cout << "error: ť�� ��������Դϴ�." << endl;
		exit(1); //�����޽��� ��� �� ����
	}
	else {
		front = (front+1) % MAX_QUEUE_SIZE; //ó���� ���� ���� ��ġ = front
		return data[front]; //front�� ��ȯ. ó�� ���� ���Ұ��� ���õ�
	}
}

Information Queue::peek() { //���� ��ȯ
	if(isEmpty()) { //������� ��
		cout << "error: ť�� ��������Դϴ�." << endl;
		exit(1); //���� �޽��� ��� �� ����
	}
	else
		return data[(front+1) % MAX_QUEUE_SIZE];
} //ó���� ���� ������ ��ġ front+1 �� ������ �� ��ȯ
>>>>>>> 703c4cd30b5df7fc525d0c1e7238cdd23ea21d06
