#include <iostream>

using namespace std;

unsigned long long arr[101];

unsigned long long tri(int n) {
	if (arr[n] > 0) {
		return arr[n];
	}
	arr[n] = tri(n - 1) + tri(n - 5);
	return arr[n];
}

int main(void) {
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;
	arr[4] = 2;
	arr[5] = 2;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		cout << tri(temp) << endl;
	}


}