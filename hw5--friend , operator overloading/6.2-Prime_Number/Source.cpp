#include <iostream>
#include "PrimeNumber.h"
using namespace std;


PrimeNumber::PrimeNumber() {
	value = 1;
}
PrimeNumber::PrimeNumber(int _value) {
	value = _value;
}
int PrimeNumber::get() {
	return value;
}
PrimeNumber& PrimeNumber::operator++() {//++x
	this->value+=1;
	while (_isPrime(this->value) != true) {
		this->value+=1;
	}
	return *this;
}
PrimeNumber PrimeNumber::operator++(int) {//x++
	PrimeNumber temp = *this;
	++ *this;
	return temp;
}
PrimeNumber& PrimeNumber::operator--() {
	this->value-=1;
	while (_isPrime(this->value) != true) {
		this->value-=1;
	}
	return *this;
}
PrimeNumber PrimeNumber::operator--(int) {
	PrimeNumber temp = *this;
	-- *this;
	return temp;
}

bool PrimeNumber::_isPrime(int n) {
	if (n == 1) return true;
	else if (n < 2) return false;
	else {
		for (int i = 2; i < n; i++) {
			if (n%i == 0) return false;
		}
		return true;
	}
}