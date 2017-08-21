#include <iostream>

using namespace std;

int arr[501][501];
int dp[501][501];
int n, m;


int go(int row, int column) {
	if (dp[row][column] == -1) {
		return 0;
	}
	if (dp[row][column] > 0) {
		return dp[row][column];
	}
	int high = arr[row][column];
	int sum = 0;
	if (row > 1 && high > arr[row - 1][column]) {
		sum += go(row - 1, column);
	}
	if (row < n && high > arr[row + 1][column]) {
		sum += go(row + 1, column);
	}
	if (column >1 && high > arr[row][column-1]) {
		sum += go(row, column-1);
	}
	if (column <m && high > arr[row][column + 1]) {
		sum += go(row, column + 1);
	}
	if (sum == 0) {
		dp[row][column] = -1;
		return 0;
	}
	else {
		dp[row][column] = sum;
		return sum;
	}
}

int main(void) {

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}

	dp[n][m] = 1;
	cout << go(1, 1);

}