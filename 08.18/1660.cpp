#include <iostream>

using namespace std;

int arr[122];
int dp[300001];


int go(int x) {
	if (x == 0) {
		return 0;
	}
	if (dp[x] > 0)
		return dp[x];
	int min = 300001;
	int i = 1;
	int temp = arr[i];
	while (x >= temp) {
		if (min > go(x - temp) + 1) {
			min = go(x - temp) + 1;
		}
		i++;
		temp = arr[i];
	}
	dp[x] = min;
	return min;
}

int main(void) {
	int n;
	cin >> n;
	for (int i = 1; i <= 121; i++) {
		arr[i] = i*(i + 1)*(i + 2) / 6;
	}
	cout << go(n);
}