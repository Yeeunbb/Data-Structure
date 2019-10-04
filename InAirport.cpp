#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

#define MAX_QUEUE_SIZE 1000 //�迭�� �ִ�ũ�� 1000

typedef struct Information { //�ɻ縦 ���� ������� ������ ������ ����ü
	int arrive_time; //������ �ð��� ������ ����
	int service_time; //�ɻ�ð��� ������ ����
} Information;

class Queue { //����ť
	int front; //���� ó���� ���� ���� ����Ŵ
	int rear; //���� �������� ���� ���� ����Ŵ
	Information data[MAX_QUEUE_SIZE]; //����ü �迭�� ������ data

public:
	Queue(); //������
	void enqueue(Information man); //man���� ť�� ����
	Information dequeue(); //ó���� ���� ������ ���� �� ��ȯ
	Information peek(); //ó���� ���� �� ��ȯ
	bool isEmpty(); //ť�� ����ִ��� Ȯ��
	bool isFull(); //ť�� �� ���ִ��� Ȯ��
	void display(); // ť ���� �����ִ� �Լ�
};

int main() { //�����Լ�
	Queue people; //������� ������ ������ ť
	struct Information Customer; //������� ������ �Է¹��� ����ü
	int waiting_time=0; //���ð��� ��� ��ĥ ����
	int all_service=0; //�Է¹��� ������� ��� ���ð� ��
	int all_arrive=0; //�Է¹��� ������� ��� �����ð� ��
	float result; //�� ���ð� ��� �����
	int customer; //���׿� ���� ������� ��
	cin >> customer; //���׿� ���� ����� �� �Է¹���

	for(int i = 0; i< customer; i++) { //��� �� ��ŭ for�� �ݺ�
		cin >> Customer.arrive_time >> Customer.service_time; //�����ð�, ���ð� ����ü�� ����
		people.enqueue(Customer); //people�� ��� ����� ����
	}

	while(!people.isEmpty()) { //peopleť�� �������� while�� �ݺ�
		Information before = people.dequeue(); //before����ü�� ���׿� ������ ������ ����� ����

		if(before.arrive_time == 0) { //��ó���� ������ ����϶�
			all_service += before.service_time; //���ð��� + ����
		}
		else { //���Ŀ� �� ������϶�
			all_arrive += before.arrive_time; //�����ð� + ����
			if((all_service - all_arrive)>0) { // ��� ���ð��� ��� �����ð����� Ŭ ��
				waiting_time += all_service - all_arrive; //���ð��� ��� ���ð� - ��� �����ð�
			}
			else{ //��� ���ð��� ��� �����ð����� ���� ��
				all_service += all_arrive - all_service; //��� ���ð��� ��� �����ð� - ��� ���ð�
			}
			all_service += before.service_time; // ��� ���ð��� ���� ���뿡 �� ����� ���ð� ����
		}
	}

	result = (float)waiting_time / customer; // ����� ��� ���ð� ������ ���� ��

	cout << fixed << setprecision(2) << result << endl; //������� �Ҽ��� �Ʒ� ���ڸ����� ���

	return 0; //���α׷� ����

}

Queue::Queue() { //ť������
	front = rear = 0; //�迭�� �ε��� 0 ���� �ʱ�ȭ
}

bool Queue::isEmpty() { //����ִ��� Ȯ���ϴ� �Լ�
	return front == rear; //����ť�̹Ƿ� ���� �������� ����ִ� ���̴�.
}

bool Queue::isFull() { //�������ִ��� Ȯ���ϴ� �Լ�
	return (rear+1)%MAX_QUEUE_SIZE == front; //�����ִ��� Ȯ���ϱ� ���ؼ� front�� ��ĭ ����ΰ� ������. �׷��� rear+1�� �ؼ� Ȯ��
}

void Queue::enqueue(Information man){ //���ο� ���� ����
	if(isFull()) { // ť�� ���� ���ִٸ�
		cout << "error: ť�� ��ȭ�����Դϴ�."<< endl;
		exit(1); //���� �޽��� ��� �� ����
	}
	else{ //ť�� ���� ������ ���� ��
		rear = (rear+1) % MAX_QUEUE_SIZE; //�迭�� ���� ������ �ε��� +1 ����
		data[rear] = man; //�� ��ġ�� ���� ����
	}
}

Information Queue::dequeue() { //�迭�� ���� ���� ���� ���� ���� �� ��ȯ
	if(isEmpty()){ //�迭�� ������� ��
		cout << "error: ť�� ��������Դϴ�." << endl;
		exit(1); //���� �޽��� ��� �� ����
	}
	else { //�迭�� ������ ��
		front = (front+1) % MAX_QUEUE_SIZE; //front�� ��ĭ ��������Ƿ� front+1�� �ε����� ����Ǿ��ִ°� ���� ó�� ���� ������
		return data[front]; // ���� ó�� ���� ���� ��ȯ & ���� ������ ����
	}
}

Information Queue::peek() { //���� ó���� ���� ���� ��ȯ
	if(isEmpty()) { //ť�� ������� ��
		cout << "error: ť�� ��������Դϴ�." << endl;
		exit(1); //�����޽��� ��� �� ����
	}
	else //ť�� ���� ���� ��
		return data[(front+1) % MAX_QUEUE_SIZE]; //���� ��ȯ�� ����.
}

/* void Queue::display() { ť�� ������ �����ִ� �Լ�
	cout << "ť ���� : " << endl;
	int length = (rear - front > 0) ? rear - front : (rear - front) + MAX_QUEUE_SIZE;
	for(int i = front+1; i <= front + 1 + length; i++)
		cout << "<" << data[i%MAX_QUEUE_SIZE] << ">" << endl;
} */

