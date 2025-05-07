#include <iostream>
using namespace std;
class position {
	int x, y;
public:
	position(int x, int y)
		: x(x), y(y) {}
	//test operator overloading
	friend position operator/(int x,position pos) {
		position pos1;
		pos1.x = pos.xx;
		pos1.y = x;
		return pos1;
	}
	void get() {
		cout << x << " " << y << endl;
	}
};
int main() {
	position pos(1,2), pos3;
	pos3 = pos / 3;
	pos3.get;
	pos3 = 3 / pos;
	pos3.get;
}