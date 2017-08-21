#include <iostream>
#include <string>

using namespace std;

int arr[1002][1002];

int main(void) {
	string a;
	string b;

	cin >> a;
	cin >> b;
	int n = a.length();
	int m = b.length();

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (a.at(j-1)==b.at(i-1)) {
				arr[i][j] = arr[i - 1][j - 1] + 1;
			}
			else {
				if (arr[i - 1][j] < arr[i][j - 1]) {
					arr[i][j] = arr[i][j - 1];
				}
				else {
					arr[i][j] = arr[i-1][j];
				}
			}
		}
	}
	cout << arr[m][n];

}