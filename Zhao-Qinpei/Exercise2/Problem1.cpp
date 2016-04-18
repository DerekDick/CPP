#include <iostream>
#include <vector>

using namespace std;

vector<unsigned> pentagonSeq(int length) {
	//Dealing with exceptions(Robustness)
	if (length > 1000) {
		cerr << "The value of n is too large!\a" << endl;
		exit(1);
	}
	else if (length <= 0) {
		cerr << "Illegal input!\a" << endl;
		exit(1);
	}

	//Generate the pentagonal sequence if the value of length is valid
	vector<unsigned> series;
	for (int i = 1; i <= length; i++) {
		series.push_back((i * (3 * i - 1)) / 2);
	}

	return series;
}

void printSeq(vector<unsigned> series, string type = "pentagonal") {
	for (int i = 0; i < series.size(); i++)
		cout << series[i] << ' ';

	cout << endl;
}

int main(void) {
	//Prompt to input
	cout << "Please input the index n of the last number you want to get" << endl
		<< "(non-negative and more than 1000):" << endl;
	int n;
	cin >> n;

	

	//Generate the pentagonal sequence
	vector<unsigned> series = pentagonSeq(n);

	//Print out the sequence
	printSeq(series, "pentagonal");

	return 0;
}