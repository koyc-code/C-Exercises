#pragma once
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
using namespace std;
class VecNf {
	int size=1;
	float* coef = NULL;
	
public:
	VecNf() {
		size = 1;
		coef = (float*)malloc(sizeof(float)*size);
		memset(coef, 0, size*sizeof(float));
	}
	VecNf(int size) {
		this->size = size;
		coef = (float*)malloc(sizeof(float)*size);
		memset(coef, 0, size * sizeof(float));    //necessary??????????
	}
	VecNf(float *dest, int cnt) {
		this->size = cnt;
		this->coef = (float*)malloc(sizeof(float)*size);
		memset(coef, 0, size * sizeof(float));  //necessary??????????
		
		for (int i = 0; i < cnt; i++) {
			*(coef + i) = dest[i];
		}
	}
	~VecNf() {

	}
	VecNf(const VecNf& rhs) {   //rhs , const + &??????????
		this->size = rhs.size;
		this->coef = (float*)malloc(sizeof(float)*size);
		memset(this->coef, 0, this->size * sizeof(float));  //necessary??????????
		for (int i = 0; i < size; i++) {
			*(this->coef + i) = rhs.coef[i];
		}
	}
	void operator= (const VecNf& rhs) {
		cout << "ASSIGNMENT!!!" << endl;
		VecNf temp(rhs);
		this->size = rhs.size;
		this->coef = (float*)malloc(sizeof(float)*this->size);
		memset(this->coef, 0, this->size * sizeof(float));  //necessary??????????
		for (int i = 0; i < size; i++) {
			*(coef + i) = temp.coef[i];
		}
	}
	float& operator[](int dimension) {
		if (dimension >= size) {
			cout << "out of range" << endl;
		}
		else {
			float value;
			return coef[dimension];
			
		}
	}
	VecNf operator+(VecNf vec) { //if no return?????????
		if (this->size != vec.size) {
			cout<<"dimensions inconsistent" << endl;
			VecNf result(1);
			return result;
		}
		VecNf result(this->size);
		for (int i = 0; i < this->size; i++) {
			result.coef[i] = this->coef[i] + vec.coef[i];
		}
		return result;
	}
	VecNf operator-(VecNf vec) {
		if (this->size != vec.size) {
			cout << "dimensions inconsistent" << endl;
			VecNf result(1);
			return result;
		}
		VecNf result(this->size);
		for (int i = 0; i < this->size; i++) {
			result.coef[i] = this->coef[i] - vec.coef[i];
		}
		return result;
	}
	float operator*(VecNf vec) {
		if (this->size != vec.size) {
			cout << "dimensions inconsistent" << endl;
			return 0;
		}
		float value=0;
		for (int i = 0; i < this->size; i++) {
			value += this->coef[i] * vec.coef[i];
		}

		return value;
	}
	VecNf operator*(float num) {
		VecNf result(this->coef,this->size);
		for (int i = 0; i < size; i++) {
			result.coef[i] *= num;
		}
		return result;
	}
	friend VecNf operator*(float num, VecNf vec) {
		VecNf result(vec.coef, vec.size);
		for (int i = 0; i < result.size; i++) {
			result.coef[i] *= num;
		}
		return result;
	}
	int Size() {
		return size;
	}
	
	//friend ostream& operator<<(ostream &strm, VecNf vec);
};

//ostream&  operator<<(ostream &strm, const VecNf& vec) {  //const &??????????
//	strm <<
//}