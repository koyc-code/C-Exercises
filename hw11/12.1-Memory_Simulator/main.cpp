#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

void doSet(vector<int> & memory) {
	int pos;
	string type , inputString;
	unsigned long long int value;
	cin >> pos >> type;
	//check position
	if (pos > memory.size()-1) {
		cout << "Violation Access." << endl;
		cin >> inputString;//garbage
		return;
	}
	//
	if (type.compare("String") == 0) {
		cin >> inputString;
		int mPos = pos;//memory position
		for (int i = 0; i < inputString.length(); i++) {
			//1 char -- 1 byte , so ASCII CODE won't be larger than 255
			//check position
			if (mPos > memory.size()-1) {
				cout << "Violation Access." << endl;
				return;
			}
			memory[mPos] = (int)inputString[i];
			mPos++;
		}
	}
	else if (type.compare("char")==0) {
		//1 char -- 1 byte , so ASCII CODE won't be larger than 255
		cin >> inputString;
		int mPos = pos;//memory position
		memory[mPos] = (int)inputString[0];
	}
	else if (type.compare("short")==0) {
		cin >> value;
		for (int i = pos; i < pos+2 ; i++) { //2 bytes
			if (i > memory.size()-1) {
				cout << "Violation Access." << endl;
				return;
			}
			int numberInOneByte = value &255;
			memory[i] = numberInOneByte;
			value >>= 8;
		}
	}
	else if (type.compare("int")==0) {
		cin >> value;
		for (int i = pos; i < pos+4 && value != 0; i++) { //4 bytes
			if (i > memory.size()-1) {
				cout << "Violation Access." << endl;
				return;
			}
			int numberInOneByte = value & 255;
			memory[i] = numberInOneByte;
			//cout << "i=" << i << " " << memory[i] << endl;
			value >>= 8;
		}
	}
	else cout << "wrong" << endl;
}
void Get(vector<int> & memory) {
	int pos;
	string type;
	cin >> pos >> type;
	//check position
	if (pos > memory.size()-1) {
		cout << "Violation Access." << endl;
		return;
	}
	if (type.compare("String") == 0) {
		for (int i = pos; i < memory.size(); i++) {
			//if memory[i]==0?
			cout << (char)memory[i];
		}
		puts("");
	}
	else {
		int nByte;
		if (type.compare("char") == 0) nByte = 1;
		else if (type.compare("short") == 0) nByte = 2;
		else if (type.compare("int") == 0) nByte = 4;
		if (pos-1+nByte > memory.size() - 1) {
			cout << "Violation Access." << endl;
			return;
		}
		int value = 0;
		for (int i = 0; i < nByte; i++) {
			
			int temp = memory[pos + i] << 8*i;
			value += temp;
		}
		cout << value<<endl;
	}
}
void doCommand(string cmd , vector<int> & memory) {
	if (cmd.compare("Set") == 0)
		doSet(memory);
	else if (cmd.compare("Get") == 0)
		Get(memory);
	else {
		cout << "invalid command" << endl;
		string garbage;
		getline(cin, garbage); //?????? 
	}
}
int main() {
	int size, nCommands;//memory capacity , numbers of commands
	cin >> size >> nCommands;
	vector<int> memory;
	memory.resize(size);
	//reset?
	string type, cmd; 
	for (int i = 0; i < nCommands; i++) {
		cin >> cmd;
		doCommand(cmd,memory);
	}
    return 0;
}