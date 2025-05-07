#include <iostream>
using namespace std;
#include <vector>
int main() {
	vector<vector<int>> A;
	vector<vector<int>> B;
	vector<int> temp;
	int rowA, columnA, rowB, columnB,value;
	while (cin >> rowA >> columnA >> rowB >> columnB) {
		A.clear();
		B.clear();
		temp.clear();
		if (columnA != rowB) {
			cout << "Matrix multiplication failed." << endl;
			return 0;
		}
		else {
			for (int i = 0; i < rowA; i++) {
				temp.clear();
				for (int j = 0; j < columnA; j++) {
					cin >> value;
					temp.push_back(value);
				}
				A.push_back(temp);
			}
			for (int i = 0; i < rowB; i++) {
				temp.clear();
				for (int j = 0; j < columnB; j++) {
					cin >> value;
					temp.push_back(value);
				}
				B.push_back(temp);
			}
			for (int i = 0; i < rowA; i++) {
				for (int j = 0; j < columnB; j++) {
					value = 0;
					for (int k = 0; k < columnA; k++) {
						int temp = A[i][k] * B[k][j];
						value += temp;
					}
					cout << value << " ";
				}
				puts("");
			}
		}
	}
    return 0;
}