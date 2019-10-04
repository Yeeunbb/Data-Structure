#include <iostream> //iostream ����Լ�  ����
#include <string> //string ����Լ� ����

using namespace std;
//���� ���α׷�
class Calculator{ //Calculator Ŭ����
	int c_value; //���� ���� �����ϴ� ����
	int m_value; //�޸𸮿� ������ ���� �����ϴ� ����

public:
	Calculator(int initial); //������
	void set_value(int value); //���� ���� �������ִ� �Լ�
	int get_value(); //���� ���� ��ȯ�ϴ� �Լ�
	void add(int value); //���ϱ� ������ �����ϴ� �Լ�
	void sub(int value); //���� ������ �����ϴ� �Լ�
	void multiply(int value); //���ϱ� ������ �����ϴ� �Լ�
	void divide(int value); //������ ������ �����ϴ� �Լ�
	void mod(int value); //�������� ������ ���� ���ϴ� �Լ�
	void change_sign(); //���� ���� ��ȣ�� �ٲٴ� �Լ�
	void clear(); //���� ���� 0���� �ٲ��ִ� �Լ�
	void memory_save(); //���� ���� �޸𸮿� �����ϴ� �Լ�
	void memory_read(); //�޸𸮿� �ִ� ���� ���� ������ �����ϴ� �Լ�
	void memory_clear(); //�޸𸮿� ����� ���� 0���� �ٲٴ� �Լ�
	void memory_add(); //�޸𸮿� ����Ǿ� �ִ� ���� ���� ���� ���Ͽ� �� ���� �����ϴ� �Լ�
	void memory_sub(); //�޸𸮿� ����Ǿ� �ִ� ���� ���� ���� ���� �� ���� �����ϴ� �Լ�

};

Calculator::Calculator(int initial){
	c_value = initial;	//���� ���� initial ���� ����
	m_value = initial; //�޸� ���� initial ���� ����
}

void Calculator::set_value(int value){
	c_value = value; //���� ���� value�� �ٲ�
}

int Calculator::get_value(){
	return c_value; //���� �� ��ȯ
}

void Calculator::add(int value){
	c_value += value; //���� ���� value���� ���Ͽ� ����
}

void Calculator::sub(int value){
	c_value -= value; //���� ���� value���� �� �� ����
}

void Calculator::multiply(int value){
	c_value *= value; //���� ���� value���� ���� �� ����
}

void Calculator::divide(int value){
	c_value /= value; //���� ���� value���� ���� �� ���� ����
}

void Calculator::mod(int value){
	c_value %= value; //���� ���� value�� ���� �� �������� ����
}

void Calculator::change_sign(){
	c_value = -c_value; //���� ���� ��ȣ�� �ٲ� �� ����
}

void Calculator::clear(){
	c_value = 0; //���� ���� 0���� ����
}

void Calculator::memory_save(){
	m_value = c_value; //�޸� ���� ���� ���� ����
}

void Calculator::memory_read(){
	c_value = m_value; //���� ���� �޸� ���� ����
}

void Calculator::memory_clear(){
	m_value = 0; //�޸� ���� 0���� ����
}

void Calculator::memory_add(){
	m_value += c_value; //�޸𸮰��� ���簪�� ���� �� ����
}

void Calculator::memory_sub(){
	m_value -= c_value; //�޸𸮰��� ���� ���� �� �� ����
}

int main() //�����Լ�
{
	Calculator cal(0); //CalculatorŬ���� cal����. �ʱⰪ 0����
	string EXITCMD = "exit"; //���α׷� ���Ṯ�� ����
	string command; //�Է¹��� ��ɾ� ����

	int operand; //����� ���� ����

	cin >> command; //��ɾ� �Է�

	while (command != EXITCMD){ //���α׷� ���Ṯ�� �Է� ������ �ݺ��Ǵ� �ݺ���
		if(command == "clear") //��ɾ clear�� ��
			cal.clear(); //calŬ������ clear�Լ� ����

		else if(command == "cs") //��ɾ cs�� ��
			cal.change_sign(); //calŬ������ change_sign�Լ� ����

		else if(command == "MS") //��ɾ MS�� ��
			cal.memory_save(); //calŬ������ memory_save�Լ� ����

		else if(command == "MR") //��ɾ MR�� ��
			cal.memory_read(); //calŬ������ memory_read�Լ� ����

		else if(command == "M+") //��ɾ M+�� ��
			cal.memory_add(); //calŬ������ memory_add�Լ� ����

		else if(command == "M-") //��ɾ M-�� ��
			cal.memory_sub(); //calŬ������ memory_sub�Լ� ����

		else if(command == "MC") //��ɾ MC�� ��
			cal.memory_clear(); //calŬ������ memory_clear�Լ� ����

		else
		{ //��ɾ� + ����� ���ڸ� �Է¹���
			cin >> operand;
			if (command == "add") { //��ɾ add�� ��
				cal.add(operand); //calŬ������ add�Լ� ����
			}

			else if (command == "sub") { //��ɾ sub�� ��
				cal.sub(operand); //calŬ������ sub�Լ� ����
			}

			else if (command == "mul") { //��ɾ mul�� ��
				cal.multiply(operand); //calŬ������ multiply�Լ� ����
			}

			else if (command == "div") { //��ɾ div�� ��
				cal.divide(operand); //calŬ������ divide�Լ� ����
			}

			else if (command == "mod") { //��ɾ mod�� ��
				cal.mod(operand); //calŬ������ mod�Լ� ����
			}

			else if (command == "setValue") { //��ɾsetValue�� ��
				cal.set_value(operand); //calŬ������ set_value�Լ� ����
			}
		}

		cout << cal.get_value() << endl; //calŬ������ ���簪 ��ȯ
		cin >> command; // ���� ��ɾ� �ٽ� �Է¹���
	}

	return 0; //�����Լ� ����
}
