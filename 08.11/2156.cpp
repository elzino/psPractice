#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	int arr[10001];
	int dp[10001];
	for (int i = 1; i <=n; i++) {
		cin >> arr[i];
	}
	dp[1] = arr[1];
	if (n == 1) {
		cout << dp[1];
		return 0;
	}
	dp[2] = arr[1] + arr[2];
	if (n == 2) {
		cout << dp[2];
		return 0;
	}
	dp[3] = max(max(arr[1] + arr[2], arr[2] + arr[3]), arr[1] + arr[3]);
	if (n == 3) {
		cout << dp[3];
		return 0;
	}
	for (int i = 4; i <=n; i++) {
		int temp = dp[i - 1];
		if (temp < arr[i] + dp[i - 2]) {
			temp = arr[i] + dp[i - 2];
		}
		if (temp < arr[i] + arr[i - 1] + dp[i - 3]) {
			temp = arr[i] + arr[i - 1] + dp[i - 3];
		}
		dp[i] = temp;
	}
	cout << dp[n];
}