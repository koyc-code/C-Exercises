#include <iostream>
#include <string>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	string input;
	int num;
	while (getline(cin, input)) {
		cin >> num;
		cout << num << endl;
	}
	return 0;
}
