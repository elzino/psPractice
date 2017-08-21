#include <iostream>

using namespace std;

int main(void) {
	int n;
	int arr[1001];
	int dp[1001];
	cin >> n;
	for (int i = 1; i <=n; i++) {
		cin >> arr[i];
	}
	dp[1] = arr[1];
	for (int i = 2; i <= n; i++) {
		int temp = arr[i];
		for (int j = 1; j < i; j++) {
			if (temp < arr[j] + dp[i - j]) {
				temp = arr[j] + dp[i - j];
			}
		}
		dp[i] = temp;
	}
	cout << dp[n];
}