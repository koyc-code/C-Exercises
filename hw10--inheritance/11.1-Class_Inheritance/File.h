#pragma once
#include <iostream>
#include <string>
#include "Document.h"
using namespace std;
class File:public Document {
private:
	string pathname;
public:
	File() {
		pathname = "";
		setText("");//same name????
	}
	File(string text, string pathname) {
		setText(text);
		this->pathname = pathname;
	}
	void operator=(File rhs) {
		setText(rhs.getText());
		this->pathname = rhs.pathname;
	}
	void setPathname(string pathname) {
		this->pathname = pathname;
	}
	string getPathname() {
		return this->pathname;
	}
	
};