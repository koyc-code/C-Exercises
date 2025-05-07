#include "Month.h"
#include <iostream>
using namespace std;


Month::Month()
{
	month = 1;
}

Month::Month(char first, char second, char third)
{
	month = WhichMonth(first, second, third);
}

Month::Month(int monthInt)
{
	if (monthInt>0&&monthInt<13) month = monthInt;
	else month = 1;

}


Month::~Month()
{

}

void Month::inputInt()
{
	int temp;
	cin >> temp;
	if (temp > 0 && temp < 13) month = temp;
	else month = 1;
}

void Month::inputStr()
{
	char first,second,third;
	cin >> first >> second >> third ;
	month = WhichMonth(first, second, third);
}

void Month::outputInt()
{
	cout << month;
}

void Month::outputStr()
{
	switch (month) {
	case 1: cout << "Jan"; break;
	case 2: cout << "Feb"; break;
	case 3: cout << "Mar"; break;
	case 4: cout << "Apr"; break;
	case 5: cout << "May"; break;
	case 6: cout << "Jun"; break;
	case 7: cout << "Jul"; break;
	case 8: cout << "Aug"; break;
	case 9: cout << "Sep"; break;
	case 10: cout << "Oct"; break;
	case 11: cout << "Nov"; break;
	case 12: cout << "Dec"; break;
	}
}

Month Month::nextMonth()
{
	int nextMonth;
	nextMonth = month + 1;
	if (nextMonth == 13) nextMonth = 1;
	
	return Month(nextMonth);
}

int Month::WhichMonth(char f, char s, char t)
{
	if (f == 'J' && s == 'a' &&t == 'n')
		return 1;
	else if (f == 'F' && s == 'e' &&t == 'b')
		return 2;
	else if (f == 'M' && s == 'a' &&t == 'r')
		return 3;
	else if (f == 'A' && s == 'p' &&t == 'r')
		return 4;
	else if (f == 'M' && s == 'a' &&t == 'y')
		return 5;
	else if (f == 'J' && s == 'u' &&t == 'n')
		return 6;
	else if (f == 'J' && s == 'u' &&t == 'l')
		return 7;
	else if (f == 'A' && s == 'u' &&t == 'g')
		return 8;
	else if (f == 'S' && s == 'e' &&t == 'p')
		return 9;
	else if (f == 'O' && s == 'c' &&t == 't')
		return 10;
	else if (f == 'N' && s == 'o' &&t == 'v')
		return 11;
	else if (f == 'D' && s == 'e' &&t == 'c')
		return 12;
	else
		return 1;
	return 0;
}
