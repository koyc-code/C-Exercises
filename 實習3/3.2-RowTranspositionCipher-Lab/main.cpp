#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main() {
	unsigned int row;
	int temp;
	string str,input;
	while (getline(cin, str)) {
		vector<int> key;
		stringstream ss;
		row = 0;
		temp = 0;
		int i = 0;
		
		getline(cin, input);

		ss << input;
		while (ss >> temp) {
			key.push_back(temp);
			row++;
		}
	
		//change space into _
		i = 0;
		while (str[i] != NULL) {
			if (str[i] == ' ') str[i] = '_';
			i++;
		}
		//print
		for (int j = 0; j < row; j++) {
			int order = key[j];//get order
			for (int k = order; k < str.length(); k+=row) {
				cout << str[k];
			}
		}
		cout << endl;
		//char garbage = getchar();
		//cout << garbage;
		//garbage = getchar();
		//cout << garbage;
		str.clear();
	
	}
    return 0;
}