#include <iostream>

using namespace std;

int arr[2001];
int dp[2001][2001];
bool b[2001][2001];


int go(int s, int e) {
	if (s == e) {
		dp[s][e] = 2;
		return 2;
	}
	if (s + 1 == e&&arr[s] == arr[e]) {
		dp[s][e] = 2;
		return 2;
	}
	if (dp[s][e] > 0) {
		return dp[s][e];
	}
	if (arr[s] == arr[e] && go(s + 1,e - 1) == 2) {
		dp[s][e] = 2;
		return 2;
	}
	dp[s][e] = 1;
	return 1;
}

bool check(int s, int e) {
	int temp = (e - s + 1)/2;
	for (int i = 0; i < temp; i++) {
		if (arr[s + i] != arr[e - i]) {
			return false;
		}
	}
	return true;

}

int main(void) {
	int n, m;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	
	for (int i = 1; i <= n; i++) {
		b[i][i] = true;
		if (arr[i] == arr[i - 1]) {
			b[i - 1][i] = true; 
		} 
	}
	for (int i = 2; i <= n - 1; i++) {
		for(int j = 1; j<=n-i;j++){
			if (arr[j] == arr[j + i] && b[j + 1][j + i - 1]) {
				b[j][j + i] = true;
			}
		}
	}


	cin >> m;
	for (int i = 1; i <= m; i++) {
		int p, q;
		cin >> p >> q;
		cout<<b[p][q]<<endl;
	}
}