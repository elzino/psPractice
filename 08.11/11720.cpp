#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	string query;
	cin >> query;

	int sum = 0;;

	for (int i = 0; i < n; i++) {
		sum += query.at(i) - 48;
	}
	cout << sum;
}