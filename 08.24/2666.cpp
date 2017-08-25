#include <iostream>
#include <algorithm>

using namespace std;

int dp[21][21][21];

int main(void) {
	int n;

	cin >> n;


	int p, q;
	cin >> p >> q;


	int m, temp;
	cin >> m;
	for (int k = 0; k <= m; k++) {
		for (int i = 1; i <= n - 1; i++) {
			for (int j = i + 1; j <= n; j++) {
				dp[k][i][j] = -1;
			}
		}
	}
	dp[0][p][q] = 0;


	for (int k = 1; k <= m; k++) {
		cin >> temp;
		for (int i = 1; i <= n-1; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (dp[k - 1][i][j] >= 0) {
					if (temp > j) {
						if (dp[k][i][temp] >= 0) {
							dp[k][i][temp] = min(dp[k][i][temp],dp[k - 1][i][j] + temp - j);

						}
						else {
							dp[k][i][temp] = dp[k - 1][i][j] + temp - j;
						}
					}
					else if (temp == j) {
						if (dp[k][i][j] >= 0) {
							dp[k][i][j] = min(dp[k][i][j],dp[k - 1][i][j]);

						}
						else {
							dp[k][i][j] = dp[k - 1][i][j];
						}
					}
					else if (i < temp&&temp < j) {
						if (dp[k][temp][j]>=0) {
							dp[k][temp][j] = min(dp[k][temp][j],dp[k - 1][i][j] + temp - i);
						}
						else {
							dp[k][temp][j] = dp[k - 1][i][j] + temp - i;
						}
						if (dp[k][i][temp] >= 0) {
							dp[k][i][temp] = min(dp[k][i][temp],dp[k - 1][i][j] + j - temp);
						}
						else {
							dp[k][i][temp] = dp[k - 1][i][j] + j - temp;

						}
					
					}
					else if (temp == i) {
						if (dp[k][i][j]>=0) {
							dp[k][i][j] = min(dp[k][i][j],dp[k - 1][i][j]);
						}
						else {
							dp[k][i][j] = dp[k - 1][i][j];
						}
					}
					else {
						if (dp[k][temp][j] >= 0) {
							dp[k][temp][j] = min(dp[k][temp][j] , dp[k - 1][i][j] + i - temp);
						}
						else {
							dp[k][temp][j] = dp[k - 1][i][j] + i - temp;
						}
					}
				}
			}
		}
	}

	int min = 2012341234;
	for (int i = 1; i <= n-1; i++) {
		for (int j = i+1; j <= n; j++) {
			if (dp[m][i][j] >= 0 &&min>dp[m][i][j]) {
				min = dp[m][i][j];
			}
		}
	}
	cout << min << endl;
	

}