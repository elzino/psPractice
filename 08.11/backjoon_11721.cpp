#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string temp;
	cin >> temp;
	int length = temp.length();
	int quotion = length / 10;
	int remainder = length % 10;
	for (int i = 0; i < quotion; i++) {
		cout<<temp.substr(10 * i, 10);
		cout << endl;
	}
	if (remainder != 0) {
		cout<<temp.substr(10 * quotion, remainder);
	}


}