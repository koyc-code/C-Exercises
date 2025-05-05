#pragma once
#include <vector>
#include<iostream>
using namespace std;
class VecNf {
	
	vector<float> vec;
public:
	VecNf() {
		vec.push_back(0);
	}
	VecNf(float *dest, int cnt) {
		for (int i = 0; i < cnt; i++) {
			vec.push_back(dest[i]);
		}
	}
	VecNf(const VecNf& rhs) {
		vec = rhs.vec;//?
	}
	void operator=(const VecNf& rhs) {
		cout << "ASSIGNMENT!!!" << endl;
		vec = rhs.vec;
	}
	float& operator[](int n) {
		return vec[n];
	}
	friend VecNf operator+(VecNf v1, VecNf v2) {
		VecNf temp;
		if (v1.vec.size() != v2.vec.size()) {
			cout << "dimensions inconsistent" << endl;
			return temp;
		}
		temp.vec.clear();//*************
		for (int i = 0; i < v1.vec.size(); i++) {
			float num = v1.vec[i] + v2.vec[i];
			temp.vec.push_back(num);
		}
	}
	friend VecNf operator-(VecNf v1, VecNf v2) {
		VecNf temp;
		if (v1.vec.size() != v2.vec.size()) {
			cout << "dimensions inconsistent" << endl;
			return temp;
		}
		temp.vec.clear();//***********
		for (int i = 0; i < v1.vec.size(); i++) {
			float num = v1.vec[i] - v2.vec[i];
			temp.vec.push_back(num);
		}
	}
	float operator*(VecNf v) {
		float n=0;
		if (vec.size() != v.vec.size()) {
			cout << "dimensions inconsistent" << endl;
			return 0;
		}
		for (int i = 0; i < v.vec.size(); i++) {
			n += vec[i] * v.vec[i];
		}
		return n;
	}
	friend VecNf operator*(VecNf v, float n) {
		for (int i = 0; i < v.vec.size(); i++) {
			v.vec[i] *= n;
		}
		return v;
	}
	friend VecNf operator*(float n , VecNf v) {
		for (int i = 0; i < v.vec.size(); i++) {
			v.vec[i] *= n;
		}
		return v;
	}
	int Size() {
		return vec.size();
	}
};