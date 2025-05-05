/*
symptom space????????????
*/

#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
string symptom_denied[5] = { "Fever" , "Dry cough" , "Fatigue" , "Shortness of breath", "Chills" };
string country_denied[9] = { "China" , "USA" , "Italy", "Spain" , "Germany" , "Iran","France", "UK","Switzerland" };
class student {
public:
	string id;
	string symptom;
	string travel;
	bool access;
	void print_student() {
		string access_str;
		if (access == true) access_str = "Allowed";
		else access_str = "Denied";
		cout << id << "\t" << symptom << "\t" << travel << "\t" << access_str << endl;
	}
	void access_test( ) {
		//symtom first
		bool found = false;
		for (int i = 0; i < 5; i++) {
			if (symptom.compare(symptom_denied[i]) == 0) {
				access = false;
				found = true;
			}
		}
		if (found == false) {
			// travel
			for (int i=0;i<9;i++){
				if (travel.compare(country_denied[i]) == 0) {
					access = false;
					return;
				}

			}
			access = true;
		}

	}

};
int main() {
	/*
	input command
	list/ access ID SYMPTON TRAVEL
	access:
	determine if it's allowed
	put into list , add status
	list:
	print
	*/
	string command;
	vector <student> Student;
	while (cin >> command) {
		if (command == "List") {
			for (int i = 0; i < Student.size(); i++) {
				Student[i].print_student();
			}
		}
		else if (command == "Access") {
			student temp;
			cin >> temp.id;
			cin.ignore(); //eat the space
			string line , append_str;
			getline(cin, line);
			stringstream input;
			input.str(line);
			//count space
			int count =0;
			for (int i = 0; i < line.length(); i++) {
				if (line[i] == ' ') count++;
			}
			if (count == 1) {
				input >> temp.symptom;
				input >> temp.travel;
			}
			else if (count == 2) {
				input >> temp.symptom;
				input >> append_str;
				input >> temp.travel;
				temp.symptom.append(" ");
				temp.symptom.append(append_str);
			}
			else if (count == 3) {
				input >> temp.symptom;
				input >> append_str;
				temp.symptom.append(" ");
				temp.symptom.append(append_str);
				input >> append_str;
				temp.symptom.append(" ");
				temp.symptom.append(append_str);
				input >> temp.travel;
				
			}
			temp.access_test();
			Student.push_back(temp);
			if (temp.access == true) cout << temp.id << " Access allowed."<<endl;
			else cout << temp.id << " Access denied."<<endl;
		}
	}
    return 0;
}
