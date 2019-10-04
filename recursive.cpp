#include <iostream>

using namespace std;

void f1(int n);
void f2(int n);

int main() {
	f1(5);
	f2(5);
}

void f1(int n) {
	if(n>0) {
		cout << n << endl;
		f1(n-1);
	}
}
void f2(int n) {
	if (n>0) {
		f2(n-1);
		cout << n << endl;
	}
}

/* f2(5)
 * f2(4)
 * f2(3)
 * f2(2)
 * f2(1)
 * f2(0)
 * 1
 * 2
 * 3
 * 4
 * 5
 */
