#include <string>
#include <iostream>
using namespace std;

class Atoi {

private:
	string beTrans;
	
public:
	Atoi() {
		beTrans = "";
	}
	Atoi(string s) {
		beTrans = s;
	}
	void SetString(string s) {
		beTrans = s;
	}
	const string GetString() {
		return beTrans;
	}
	int Length() {
		if (beTrans[0] == '-')   return beTrans.length()-1;
		else  return beTrans.length();
	}
	bool IsDigital() {
		if (beTrans[0] == '-') {
			for (int i = 1; i < beTrans.length(); i++) {
				if (!isdigit(beTrans[i])) return false;
			}
		}
		else {
			for (int i = 0; i < beTrans.length(); i++) {
				if (!isdigit(beTrans[i])) return false;
			}
		}
		return true;
	}
	int StringToInteger() {
		int integer=0;
		if (beTrans[0] == '-') {
			for (int i = 1; i < beTrans.length(); i++) {
				integer = integer * 10 + beTrans[i] - '0';
			}
			integer *= -1;
		}
		else {
			for (int i = 0; i < beTrans.length(); i++) {
				integer = integer * 10 + beTrans[i] - '0';
			}
		}
		return integer;
	}

};