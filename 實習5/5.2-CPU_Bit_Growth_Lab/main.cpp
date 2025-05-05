#include <iostream>
#include <math.h>
using namespace std;

int main() {
	/*
	input year
	max = 2^k -1 ---------- k = 4*2^{(year - 1900) / 10}
	output the max N --- N! <= max
	n!<=2^k-1;
	*/
	int year;
	while (cin >> year) {
		long double logNfac = 0;
		long double logMax = 4 * log10(2);//log Max  =  log (2^4) = 4* log 2
		int times = (year - 1900) /10;
		for (int i = 0; i < times; i++) {
			logMax *= 2;
		}
		int result=0;
		for (int i = 1; ; i++) {
			logNfac+= log10(i);
			if (logNfac > logMax) {
				result = i - 1;
				break;
			}
		}
		cout << result << endl;

	}
    return 0;
}