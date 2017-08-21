#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	int num[10][101];

	num[0][1] = 0;
	for (int i = 1; i < 10; i++) {
		num[i][1] = 1;
	}
	for (int i = 2; i <= n; i++) {
		num[0][i] = num[1][i - 1];
		for (int j = 1; j < 9; j++) {
			num[j][i] = (num[j - 1][i - 1] + num[j + 1][i - 1])% 1000000000;
		}
		num[9][i] = num[8][i-1];
	}
	int sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += num[i][n];
		sum %= 1000000000;
	}
	cout << sum;

}