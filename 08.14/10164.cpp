#include <iostream>


using namespace std;
int n, m, k;


int dp[16][16];

int go(int row, int column) {
	if (dp[row][column] > 0) {
		return dp[row][column];
	}
	int sum = 0;
	if (row < n) {
		sum += go(row + 1, column);
	}
	if (column < m) {
		sum += go(row, column + 1);
	}

	dp[row][column] = sum;
	return sum;
}

int main(void) {
	cin >> n >> m >> k;

	int q = k / m;
	int r = k % m;
	dp[n][m] = 1;
	if (k == 0) {
		cout << go(1, 1);
		return 0;
	}
	else if(r==0){
		r = m;
	}
	else {
		q++;
	}
	
	int circle = go(q, r);
	int start = go(n - q+ 1, m - r + 1);
	cout << circle * start;
	return 0;
	

}