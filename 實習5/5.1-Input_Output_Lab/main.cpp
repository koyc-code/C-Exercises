#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main() {
	string num_str; int total_len;	int decimal_len;char ch;
	string get_input ; stringstream input;
	vector<char> output;
	while (getline(cin, get_input)) {
		//using string stream
		ch = NULL;
		input.str("");
		input.clear();

		input << get_input;
		input >> num_str;
		input >> total_len;
		input >> decimal_len;
		input >> ch;
		// if input to ch is blankspace, ch will be NULL
		if (ch == NULL) ch = ' ';
		//fill the integer part
		int dp_loc = 0; //decimal point location
		bool isFound = false;
		for (int i = 0; i < num_str.length(); i++) {
			if (num_str[i] == '.') {
				isFound = true;
				dp_loc = i;
				break;
			}
			output.push_back(num_str[i]);

		}
		//get decimal part
		if (isFound == true) {
			if (decimal_len !=0) output.push_back('.');
			for (int i = 1; i <= decimal_len; i++) {
				int pos = dp_loc + i;
				if (pos < num_str.length()) 	output.push_back(num_str[pos]);
				else output.push_back('0');
			}
		}
		else {
			if (decimal_len != 0) output.push_back('.');
			for (int i = 0; i < decimal_len; i++) {
				output.push_back('0');
			}
		}

		//fill the char
		int char_len = total_len - output.size();
		for (int i = 0; i < char_len; i++) {
			output.insert(output.begin(), ch);
		}

		 //print output;
		for (int i = 0; i < output.size(); i++) {
			cout << output[i];
		}
		cout << endl;
		output.clear();
	}

    return 0;
}