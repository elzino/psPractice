#include <iostream>
#include <string>
#include <queue>

using namespace std;


class Point {
public:
	int x;
	int y;
	int closeness;
	Point() {

	}
	Point(int x, int y, int closeness) {
		this->x = x;
		this->y = y;
		this->closeness = closeness;
	}

};


int main(void) {
	queue<Point *> q;
	int row, column;
	cin >> row >> column;
	string *data = new string[row];
	for (int i = 0; i < row; i++) {
		cin>>data[i];
	}

	Point* first = new Point(0, 0, 1);

	data[0][0] = 0;

	q.push(first);
	while (!q.empty()) {
		Point* temp = q.front();
		q.pop();
		int x = temp->x;
		int y = temp->y;
		int closeness = temp->closeness;
		if (x == row-1 && y == column-1) {
			cout << closeness;
			return 0;
		}
		if (x - 1 >=0&& data[x - 1][y] != '0') {
			Point* in = new Point(x - 1, y, closeness+1);
			data[x - 1][y] = '0';
			q.push(in);
		}
		if (x + 1 < row && data[x+1][y] != '0') {
			Point* in = new Point(x + 1, y, closeness + 1);
			data[x + 1][y] = '0';
			q.push(in);
		}
		if (y - 1 >= 0 && data[x ][y-1] != '0') {
			Point* in = new Point(x, y-1, closeness + 1);
			data[x][y-1] = '0';
			q.push(in);
		}
		if (y + 1 <column && data[x][y+1] != '0') {
			Point* in = new Point(x, y + 1, closeness + 1);
			data[x][y+1] = '0';
			q.push(in);
		}


	}

	system("pause");



}

