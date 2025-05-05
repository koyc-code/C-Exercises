#include <iostream>
#define PI 3.14159265358979323846
#include <iomanip>
using namespace std;

int main() {
	double r;
	double vol;
	while (cin >> r) {
		vol = 4.0*PI*r*r*r / 3.0;
		cout << PI;
		cout << fixed<<setprecision(6)<<vol<<endl;
	}
    return 0;
}