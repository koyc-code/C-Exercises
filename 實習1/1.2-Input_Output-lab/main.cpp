#include <iostream>
#include <vector>
using namespace std;
int count_digit(int n);
int main() {
	long long int num;
	while (cin >> num) {
		int  digit;
		//count digit or determine if it's less than 10 digits?
		digit = count_digit(num);
		if (digit < 10) {
			int n_space = 10 - digit;
			for (int i = 0; i < n_space; i++) {
				cout << " ";
			}
			cout << num<<endl;
		}
		else {
			cout << num<<endl;
		}
	}
    return 0;
}

int count_digit(int n) {
	int count = 0;//count will return
	//if it's negative
	if (n < 0) {
		count += 1;
		n *= (-1);//make it positive
	}
	//count digit
	while (n != 0) {
		n /= 10;
		count++;
	}
	return count;
	
}