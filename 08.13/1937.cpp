#include <iostream>


using namespace std;

int arr[501][501];
int dp[501][501];

int n;


int cal(int row, int column) {
	if (dp[row][column] >= 0) {
		return dp[row][column];
	}
	int bamboo = arr[row][column];
	int temp = 0;
	if (row > 1&& arr[row-1][column]> bamboo) {
		int k = cal(row - 1, column);
		if (temp < k) {
			temp = k;
		}
	}
	if (row < n && arr[row + 1][column]> bamboo) {
		int k = cal(row + 1, column);
		if (temp < k) {
			temp = k;
		}
	}
	if (column > 1 && arr[row][column -1 ]> bamboo) {
		int k = cal(row , column - 1);
		if (temp < k) {
			temp = k;
		}
	}
	if (column < n && arr[row][column +1]> bamboo) {
		int k = cal(row, column + 1);
		if (temp < k) {
			temp = k;
		}
	}

	dp[row][column] = temp + 1;
	return temp + 1;

}

int main(void) {

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			dp[i][j] = -1;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cal(i, j);
		}
	}

	int max = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (max < dp[i][j]) {
				max = dp[i][j];
			}
		}
	}

	cout << max;
}