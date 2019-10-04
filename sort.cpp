#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>

using namespace std;

bool desc(int a, int b){ return a>b; }

int main() {
	int a,b=0;
	cin>>a;
	int arr[11];
	for(int i=0; i<11; i++){
		arr[i]=a%10;
		if(a>=10)
			a=a/10;
		else{
			arr[i+1] = a;
			b=i+1;
			break;
		}
	}
	/*
	while(a>0){
		arr[b]=a%10;
		a/=10;
		b++;
	}*/
	/*
	for(int cnt = 0 ; a > 0 ; cnt++)
	   {
	       arr[cnt]=a%10; // 배열에 각 숫자 저장
	       a/=10;
	       cnt++; // 카운트 1 증가
	   } */

	sort(arr, arr+b, desc);

	for(int i=0; i<b; i++) {
		cout<<arr[i];
	}
	return 0;
}

