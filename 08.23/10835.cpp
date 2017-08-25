#include <iostream>
#include <algorithm>

using namespace std;




int cardA[2001];
int cardB[2001];

int dp[2001][2001];


int go(int a, int b) {
	if (a == 0 || b == 0) {
		return 0;
	}
	if (dp[a][b] >= 0) {
		return dp[a][b];
	}
	int temp = std::max(go(a - 1, b - 1), go(a - 1, b));
	if (cardA[a] > cardB[b]) {
		temp = max(go(a, b - 1) + cardB[b], temp);
	}

	dp[a][b] = temp;
	return dp[a][b];

}

int main(void) {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> cardA[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> cardB[i];
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			dp[i][j] = -1;
		}
	}

	cout<<go(n, n);


}