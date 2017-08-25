#include <iostream>


using namespace std;

long long dp[101][21];
int arr[101];

int main(void) {
	int n;


	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dp[1][arr[0]] = 1;
	for (int j = 1; j < n -1; j++) {
		int temp = arr[j];
		for (int i = 0; i <= 20; i++) {
			if (dp[j][i] > 0) {
				if ( i + temp <= 20) {
					dp[j+1][i + temp] += dp[j][i];
				}
				if (i - temp >= 0) {
					dp[j+1][i - temp] += dp[j][i];
				}
			}
		}
	}
	cout << dp[n-1][arr[n - 1]];

}