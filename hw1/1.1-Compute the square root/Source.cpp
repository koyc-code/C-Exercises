#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	double num, guess, r, prv_guess;
	while (cin >> num) {
		prv_guess = num; //make sure the first statement in while would be true
		guess = num / 2;
		while ((prv_guess - guess) > 0.01) {//make a new guess
			prv_guess = guess;
			r = num / guess;
			guess = (guess + r) / 2;
		}
		cout << fixed<<setprecision(2) << guess << endl;
	}
}