#include <iostream>
#include "Form.h"
#include <string>
#include <vector>
using namespace std;

//�]�wInput
void Form::SetInputWord(string inputWord) {
	this->input = inputWord;
}
//�B�z Input ����T
void Form::ProcessInputWord() {
	for (int i = 0; i < input.length(); i++) {
		input[i] = tolower(input[i]);
	}
}
//�]�w�ɮצW��
void Form::SetFileName(string fileName) {
	this->file.open(fileName , ios::in);
	/*if (file.is_open()) cout << "file opened";
	else cout << "failed";*/
}
//Ū�ɨåB���
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
////�L�X�ŦX���r
void Form::PrintFoundWords() {
	for ( unsigned long long int i = 0; i < words_match.size(); i++) {
		cout << words_match[i];
		cout << endl;
	}
}