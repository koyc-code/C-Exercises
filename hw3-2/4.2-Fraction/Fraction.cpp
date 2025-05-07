#include "Fraction.h"

int find_gcd(int a, int b);
void Fraction::setNumerator(int nu)
{
	numerator = nu;
}

void Fraction::setDenominator(int de)
{
	denominator = de;
}

void Fraction::getDouble()
{
	double result;
	result = (double)numerator /(double) denominator;
	cout << fixed << setprecision(6) << result;
}

void Fraction::outputReducedFraction()
{
	int gcd;
	gcd = find_gcd(numerator, denominator);
	if (gcd == 0) cout << numerator << "/" << denominator;
	else {
		numerator /= gcd; denominator /= gcd;
		cout << numerator << "/" << denominator;
	}
}

int find_gcd(int a, int b) {
	if (b ==0 ) return b ;
	else return (b, a%b);
}

