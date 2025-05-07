#include <iomanip>
#include <iostream>
using namespace std;

int main() {
	double result;
	result = 2.0 / 3.0;
	cout << fixed << setprecision(6) << result;
}