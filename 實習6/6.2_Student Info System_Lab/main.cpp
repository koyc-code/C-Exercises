#include <iostream>
#include <sstream>
#include <cstring>
#define SIZE 1000
using namespace std;
//1. Add, delete, edit, find a student.
//2. List every student.

/*memo
invalid conditions
*/

class Student {
public:
	bool empty = true;
	string id;
	string name;
	string gender;
	float height;
	float weight;
	Student() {
		empty = true;
		id.clear();
		name.clear();
		gender.clear();
		height = 0;
		weight = 0;
	}
	void add(stringstream& input) {
		input >> name;
		input >> gender;
		input >> height;
		input >> weight;
		empty = false;
	}
	void del() {
		Student _void; //is null?
		*this = _void;
	}
	void print() {
		cout << id << "\t" << name << "\t" << gender << "\t" << height << "\t" << weight << endl;
	}
	};
int find_empty(Student student[]) {
	for (int i = 0; i < SIZE; i++) {
		if (student[i].empty == true) {
			return i;
		}
	}
	return -1;
}
int find_id(Student student[] , string id) {
	for (int i = 0; i < SIZE; i++) {
		if (student[i].id == id) {
			return i;
		}
	}
	return -1;
}
void swap(Student& s1, Student& s2) {
	Student temp;
	temp = s1;
	s1 = s2;
	s2 = temp;
}
int main() {
	Student student[SIZE] = {};
	string command , input_str , item ;
	string id;
	stringstream input_ss;
	while (getline(cin, input_str)) {
		input_ss << input_str;
		input_ss >> command;
		if (command.compare("Add") == 0) {
			input_ss >> id;
			int position = find_id(student , id);
			if (position != -1) {
				cout << "The student's ID is duplicate."<<endl;
				input_ss.str("");
				input_ss.clear();
				continue;
			}
			position = find_empty(student);
			student[position].id = id;
			student[position].add(input_ss);
		}
		else if (command.compare("Del") == 0) {
			input_ss >> id;
			int position = find_id(student,id);
			if (position == -1) {
				cout << "Student Not Found."<<endl;
				input_ss.str("");
				input_ss.clear();
				continue;
			}
			int tail = find_empty(student)-1;
			student[position].del();
			//move data forward
			swap(student[position],student[tail]);
		}
		else if (command.compare("Find") == 0) {
			input_ss >> id;
			int position = find_id(student, id);
			if (position == -1) {
				cout << "Student Not Found."<<endl;
				input_ss.str("");
				input_ss.clear();
				continue;
			}
			student[position].print();
		}
		else if (command.compare("Edit") == 0) {
			input_ss >> id;
			input_ss >> item;
			int position = find_id(student, id);
			if (position == -1) {
				cout << "Student Not Found."<<endl;
				input_ss.str("");
				input_ss.clear();
				continue;
			}
			if (item.compare("Name") == 0) {
				input_ss >> student[position].name;
			}
			else if (item.compare("Gender") == 0) {
				input_ss >> student[position].gender;
			}
			else if (item.compare("Height") == 0) {
				input_ss >> student[position].height;
			}
			else if (item.compare("Weight") == 0) {
				input_ss >> student[position].weight;
			}
			else {
				cout << "item does not exist"<<endl;
			}

		}
		else if (command.compare("List") == 0) {
			//sort by id
			 for (int i = 0; student[i].empty == false; i++) {
				 for (int j = 1; student[j].empty == false; j++) {
					 if (student[j - 1].id > student[j].id) swap(student[j - 1], student[j]);
				}
			 }
			 //print
			 for (int i = 0; student[i].empty == false; i++) {
				 student[i].print();
			 }
			
		}
		else {
			cout << "invalid command"<<endl;
		}
		input_ss.str("");
		input_ss.clear();
	
	}
    return 0;
}