#include <iostream>
#include <string>
using namespace std;

short int n, m;
int main() {
	while (cin >> m >> n)
	{
		if (m == 0 && n == 0) { return 0; }
		char** letters = new char*[m];
		for (int i = 0; i < m; i++) {
			letters[i] = new char[2];
			cin >> letters[i][0] >> letters[i][1];
		}

		char words[50], transWord[50];
		for (int i = 0; i < n; i++) {
			cin >> words >> transWord;
			if (canTranslateStr(words, transWord, letters)) {
				cout << "yes\n";
			}
			else {
				cout << "no\n";
			}
		}
	}
}

string& _possibleChar(string& p_Char, char a, char** letters) {
	p_Char += a;
	for (int i = 0; i < m; i++) {
		if (a == letters[i][0] && p_Char.find(letters[i][1]) == std::string::npos) {
			_possibleChar(p_Char, letters[i][1], letters);
		}
	}
	return p_Char;
}

bool _canTranslateChar(char a, char b, char** transLetters) {
	string possibleChars = "";
	_possibleChar(possibleChars, a, transLetters);
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
		if (!_canTranslateChar(word[i], targetWord[i], transLetters)) {
			return false;
		}
	}
	return true;
}


