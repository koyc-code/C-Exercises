#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
void printnumber_1(int num);
void printnumber_2(int num);
void printnumber_3(int num);
int main() {
	string input_s;
	while (getline(cin, input_s)) {

		for (int i = 0; i < input_s.length(); i++) {
			if (isdigit(input_s[i])) 	printnumber_1(input_s[i]);
		}
		puts("");
		for (int i = 0; i < input_s.length(); i++) {
			if (isdigit(input_s[i])) 	printnumber_2(input_s[i]);
		}
		puts("");
		for (int i = 0; i < input_s.length(); i++) {
			if (isdigit(input_s[i]))	printnumber_3(input_s[i]);
		}
		puts("");
	}
    return 0;
}
void printnumber_1(int num) {
	num -= '0';
	switch (num) {
	case 0:
		cout << " " << "_" << " "; break;
	case 1:
		cout << " " << " " << " "; break;
	case 2:
		cout << " " << "_" << " "; break;
	case 3:
		cout << " " << "_" << " "; break;
	case 4:
		cout<< " " << " " << " "; break;
	case 5:
		cout<< " " << "_" << " "; break;
	case 6:
		cout << " " << "_" << " "; break;
	case 7:
		cout << " " << "_" << " "; break;
	case 8:
		cout << " " << "_" << " "; break;
	case 9:
		cout << " " << "_" << " "; break;
	default:
		cout << "wrong input :" <<num<< endl;
	}
}
void printnumber_2(int num) {
	num -= '0';
	switch (num) {
	case 0:
		cout << "|" << " " << "|"; break;
	case 1:
		cout << " " << " " << "|"; break;
	case 2:
		cout << " " << "_" << "|"; break;
	case 3:
		cout<< " " << "_" << "|"; break;
	case 4:
		cout << "|" << "_" << "|"; break;
	case 5:
		cout << "|" << "_" << " "; break;
	case 6:
		cout << "|" << "_" << " "; break;
	case 7:
		cout << " " << " " << "|"; break;
	case 8:
		cout << "|" << "_" << "|"; break;
	case 9:
		cout << "|" << "_" << "|"; break;
	}
}
void printnumber_3(int num) {
	num -= '0';
	switch (num) {
	case 0:
		cout << "|" << "_" << "|"; break;
	case 1:
		cout << " " << " " << "|"; break;
	case 2:
		cout << "|" << "_" << " "; break;
	case 3:
		cout << " " << "_" << "|"; break;
	case 4:
		cout << " " << " " << "|"; break;
	case 5:
		cout << " " << "_" << "|"; break;
	case 6:
		cout << "|" << "_" << "|"; break;
	case 7:
		cout << " " << " " << "|"; break;
	case 8:
		cout << "|" << "_" << "|"; break;
	case 9:
		cout << " " << "_" << "|"; break;
	}
}