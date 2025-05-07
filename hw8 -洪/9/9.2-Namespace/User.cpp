#include "User.h"
#include <string>

using namespace std;
string userName;

bool checkUserName(string userName) {
	if (userName.size() != 8) { return false; }
	for (auto c : userName) {
		if (!isalpha(c)) {
			return false;
		}
	}
	return true;
}

void Authenticate::inputUserName()
{
	cout << "Enter your username (8 letters only)\n";
	cin >> userName;
	if (!checkUserName(userName)) {
		inputUserName();
	}
}

string Authenticate::getUserName()
{
	return userName;
}
