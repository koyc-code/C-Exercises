#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	float income,tax;
	while (cin >> income) {
		if (income <= 750.0) tax = income * 0.01;
		else if (income > 750.0&&income <= 2250) tax = (income-750) * 0.02 + 7.5;
		else if (income > 2250.0&&income <= 3750) tax = (income-2250) * 0.03 + 37.5;
		else if (income > 3750.0&&income <= 5250) tax = (income-3750) * 0.04 + 82.5;
		else if (income > 5250.0&&income <= 7000) tax = (income-5250) * 0.05 + 142.5;
		else if (income > 7000) tax = (income-7000) * 0.06 + 230.0;
		cout <<fixed<<setprecision(2)<< tax<<endl;
	}
    return 0;
}