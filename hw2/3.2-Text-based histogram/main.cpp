#include <iostream>
using namespace std;

int main() {
	int num;

	int number[6] = { 0 };
	while (cin >> num) {
		switch (num) {
		case 0: number[0] += 1; break;
		case 1: number[1] += 1; break;
		case 2: number[2] += 1; break;
		case 3: number[3] += 1; break;
		case 4: number[4] += 1; break;
		case 5: number[5] += 1; break;
		default: cout << "invalid input. Try again"; continue;
		}
	}
	for (int i = 0; i < 6; i++) {
		cout << number[i] << " grade(s) of " << i << endl;
	}
	
    return 0;
}