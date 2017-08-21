#include <iostream>
#include <algorithm>

using namespace std;


int arr[1001][1001];
int dp[1001][1001];
int his[1001][1001];


int go(int n, int m) {
	if (his[n][m] > 0) {
		return dp[n][m];
	}
	if (n == 1 & m == 1) {
		return dp[1][1];
	}
	if (n == 1) {
		dp[n][m] = arr[n][m] + go(n , m-1);
	}
	else if (m == 1) {
		dp[n][m] = arr[n][m] + go(n-1 , m);
	}
	else {
		dp[n][m] = arr[n][m] + max(go(n - 1, m), go(n, m-1));
	}
	his[n][m] = 1;
	return dp[n][m];
}

int main(void) {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	dp[1][1] = arr[1][1];
	cout << go(n, m);
}