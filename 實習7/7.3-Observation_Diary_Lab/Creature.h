#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct bodyPart {
	string partName;
	int number;
	//constructor
	bodyPart(string name) {
		partName = name;
		number = 0;
	}
	void operator= (int num) {
		number = num;
	}
	void operator += (int num) { //??????? 
		if (number != NULL) number += num;
		else number = num;
	}
	void operator-=(int num) {
		if (number != NULL) number -= num;
		else number = -1;
		if (number < 0) cout << "negative number(-=)" << endl;
	}
};
class Creature {
	string name;
	vector<bodyPart> parts;
public:
	//constructor
	Creature() {
		name = "";
		parts.clear();
	}
	Creature(string name) {
		this->name = name;
		parts.clear();
	}
	
	Creature(string name, Creature base) {
		*this = base;   //?????????
		this->name = name;
	}
	//destructor
	~Creature() {
		parts.clear(); //is it clear?????????? if each struct contains pointer..?
	}
	//copy constructor
	Creature(const Creature & rhs) {
		this->name = rhs.name;
		this->parts = rhs.parts; // available????
	}
	//overloading [],=,+=,-=
	bodyPart& operator[](string name) {
		int pos = find_part(name);
		if (pos != -1)	return parts[pos];
		else {
			this->parts.push_back(bodyPart(name));//using constructor to push back.
			return parts[parts.size() - 1];
		}
	}
	
	int find_part(string part_name) {
		for (int i = 0; i < parts.size(); i++) {
			if (parts[i].partName == part_name) return i;
		}
		return - 1;
	}

	//functions : PrintStatus() and PrintLog()
	void PrintStatus() {
		for (int i = 0; i < parts.size(); i++) {
			cout << parts[i].partName << " * " << parts[i].number << endl;
		}
	}
	void PrintLog() {

	}
};
