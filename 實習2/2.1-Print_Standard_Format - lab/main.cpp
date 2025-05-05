#include <iostream>
#include <string>
using namespace std;
int digit_count(unsigned long long int num);
struct employee {
	string name;
	unsigned long long int salary;
	unsigned long long int bonus;
};

int main() {
	struct employee data[100];
	unsigned long long int num;
	while (cin >> num) {//eof??
		for (int i = 0; i < num; i++) {
			cin >> data[i].name;
			cin >> data[i].salary;
			cin >> data[i].bonus;
		}
		//find the max name length:
		int name_max = 0;
		for (int i = 0; i < num; i++) {
			if (data[i].name.length() > name_max) {
				name_max = data[i].name.length();
			}
		}
		//find the max salary length:
		int sal_max = 0;
		for (int i = 0; i < num; i++) {
			int digit = digit_count(data[i].salary);
			if (digit > sal_max) sal_max = digit;
		}
		//find the max bonus length:
		int bon_max = 0;
		for (int i = 0; i < num; i++) {
			int digit = digit_count(data[i].bonus);
			if (digit > bon_max) bon_max = digit;
		}
		for (int i = 0; i < num; i++) {
			//output name
			int space;
			space = name_max - data[i].name.length();
			for (int i = 0; i < space; i++) {
				cout << " ";
			}
			cout << data[i].name << "|";

		
		//output salary
		    int digit = digit_count(data[i].salary);
		    space = sal_max - digit;
			for (int i = 0; i < space; i++) {
				cout << " ";
			}
			cout << "  "<<data[i].salary << "|";
		
		//output bonus
			digit = digit_count(data[i].bonus);
			space = bon_max - digit;
			for (int i = 0; i < space; i++) {
				cout << " ";
			}
			cout << "  "<<data[i].bonus<<endl;
		}
	}
    return 0;
}

int digit_count(unsigned long long int num) {
	int digit = 0;
	while (num) {
		num /= 10;
		digit++;
	}
	return digit;
}