#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int n;
	int temp;
	int one[300];
	int two[300];
	cin >> n;
	if (n == 1) {
		cin >> one[0];
	}
	else if (n == 2) {
		cin >> one[0];
		cin >> one[1];
		one[1] += one[0];
	}
	else {
		cin >> one[0];
		two[0] = one[0];
		cin >> two[1];
		one[1] = one[0] + two[1];

		for (int i = 2; i < n; i++) {
			cin >> temp;
			one[i] = two[i - 1] + temp;
			if (one[i - 2] > two[i - 2]) {
				two[i] = one[i - 2] + temp;
			}
			else {
				two[i] = two[i - 2] + temp;
			}
		}
	}

	cout << max(one[n - 1], two[n - 1]);


}