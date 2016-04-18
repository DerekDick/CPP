#include <iostream>
#include <vector>

using namespace std;

inline void check(int n) {
	//Dealing with exceptions(Robustness)
	if (n > 1000) {
		cerr << "The value of n is too large!\a" << endl;
		exit(1);
	}
	else if (n <= 0) {
		cerr << "Illegal input!\a" << endl;
		exit(1);
	}
}

vector<unsigned> pentagonSeq(unsigned length) {
	//Generate the pentagonal sequence
	vector<unsigned> series;
	for (int i = 1; i <= length; i++) {
		series.push_back((i * (3 * i - 1)) / 2);
	}

	return series;
}

void printSeq(vector<unsigned> series, string type = "pentagonal") {
	for (int i = 0; i < series.size(); i++) {
		cout << series[i] << ' ';
	}
	cout << endl;
}

int main(void) {
	//Prompt to input
	cout << "Please input the index n of the last number you want to get" << endl
		<< "(non-negative and more than 1000):" << endl;
	int n;
	cin >> n;

	//Check if the value of n is valid
	check(n);
	

	//Generate the pentagonal sequence
	vector<unsigned> series = pentagonSeq(n);

	//Print out the sequence
	printSeq(series, "pentagonal");

	return 0;
}