#pragma once
#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
//„«	void SetInput(int) : set the given integer A.
//„«	void ProcessInput() : splitting the integer A into several digits.
//„«	void SetFileName(string) : set the file name of the file where list S is located.
//„«	void LoadNumberList() : read list S from the file.
//„«	void PrintAllValid() : print all the valid numbers in S ascendingly
//„«	void Reset() : reset all variables.
class NumberGame {
public:
	unsigned long long int number;
	vector<int> digit;
	vector<unsigned long long int> match;
	fstream file;

	NumberGame() {
		number = 0;
		digit.clear();
		match.clear();
		//file???
	}

	void SetInput(unsigned long long int n) {
		number = n;
	}
	void ProcessInput() {
		unsigned long long int temp = number;
		int _digit;
		while (temp!=0) {
			_digit = temp % 10;
			digit.push_back(_digit);
			temp /= 10;
		}
		for (int i = 0; i < digit.size(); i++) {
			for (int j = 1; j < digit.size(); j++) {
				if (digit[j] > digit[j - 1]) {
					temp = digit[j];
					digit[j] = digit[j - 1];
					digit[j - 1] = temp;
				}
			}
		}
	}
	void SetFileName(string filename) {
		this->file.open(filename, ios::in);
	}
	void LoadNumberList() {
		unsigned long long int temp;
		while (file >> temp) {
			//cout << "*********" << endl;
			unsigned long long int copy = temp;
			bool found = false;
			for (int i = 0; i<digit.size() ; i++) {
				for (int j = i; j < digit.size(); j++) {
					if (digit[j] == 0) continue;
					if (digit[j] == 1 && temp == 1) found = true;
					else if(temp!=1) {
						if (copy % digit[j] == 0) {
							copy /= digit[j];
						}
						if (copy == 1) {
							found = true;
						}
					}
				}
				
				if (found == true ) {
					//add
					match.push_back(temp);
					break;
				}
				copy = temp;
			}
			
			
		}
	}
	void PrintAllValid() {
		for (int i = 0; i < match.size(); i++) {
			cout << match[i] << endl;
		}
	}
	void Reset() {
		digit.clear();
		match.clear();
		file.close();
	}
	
};