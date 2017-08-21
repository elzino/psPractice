#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int arr[102][102][102];

int main(void) {
	string a;
	string b;
	string c;

	cin >> a;
	cin >> b;
	cin >> c;
	int n = a.length();
	int m = b.length();
	int l = c.length();


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 1; k <= l; k++) {
				if (a.at(i - 1) == b.at(j - 1)&& b.at(j-1)==c.at(k-1)) {
					arr[i][j][k] = arr[i - 1][j - 1][k-1] + 1;
				}
				else {
					arr[i][j][k] = max(max(arr[i - 1][j][k], arr[i][j - 1][k]), arr[i][j][k - 1]);
				}
			}
		}
	}
	cout << arr[n][m][l] << endl;
	

}