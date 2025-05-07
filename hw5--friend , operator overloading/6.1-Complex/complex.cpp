#include <iostream>
#include "Complex.h"
#include <math.h>
using namespace std;

Complex::Complex() {
	realValue = 0;
	imaginaryValue = 0;
}
Complex::Complex(double r) {
	realValue = r;
	imaginaryValue = 0;
}
Complex::Complex(double r, double i) {
	realValue = r;
	imaginaryValue = i;
}
double Complex::real() {
	return realValue;
}
double Complex::imag() {
	return imaginaryValue;
}
double Complex::norm() {
	return sqrt(pow(realValue, 2) + pow(imaginaryValue, 2));
}
double real(Complex c) {
	return c.realValue;
}
double imag(Complex c) {
	return c.imaginaryValue;
}
double norm(Complex c) {
	double r, i;
	r = c.realValue; i = c.imaginaryValue;
	return sqrt(pow(r, 2) + pow(i, 2));
}

Complex Complex::operator+(Complex c) {
	Complex _complex;
	_complex.realValue = this->realValue + c.realValue;
	_complex.imaginaryValue = this->imaginaryValue + c.imaginaryValue;
	return _complex;
}
Complex Complex::operator-(Complex c) {
	Complex _complex;
	_complex.realValue = this->realValue - c.realValue;
	_complex.imaginaryValue = this->imaginaryValue - c.imaginaryValue;
	return _complex;
}
Complex Complex::operator*(Complex c) {
	Complex _complex;
	_complex.realValue = this->realValue*c.realValue - this->imaginaryValue*c.imaginaryValue;
	_complex.imaginaryValue = this->realValue*c.imaginaryValue + this->imaginaryValue*c.realValue;
	return _complex;
}
Complex Complex::operator/(Complex c) {
	Complex _complex;
	_complex.realValue = (this->realValue*c.realValue +this->imaginaryValue*c.imaginaryValue)/ pow(c.realValue, 2) + pow(c.imaginaryValue, 2);
	_complex.imaginaryValue =( this->imaginaryValue*c.realValue - this->realValue*c.imaginaryValue )/ pow(c.realValue, 2) + pow(c.imaginaryValue, 2);
	return _complex;
}

Complex operator+(double d, Complex c) {
	Complex _complex;
	_complex.realValue = d + c.realValue;
	_complex.imaginaryValue = c.imaginaryValue;
	return _complex;
}
Complex operator-(double d, Complex c) {
	Complex _complex;
	_complex.realValue = d - c.realValue;
	_complex.imaginaryValue = c.imaginaryValue;
	return _complex;
}
Complex operator*(double d, Complex c) {
	Complex _complex;
	_complex.realValue = d * c.realValue;
	_complex.imaginaryValue = d * c.imaginaryValue;
	return _complex;
}
Complex operator/(double d, Complex c) {
	Complex _complex;
	_complex.realValue = d / c.realValue;
	_complex.imaginaryValue = d / c.imaginaryValue;
	return _complex;
}
bool operator==(Complex c1, Complex c2) {
	if (c1.realValue == c2.realValue && c1.imaginaryValue == c2.imaginaryValue) return true;
	else return false;
}
ostream& operator<<(ostream &strm, const Complex &c) {
	strm << c.realValue<<" + "<<c.imaginaryValue<<"*i"<<endl;
	return strm;
}
istream& operator>>(istream &strm, Complex &c) {
	strm >> c.realValue >>(char*) " + " >> c.imaginaryValue >> (char*)"*i";
	return strm;
}
