#include <iostream>
#include <vector>
using namespace std;
int collatz(int n);
int findMax(vector<int> length);
void swap(int *a, int *b);
static int clength;//countLength

int main() {
    /*
	input two num
	calculate from n1 to n2 (while)
	vector.pushback
	find the max length
	output maximun cycle length
	*/
	int n1, n2;
	while (cin >> n1 >> n2) {
		vector<int> length;
		cout << n1 << " " << n2<<" ";
		if (n1 > n2) swap(&n1, &n2);
		for (int i = n1; i <= n2; i++) {
			int temp;
			clength = 1;  //include i itself
			temp = collatz(i);
			length.push_back(temp);
		}
		int max = (int)findMax(length);
		cout  << max << endl;
	}
		return 0;
}
int collatz(int n) {
	if (n == 1) {
		return clength;
	}
	else if (n % 2 == 0) {
		clength++;
		return (collatz(n / 2));
	}
	else {
		clength++;
		return collatz(n * 3 + 1);
	}
}
int findMax(vector<int> length ) {
	 int max = length[0];
	for (int i = 1; i < length.size(); i++) {
		if (max < length[i]) {
			swap(&max,&length[i]);
			/*unsigned long long int temp;
			temp = max;
			max = length[i];
			length[i] = temp;*/
		}
	}
	return max;

}
void swap( int *a,  int *b) {
    int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}