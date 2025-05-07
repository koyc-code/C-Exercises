#include <iostream>
#include <vector>
using namespace std;

int main() {
	int num;//numbers of scores
	float tot,ave,dev_temp,dev,temp;
	while (cin >> num) {
		vector <int> score;
		tot = 0; dev_temp = 0;
		for (int i = 0; i < num; i++) {
			cin >> temp;
			score.push_back(temp);
			tot += score[i];
		}
		ave = tot / num;
		for (int i = 0; i < num; i++) {
			dev_temp += (score[i] - ave)*(score[i] - ave);

		}
		dev = sqrt(dev_temp / num);
		cout << "Average:" << ave << "\t" << "Standard deviation:" << dev<<endl;
	}
    return 0;
}