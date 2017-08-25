#include <iostream>
#include <algorithm>


using namespace std;



int dp[400000];


int go(int n) {
	if (n >= 100000) {
		int temp;
		if (n % 2 == 0) {
			temp = max(go(n / 2), n);
		}
		else {
			temp = max(go(n * 3 + 1), n);
		}
		return temp;
	}
	if (dp[n] > 0) {
		return dp[n];
	}
	if (n % 2 == 0) {
		dp[n] = max(go(n / 2), n);
	}
	else {
		dp[n] = max(go(n * 3 + 1), n);
	}
	return dp[n];
}
int main(void) {
	int n;

	cin >> n;

	dp[1] = 1;
	dp[2] = 2;
	dp[4] = 4;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		cout << go(temp) << endl;

	}
}