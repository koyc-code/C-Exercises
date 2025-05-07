#include <iostream>
using namespace std;
class Point {
public:
	int vertical=0;
	int horizontal=0;
	void Set(int a, int b) {
		point.vertical = a;
		point.horizontal = b;
	}
	void move(int a, int b) {
		point.vertical += a;
		point.horizontal += b;
	}
	//void rotate(int a, int b);
}point;
int main(void) {
	cout << point.vertical << " " << point.horizontal << endl;
    point.Set(0, 5);
	cout << point.vertical << " " << point.horizontal << endl;

	point.move(1, 2);
	cout << point.vertical << " " << point.horizontal << endl;
	/*for (int i = 0; i < 4; i++) {
		point.Rotate();
		cout << point.vertical << " " << point.horizontal << endl;
	}*/

	return 0;
}

