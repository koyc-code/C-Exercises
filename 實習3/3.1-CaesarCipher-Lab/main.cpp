#include <iostream>
#include <string>
using namespace std;
//���ƿ�J
int main() {
	string str;
	long int num;
	while (getline(cin, str)) {
		cin >> num;
		num = num % 26; //shift from 0 to 25 
		int i = 0;
		while (str[i] != NULL) {
			// if str[i]=space;
			if (str[i] == ' ') cout << ' ';
			// if str[i] = char
			else {
				int ch = (int)str[i] + num;
				//cout<<str[i]<<(int)str[i]<<(int)ch;
				//�Φ��r���j��
				if (ch > 'z') ch = ('a'-1) + (ch - 'z');
				else if (ch < 'a') ch = ('z'+1) - ('a' - ch);
				cout << (char)ch;
			}
			i++;
		}
		cout << endl;
		char garbage = getchar();//eat \r (�_�h �U�@��getline �|�Y���W�@�ռƦr��\r�H�e���F��) 
	}
    return 0;
}