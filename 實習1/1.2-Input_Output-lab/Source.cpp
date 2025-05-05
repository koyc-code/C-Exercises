#include <iostream>
#include <string>
using namespace std;

int main() {
	string  input;
	while (cin >> input) {
		int digit = input.size();
		if (digit < 10) {
			int space_num = 10 - digit;
			for (int i = 0; i < space_num; i++) {
				cout << " ";
			}
		}
		cout << input << endl;
	}
}