#include <iostream>
#include <string>

using namespace std;

char arr[2001];
int dp[2001][2001];

int main(void) {
	int n;
	string line;
	cin >> line;
	n =  line.length();
	for (int i = 1; i <= n; i++) {
		arr[i] = line.at(i - 1);
	}
	for (int i = 1; i <= n; i++) {
		dp[0][i] = 1;
		dp[1][i] = 1;
	}
	for (int i = 2; i <= n ; i++){
		for (int j = 1; j <= n - i +1; j++) {
			if (arr[j] == arr[j + i -1] && dp[i - 2][j+1] == 1) {
				dp[i][j] = 1;
			}
		}
	}
	for (int i = n; i >=1 ; i--) {
		if (dp[i][n-i+1] == 1) {
			cout <<2 * n - i;
			return 0;
		}	
	}
	return 0;
}