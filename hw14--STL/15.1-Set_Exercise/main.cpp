#include <iostream>
#include <set>
#include <fstream>
#include <string>
using namespace std;

int main() {
	fstream fp;
	fp.open("name.txt", ios::in);
	set<string> names;
	string name;
	while (getline(fp, name)) {
		names.insert(name);
	}
	set<string>::iterator p;
	for (p = names.begin(); p != names.end();p++) {
		cout << *p << endl;

	}
    return 0;
}