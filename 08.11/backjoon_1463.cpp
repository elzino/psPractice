#include <iostream>

using namespace std;

int *dp;


int num(int n) {
	if (n == 1) {
		return 0;
	}
	if (dp[n] > 0) {
		return dp[n];
	}
	dp[n] = num(n - 1) + 1;
	if (n % 3 == 0) {
		if (dp[n] > num(n / 3) + 1) {
			dp[n] = num(n / 3) + 1;
		}
	}
	if (n % 2 == 0) {
		if (dp[n] > num(n / 2) + 1) {
			dp[n] = num(n / 2) + 1;
		}
	}
	return dp[n];

}

int main(void) {
	int n;
	cin >> n;
	dp = new int[n+1]();

	cout << num(n)<<endl;
		

}

