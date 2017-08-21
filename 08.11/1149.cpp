#include <iostream>
#include <algorithm>

using namespace std;

int* red;
int* blue;
int* green;


int main(void) {
	int n;
	cin >> n;
	
	red = new int[n];
	blue = new int[n];
	green = new int[n];

	int a, b, c;
	

	cin >> a >> b >> c;
	

	red[0] = a;
	blue[0] = b;
	green[0] = c;

	for (int i = 1; i < n; i++) {
		cin >> a >> b >> c;
		

		if (blue[i - 1] < green[i - 1]) {
			red[i] = a + blue[i - 1];
		}
		else {
			red[i] = a + green[i - 1];

		}

		if (red[i - 1] < green[i - 1]) {
			blue[i] = b + red[i - 1];
		}
		else {
			blue[i] = b + green[i - 1];

		}

		if (blue[i - 1] < red[i - 1]) {
			green[i] = c + blue[i - 1];
		}
		else {
			green[i] = c + red[i - 1];

		}

	}

	cout << min(min(red[n - 1], blue[n - 1]), green[n - 1]);

}