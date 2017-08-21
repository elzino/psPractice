#include <iostream>

using namespace std;
int arr[31];


int tile(int n) {
	if (arr[n] > 0) {
		return arr[n];
	}
	int temp = n;
	int sum = 0;
	temp -= 2;
	sum += tile(n - 2) * 3;
	temp -= 2;
	while (temp >= 0) {
		sum += 2 * tile(temp);
		temp -= 2;
	}
	arr[n] = sum;
	return sum;
	
}


int main(void) {
	int n;
	cin >> n;

	if (n % 2 == 1) {
		cout << 0;
		return 0;
	}
	arr[0] = 1;

	cout << tile(n);


}