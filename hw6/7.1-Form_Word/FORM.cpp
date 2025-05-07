#include <iostream>
#include "Form.h"
#include <string>
#include <vector>
using namespace std;

//設定Input
void Form::SetInputWord(string inputWord) {
	this->input = inputWord;
}
//處理 Input 的資訊
void Form::ProcessInputWord() {
	for (int i = 0; i < input.length(); i++) {
		input[i] = tolower(input[i]);
	}
}
//設定檔案名稱
void Form::SetFileName(string fileName) {
	this->file.open(fileName , ios::in);
	/*if (file.is_open()) cout << "file opened";
	else cout << "failed";*/
}
//讀檔並且比較
void Form::Load_CompareWord() {
	string temp;
	bool match;
	while (file>>temp) {  //if one word each line
		match = true;
		//cout << temp <<endl;
		string copy = input;
		for (int i = 0; i < temp.length(); i++) {
			temp[i] = tolower(temp[i]);
			size_t found = copy.find(temp[i]);
			if (found == string::npos) { //npos->end of the string
				match = false;
				break;
			}
			else {
				copy[found] = ' ';
			}
		}
		if (match == true) {
			words_match.push_back(temp);
		}

	}
}
////印出符合的字
void Form::PrintFoundWords() {
	for ( unsigned long long int i = 0; i < words_match.size(); i++) {
		cout << words_match[i];
		cout << endl;
	}
}