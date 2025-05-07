#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
	ifstream file;
	vector <int> arr; int temp;
	int count = 0;
	file.open("intArray.txt");
	//read file
	if (file.is_open()) {
		while (file >> temp) {
			arr.push_back(temp);
			count++;
	   }
		//sort

		//print the array
		cout << "N\tcount" << endl;
		for (int i = 0; i < count; i++) {
			cout << arr[i]<<endl;
		}
	}
	else cout << "file not opened.";
	file.close();
    return 0;
}