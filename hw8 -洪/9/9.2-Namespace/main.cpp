#include <iostream>
#include "Password.h"
#include "User.h"

using namespace std;
using namespace Authenticate;

int main()
{
	inputUserName();
	inputPassword();
	cout << "Your username is " << getUserName() <<
		" and your password is: " <<
		getPassword() << endl;
	return 0;
}