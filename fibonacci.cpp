#include <iostream>

using namespace std;

int fibonacci(int n);

int main(){

	int onearr[41];
	int zeroarr[42];
	zeroarr[0]=1;
	for(int i=0; i<=40; i++){
		onearr[i]=fibonacci(i);
		zeroarr[i+1]=fibonacci(i);
	}
	int a,b;
	cin>>a;
	for(int i=0; i<a; i++){
		cin>>b;
		cout<<zeroarr[b]<<" "<<onearr[b]<<endl;
	}
	/*

	int dp[41][2];
	int n, k;

	dp[0][0] = 1;
	dp[0][1] = 0;
	dp[1][0] = 0;
	dp[1][1] = 1;

	cin>>n;
	for(int i = 0 ;i < n; i++)
	{
		cin>>k;
		for(int j = 2 ; j <= k ; j++)
		{
			dp[j][0] = dp[j-1][0] + dp[j-2][0];
			dp[j][1] = dp[j-1][1] + dp[j-2][1];
		}
		cout<<dp[k][0]<<" "<<dp[k][1]<<endl;
	}
	*/
	return 0;
}

int fibonacci(int n) {
	if (n == 0) {
		return n;
	}

	else if ( n == 1) {
		return n;
	}
	else{
		int i, tmp, current=1, last=0;
		for(i=2; i<=n; i++){
			tmp = current;
			current +=last;
			last = tmp;
		}
		return current;
	}
}
