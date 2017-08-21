#include <iostream>
#include <string>
#include <stack>

using namespace std;

int arr[1002][1002];
int dp[1002][1002];

int main(void) {
	string a;
	string b;

	cin >> a;
	cin >> b;
	int n = a.length();
	int m = b.length();

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (a.at(j - 1) == b.at(i - 1)) {
				arr[i][j] = arr[i - 1][j - 1] + 1;
				dp[i][j] = 1;	//대각선
			}
			else {
				if (arr[i - 1][j] < arr[i][j - 1]) {
					arr[i][j] = arr[i][j - 1];
					dp[i][j] = 2; //왼쪽
				}
				else {
					arr[i][j] = arr[i - 1][j];
					dp[i][j] = 3; //위쪽
				}
			}
		}
	}
	cout << arr[m][n] << endl;
	stack<char> temp;
	while (m > 0 && n > 0) {
		if (dp[m][n] == 1) {
			m--; n--;
			temp.push(a.at(n));
		}
		else if(dp[m][n]==2){
			n--;
		}
		else if(dp[m][n]==3){
			m--;
		}
		else if (dp[m][n] == 0) {
			cout << "error" << endl;
		}
	}
	while (!temp.empty()) {
		cout << temp.top();
		temp.pop();
	}

}