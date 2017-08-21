#include <iostream>

using namespace std;

int arr[12];

int way(int num) {
	if (num == 1) {
		return 1;
	}
	if (num == 2) {
		return 2;
	}
	if (num == 3) {
		return 4;
	}
	if (arr[num] > 0) {
		return arr[num];
	}
	arr[num] = way(num - 1) + way(num-2) + way(num-3);
	return arr[num];
}


int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		cout<<way(temp)<<endl;
	}
}