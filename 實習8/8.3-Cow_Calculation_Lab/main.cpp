#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
void toChar(string& s) {
	for (int i = 0; i < s.length(); i++) {
		switch (s[i]) {
		case '0':
			s[i] = 'V'; break;
		case '1':
			s[i] = 'U'; break;
		case '2':
			s[i] = 'C'; break;
		case '3':
			s[i] = 'D'; break;
		}
	}
}
string toNum(string s) {
	string s_num;
	for (int i = 0; i < s.length(); i++) {
		switch (s[i]) {
		case 'V':
			s[i] = '0'; break;
		case 'U':
			s[i] = '1'; break;
		case 'C':
			s[i] = '2'; break;
		case 'D':
			s[i] = '3'; break;
		}
	}
	s_num = s;
	return s_num;
}
void do_A(string s1, string& s2) {
	string s1_n = toNum(s1);
	string s2_n = toNum(s2);
	int L1 = s1_n.length();
	int L2 = s2_n.length();
	int Ld = L2 - L1;
	//四進位加法
    reverse(s1_n.begin(),s1_n.end());
	reverse(s2_n.begin(),s2_n.end());
	if (Ld != 0) {
		//swap
		char temp;
		temp = s2_n[L2 - 1];
		s2_n[L2 - 1] = s2_n[L2 - 2];
		s2_n[L2 - 2] = temp;
	}
	for (int i = 0; i < s1_n.length(); i++) {
		s2_n[i] = s1_n[i] + s2_n[i] - '0';
		if (s2_n[i] > '3' ) {
			int temp = ((int)s2_n[i] - '0') % 4;
			s2_n[i] = temp + '0';
			if (i + 1 > L2 - 1)
				s2_n.append("1");//?
			else
				s2_n[i + 1] += 1;
		}
		//cout << i << " s2[i]:" << s2_n[i] << endl;
	}
	reverse(s2_n.begin(), s2_n.end());
	toChar(s2_n);
	if (Ld != 0) {
		//swap
		char temp;
		temp = s2_n[1];
		s2_n[1] = s2_n[1];

		s2_n[0] = temp;
	}
	s2 = s2_n;
}


void do_L(string s1, string& s2) {
	s2.append("V");
}
void do_R(string s1, string& s2) {
	s2.insert(0, "V");
	s2.erase(s2.end()-1);
}
void do_N(string s1, string& s2) {
}
int main() {
	int num;
	string Num1, Num2, garbage,result;
	char operation;
	while (cin >> num) {
		//getline(cin, garbage);//?
		cout << "COWCULATIONS OUTPUT" << endl ;
		for (int n = 0; n < num; n++) {
			//getline(cin, Num1);
			cin >> Num1 >> Num2;
			//getline(cin,Num2);
			for (int i = 0; i < 3; i++) {
				cin >> operation;
				switch (operation) {
				case 'A':
					do_A(Num1, Num2); break;
				case 'L':
					do_L(Num1, Num2); break;
				case 'R':
					do_R(Num1, Num2); break;
				case 'N':
					do_N(Num1, Num2); break;
				default:
					cout << operation << endl;
					cout << "wrong command" << endl;
					break;
				}
			}
			//to 8 digit
			while (Num2.length() < 8) {
				Num2.insert(0, "V");
			}
			//getline(cin, garbage);
			//getline(cin, result);
			cin >> result;
			//cout << "result:" << result << endl;
			//cout << "Num2:" << Num2 << endl;
			if (result.compare(Num2) != 0) {
				cout << "NO" << endl;
			}
			else {
				cout << "YES" << endl;
			}
		}
		cout << "END OF OUTPUT" << endl;
	}
	return 0;
}