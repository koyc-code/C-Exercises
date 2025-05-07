#include <iostream>
#include <string>
using namespace std;

short int n, m;

string& possibleChar(string& pChar, char a, char** transLetters) {
	pChar += a;
	for (int i = 0; i < m;i++) {
		if (a == transLetters[i][0] && pChar.find(transLetters[i][1]) == std::string::npos) {
			//cout << pChar<<"\ntrans---" << a << endl;
			possibleChar(pChar, transLetters[i][1], transLetters);
		}
	}
	return pChar;
}

bool canTranslateChar(char a, char b, char** transLetters) {
	string possibleChars="";
	possibleChar(possibleChars, a, transLetters);
	//cout << possibleChars << "C-------\n";
	for (auto pChar : possibleChars) {
		if (pChar == b) {
			return true;
		}
	}
	return false;
}



bool canTranslateStr(string word, string targetWord, char** transLetters) {
	if (word.size() != targetWord.size()) { return false; }
	for (int i = 0; i < word.size(); i++) {
		if (!canTranslateChar(word[i], targetWord[i], transLetters)) {
			return false;
		}
	}
	return true;
}


int main() {
	while (cin >> m >> n)
	{
		if (m == 0 && n == 0) { return 0; }
		char** transLetters=new char*[m];
		for (int i = 0; i < m; i++) {
			transLetters[i] = new char[2];
			cin >> transLetters[i][0] >> transLetters[i][1];
		}

		char word[50], tranWord[50];
		for (int i = 0; i < n; i++) {
			cin >> word >> tranWord;
			if (canTranslateStr(word, tranWord, transLetters)) {
				cout << "yes\n";
			}
			else {
				cout << "no\n";
			}
		}
	}
}