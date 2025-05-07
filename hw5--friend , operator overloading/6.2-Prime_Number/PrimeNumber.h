#pragma once
class PrimeNumber {
public:
	int value;
	int get();
	PrimeNumber();
	PrimeNumber(int _value);
	PrimeNumber& operator++();//++x
	PrimeNumber operator++(int);//x++
	PrimeNumber& operator--();
	PrimeNumber operator--(int);
	bool _isPrime(int n);
};

