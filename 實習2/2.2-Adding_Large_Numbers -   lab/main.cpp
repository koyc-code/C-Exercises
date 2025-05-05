#include <iostream>
#include <string>
using namespace std;

int main() {
	/*
	large number addition:
	1.char array
	2.reverse array&¹ï»ô
	3.add by digit: 
	num1:ch-'0'
	¶i¦ì:if result>10 :result-=10  nextone+=1;
	4.reverse result array
	 */
	int num,temp,place; string str1, str2,result="";
	while (cin >> num) {
		cin >> str1 >> str2;
		cout << str1 << endl << str2<<endl;
		//reverse both string
		for (int i = 0; i < str1.length(); i++) {
			temp = str1[i];
			place = str1.length() - i;
			str1[i] = str1[place];
			str1[place] = temp;
		}
		for (int i = 0; i < str2.length(); i++) {
			temp = str2[i];
			place = str2.length() - i;
			str2[i] = str2[place];
			str2[place] = temp;
		}
		cout << str1 << endl << str2;
		//do math

		
	}

}

