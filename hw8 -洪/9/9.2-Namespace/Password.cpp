#include "Password.h"
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;

string password;

bool checkPassword(string password) {
	if (password.size() < 8) { return false; }
	for (auto c : password) {
		if (!isalpha(c) && !isdigit(c)) {
			return true;
		}
	}
	return false;
}

void Authenticate::inputPassword()
{
	cout << "Enter your password (at least 8 characters and at least one non-letter)\n";
	cin >> password;
	if (checkPassword(password)) {
		inputPassword();
	}

}

string Authenticate::getPassword()
{
	return password;
}
