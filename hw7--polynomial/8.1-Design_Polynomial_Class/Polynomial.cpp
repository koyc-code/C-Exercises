#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
#include "Polynomial.h"
using namespace std;

Polynomial::Polynomial() {
	size = 1;
	coef = (double*)malloc(sizeof(double)*size);
	memset(coef,0, size * sizeof(double));
	
}
Polynomial::Polynomial(int size) {
	this->size = size;
	coef = (double*)malloc(sizeof(double)*size);
	memset(coef, 0, size * sizeof(double));
}
Polynomial::Polynomial(double* param, int size) {
	this->size = size;
	coef = (double*)malloc(sizeof(double)*size);
	memset(coef, 0, size * sizeof(double));
	for (int i = 0; i < size; i++) {
		this->coef[i] = param[i];
	}
	
}
//copy constructor
Polynomial::Polynomial(const Polynomial& poly) {//const
	this->size = poly.size;
	//cout << "copy constructor" << endl;
	this->coef = (double*)malloc(sizeof(double)*(this->size));
	memset(this->coef, 0, sizeof(double) * (this->size));
	for (int i = 0; i < poly.size; i++) {
		//cout << i<<"            "<<poly.coef[i] << endl;
		this->coef[i] =poly.coef[i];
	}
	
}
Polynomial::~Polynomial() {
	//free(coef);
}
int Polynomial::mySize() {
	return size;
}
double evaluate(const Polynomial& poly, const double& var) {
	double value=0;
	for (int i = 0; i < poly.size; i++) {
		double a = *(poly.coef + i);
		double b = pow(var, i);
		value += a * b;
	}
	return value;
}
Polynomial bigger(Polynomial poly1, Polynomial poly2) {  // after defining  copy con~, the return should add &
	if (poly1.mySize() > poly2.mySize()) return poly1;
	else if (poly1.mySize() < poly2.mySize()) return poly2;
	else return poly1;
}
Polynomial smaller(Polynomial poly1, Polynomial poly2) {
	if (poly1.mySize() < poly2.mySize()) return poly1;
	else if (poly1.mySize() > poly2.mySize()) return poly2;
	else return poly1;
}

//operator
void Polynomial :: operator=(const Polynomial& poly) {//   +const!!!!!!!!!!!!!!!!
	this->size = poly.size;
	this->coef = (double*)malloc(sizeof(double)*(poly.size));
	memset(this->coef, 0, sizeof(double)*this->size);
	//this->coef = poly.coef;
	for (int i = 0; i < poly.size; i++) {
		//cout << *((this->coef) + i)<<" "<< *(poly.coef + i)<<endl;
		this->coef[i] = poly.coef[i];

	}
}

double& Polynomial :: operator[](int pow) {
	return *(this->coef + pow);
}
Polynomial Polynomial::operator+(Polynomial poly)  {
	Polynomial B = bigger(*this, poly), S = smaller(*this, poly);
	Polynomial result(B.size);
	for (int i = 0; i < result.size; i++) {
		if (i > S.size-1) *(result.coef + i) = *(B.coef + i);
		else *(result.coef + i) = *(B.coef + i) + *(S.coef + i);
	}
	//cout << "+" << result.size << "¡@" << poly.size;
	return result;
}
 Polynomial operator+(Polynomial poly, double n) {
	Polynomial result(poly.size);
	result = poly;
	*(result.coef ) += n;
	return result;
}
 Polynomial operator+(double n, Polynomial poly) {
	 Polynomial result(poly.size);
	 result = poly;
	 *(result.coef ) += n;
	 return result;
}
 Polynomial Polynomial::operator-(Polynomial poly) {
	 Polynomial B = bigger(*this, poly), S = smaller(*this, poly);
	 Polynomial result(B.size);
	 for (int i = 0; i < result.size; i++) {
		 double a = *(poly.coef + i);
		 double b = *(this->coef + i);
		 if (i>(this->size-1) ) *(result.coef + i) = a*(-1);
		 else if (i > (poly.size - 1)  )  *(result.coef + i) = b;
		 else *(result.coef + i) = b - a;
	 }
	 return result;
}
 Polynomial operator-(Polynomial poly, double n) {
	 Polynomial result(poly.size);
	 result = poly;
	 *(result.coef ) -= n;
	 return result;
}
Polynomial operator-(double n, Polynomial poly) {
	 Polynomial result(poly.size);
	 result = poly;
	 *(result.coef ) -= n;
	 return result;
}
Polynomial Polynomial::operator*(Polynomial poly) {
	int size = this->size + poly.size - 1;
	Polynomial result(size);
	int pos;
	for (int i = 0; i < this->size; i++) {
		pos = i;
		for (int j = 0; j < poly.size; j++) {
			double a = *(this->coef + i);
			double b = *(poly.coef + j);
			*(result.coef + pos ) += a * b;
			pos++;
		}
	}
	return result;
}
Polynomial operator*(Polynomial poly, double n) {
	Polynomial result(poly.size);
	for (int i = 0; i < result.size; i++) {
		*(result.coef + i) = *(poly.coef + i ) * n;
	}
	return result;
}
Polynomial operator*(double n, Polynomial poly) {
	Polynomial result(poly.size);
	for (int i = 0; i < result.size; i++) {
		*(result.coef + i) = *(poly.coef + i) * n;
	}
	return result;
}