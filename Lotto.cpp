#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Lotto{
	int lotto_number[7];

public:
	void set_lotto_number();
	bool is_exist_lotto(int num);
	bool is_exist_bonus(int num);
	void print_lotto_number();
};

class User{
	int user_lotto_number[6];

public:
	void set_lotto_number();
	int check_rank(Lotto lotto);
	void print_rank(Lotto lotto);
};

void Lotto::set_lotto_number() {
	for(int i=0; i<7; i++)
		cin>> lotto_number[i];
}

bool Lotto::is_exist_lotto(int num) {
	for(int i=0; i<6; i++) {
		if(lotto_number[i]==num)
			return true;
	}
	return false;
}

bool Lotto::is_exist_bonus(int num) {
	if(lotto_number[6] == num)
		return true;
	else
		return false;
}

void Lotto::print_lotto_number() {
	cout << "로또번호: ";
	for(int i=0; i<6; i++) {
		cout <<lotto_number[i] << " ";
	}
	cout << "보너스 번호 : " << lotto_number[6] << endl;
}

void User::set_lotto_number() {
	for(int i=0; i<6; i++) {
		cin >> user_lotto_number[i];
	}
}

void User::print_rank(Lotto lotto){
	cout << check_rank(lotto) << endl;
}

int User::check_rank(Lotto lotto) {
	int same_number_num = 0;
	bool is_bonus = false;

	for(int i=0; i< 6; i++) {
		if(lotto.is_exist_lotto(user_lotto_number[i]))
			same_number_num++;
		if(lotto.is_exist_bonus(user_lotto_number[i]))
			is_bonus = true;
	}

	switch(same_number_num){
	case 6:
		return 1;
	case 5:
		if(is_bonus)
			return 2;
		else
			return 3;
	case 4:
		return 4;
	case 3:
		return 5;
	default:
		return -1;
	}
}

int main(){
	User user;
	Lotto lotto;

	user.set_lotto_number();

	lotto.set_lotto_number();
	lotto.print_lotto_number();

	user.print_rank(lotto);

	return 0;
}
