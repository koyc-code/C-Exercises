#pragma once
#include <stdio.h>
template<typename T>
//char??????????
double absoluteValue(T n1, T n2) {
	double result;
	( n1 - n2 > 0 ) ? ( result =  n1 - n2):( result = n2 - n1);
	return result;
}