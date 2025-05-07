#pragma once
#include <iostream>
#include <string>
using namespace std;
class Document {
private:
	string text;
public:
	Document() {
		text = "";
	}
	Document(string text) {
		this->text = text;
	}
	void operator=(Document rhs) {
		this->text = rhs.text;
	}
	void setText(string text) {
		this->text = text;
	}
	string getText () const { //????????
		return this->text;
	}
};