#include "Polynomial.h"
#include <iostream>
using namespace std;
int main()
{
	Polynomial empty;
	double one[] = { 1 };
	Polynomial One(one, 1);
	double quad[] = { 3, 2, 1 };
	double cubic[] = { 1, 2, 0, 3 };
	Polynomial q(quad, 3); // q is 3 + 2*x + x*x
	Polynomial c(cubic, 4);// c is 1 + 2*x + 0*x*x + 3*x*x*x
	Polynomial p = q;  // test copy constructor
	cout << "p = q" << endl;
	/*for (int i = 0; i < p.mySize(); i++)
		cout << "term with degree " << i << " has coefficient " << p[i] << endl;
	for (int i = 0; i < q.mySize(); i++)
		cout << "term with degree " << i << " has coefficient " << q[i] << endl;*/
	Polynomial r;
	r = q;             //test operator=
	r = c;
	cout << "*********************" << endl;

	cout << "Polynomial q " << endl;
	
	cout << "Polynomial c " << endl;
	

	cout << "value of q(2) is " << evaluate(q, 2) << endl;
	cout << "value of p(2) is " << evaluate(p, 2) << endl;
	cout << "value of r(2) is " << evaluate(r, 2) << endl;
	cout << "value of c(2) is " << evaluate(c, 2) << endl;
	cout << "*********************" << endl;
	r = q + c;
	/*for (int i = 0; i < r.mySize(); i++)
		cout << "term with degree " << i << " has coefficient " << r[i] << endl;*/
	cout << "value of (q + c)(2) is " << evaluate(r, 2) << endl;
	cout << "*********************" << endl;
	r = q - c;
	for (int i = 0; i < r.mySize(); i++)
		cout << "term with degree " << i << " has coefficient " << r[i] << endl;
	cout << "value of (q - c)(2) is " << evaluate(r, 2) << endl;
	cout << "*********************" << endl;
	r = q * c;
	cout << "size of q*c is " << r.mySize() << endl;
	cout << "Polynomial r (= q*c) " << endl;
	cout << "*********************" << endl;
	for (int i = 0; i < r.mySize(); i++)
		cout << "term with degree " << i << " has coefficient " << r[i] << endl;
	cout << "*********************" << endl;
	cout << "value of (q * c)(2) is " << evaluate(r, 2) << endl;
	return 0;
}
