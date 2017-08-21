#include <iostream>

using namespace std;


int arr[101];
int cost[101];
int dp[10001];




int main(void) {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
	}

	for (int i = 0; i <= n*100; i++) {
		dp[i] = -1;
	}
	dp[0] = 0;
	int max = 0;
	int maxpre = 0;

	for (int i = 0; i < n; i++) {
		for (int j = max; j>=0; j--) {
			if (dp[j] >= 0 && dp[j + cost[i]] < dp[j] + arr[i]) {
				dp[j + cost[i]] = dp[j] + arr[i];
				if (j + cost[i]>maxpre) {
					maxpre = j + cost[i];
				}
				
			}
		}
		max = maxpre;
	}
	for (int i = 0; i <= max; i++) {
		if (dp[i] >= m) {
			cout << i;
			break;
		}
	}


}