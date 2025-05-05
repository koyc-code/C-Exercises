//#include <iostream>
//#include <string>
//using namespace std;
//int main() {
//	string str;
//	while (getline(cin, str)) {
//		cout << str<<endl;
//	}
//}

#include <iostream>
#include <sstream>
#include <vector>
#define SIZE 100
using namespace std;
/*
AddStudent <Student_name>
addcourse name course w+t ...
delname
delcourse name course
print students
print name --> print schedule
print name course ----->print time

*/
struct Student {
	bool empty = true;
	string name;
	string course[5][11] = {""};
};
int find_empty(Student student[]) {
	for (int i = 0; i < SIZE; i++) {
		if (student[i].empty == true) {
			return i;
		}
	}
	return -1;
}
int find_name(Student student[], string name) {
	for (int i = 0; i < SIZE; i++) {
		if (student[i].name == name) return i;
	}
	return -1;
}
void swap(Student& s1, Student& s2) {
	Student temp;
	temp = s1;
	s1 = s2;
	s2 = temp;
}
int week_int(char week) {
	switch (week) {
	case 'M':return 0;
	case 'T':return 1;
	case 'W':return 2;
	case 'R':return 3;
	case 'F':return 4;
	default: cout << "week wrong"<<endl;
	}
}
char week_char(int num) {
	switch (num) {
	case 0:return 'M';
	case 1:return 'T';
	case 2:return 'W';
	case 3:return 'R';
	case 4:return 'F';
	default:cout << "week num wrong"<<endl;
	}
}

int main() {
	Student student[SIZE] = {};
	string input_str;
	while (getline(cin, input_str)) {
		stringstream input;
		input << input_str;
		string command , item , name , course;
		input >> command;
		if (command.compare("AddStudent") == 0) {
			input >> name;
			int pos = find_name(student , name);
			if (pos != -1) {
				cout << "The student's name is duplicate." << endl;
				continue;
			}
			pos = find_empty(student);
			if (pos == -1) {
				cout << "array is full";
				continue;
			}
			student[pos].name = name;
			student[pos].empty = false;
		}
		else if (command.compare("AddCourse") == 0) {
			input >> name >> course;
			int pos = find_name(student, name);
			if (pos == -1) {
				cout << "The student's name does not exist." << endl;
				continue;
			}
			char temp[10] = ""; int num[10] = {0};
			bool conflict=false;
			for (int i = 0; input >> temp[i] >> num[i]; i++) {
				if (student[pos].course[week_int(temp[i])][num[i]] != "")
				{
					conflict = true;
					break;
				}
			}
				
			if (conflict == false) {
				for(int i=0; num[i]!= 0 ; i++){
					student[pos].course[week_int(temp[i])][num[i]] = course;
				}
			}
				else
				{
					cout << "Course conflict." << endl;
				}
		}
		
		else if (command.compare("DelStudent") == 0) {
			input >> name;
			int pos = find_name(student, name);
			if (pos == -1) {
				cout << "The student's name does not exist." << endl;
				continue;
			}
			//move data forward
			int i;
			for (i = pos+1; student[i].empty == false; i++) {
				swap(student[i - 1], student[i]);
			}
			student[i - 1].empty = true; // the deleted one
			student[i - 1].name = "";
		}
		else if (command.compare("DelCourse") == 0) {
			input >> name >> course;
			int pos = find_name(student, name);
			if (pos == -1) {
				cout << "The student's name does not exist." << endl;
				continue;
			}
			bool found_course = false;
			for (int i = 0; i < 5; i++) {
				for (int j = 1; j < 11; j++) {
					if (course.compare(student[pos].course[i][j]) == 0) {
						found_course = true;
						student[pos].course[i][j] = "";
					}
				}
			}
			if (found_course == false) {
				cout << "The course does not exist." << endl;
				continue;
			}
		}
		else if (command.compare("Print") == 0) {
			input >> item;
			if (item.compare("StudentList") == 0) {
				if (student[0].empty == true) cout << "The Students list is empty." << endl;
				for (int i = 0; student[i].empty == false; i++) {
					cout << student[i].name<<endl;
				}
			}
			else {
				name = item;
				if (input >> course) {
					int pos = find_name(student, name);
					if (pos == -1) {
						cout << "The student's name does not exist." << endl;
						continue;
					}
					bool found_course = false;
					for (int i = 0; i < 5; i++) {
						for (int j = 1; j < 11; j++) {
							if (course.compare(student[pos].course[i][j]) == 0) {
								if (found_course == false)	cout<<student[pos].course[i][j]<<" ";
								cout << week_char(i) << j<<" ";
								found_course = true;
							}
						}
					}
					if (found_course == false) {
						cout << "The course does not exist." << endl;
						continue;
					}
					else {
						cout << endl;
					}

				}
				else {//print schedule
					int pos = find_name(student, name);
					if (pos == -1) {
						cout << "The student's name does not exist." << endl;
						continue;
					}
					for (int i = 0; i < 5; i++) {
						cout << week_char(i) << ": ";
						for (int j = 1;j<11;j++){
							if (student[pos].course[i][j] != "") cout << j << ":" << student[pos].course[i][j] << " ";
						}
						cout << endl;
					}
				}
			}
		}
		else {
		cout << "invalid command" << endl;
        }
	}
    return 0;
}