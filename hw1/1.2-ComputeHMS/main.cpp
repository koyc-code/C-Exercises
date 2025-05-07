#include <iostream>
using namespace std;

int main() {
	unsigned long long int num, hour, min, sec;
	while (cin>>num) {
		hour = num / 3600;
		min = num % 3600 / 60;
		sec = num % 3600 % 60;
		cout << hour << " hours " << min << " minutes and " << sec << " seconds" << endl;
	}

    return 0;
}