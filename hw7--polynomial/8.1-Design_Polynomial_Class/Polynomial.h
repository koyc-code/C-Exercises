#pragma once
#include <iostream>
class Polynomial {
private:
	int size;
	double *coef = NULL; 
public:
	Polynomial();
	Polynomial(int size);
	Polynomial(double* param, int size);
	~Polynomial();
	Polynomial(const Polynomial & poly);

	int mySize();
	friend double evaluate(const Polynomial& poly, const double& var);

	//operator
	void operator=(const Polynomial& poly);
	double& operator[](int pow);
	Polynomial operator+(Polynomial poly) ;
	friend Polynomial operator+(Polynomial poly, double n);
	friend Polynomial operator+(double n , Polynomial poly);
	Polynomial operator-(Polynomial poly);
	friend Polynomial operator-(Polynomial poly, double n);
	friend Polynomial operator-(double n, Polynomial poly);
	Polynomial operator*(Polynomial poly);
	friend Polynomial operator*(Polynomial poly, double n);
	friend Polynomial operator*(double n, Polynomial poly);

 };
