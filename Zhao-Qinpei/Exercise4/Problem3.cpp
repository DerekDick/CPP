#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>

using namespace std;

int main() {
	istream_iterator<int> intIter(cin);
	istream_iterator<int> intEOF;
	ofstream outodd("odd.txt");
	ofstream outeven("even.txt");

	//Input a series of integers by using istream_iterator
	vector<int> num;
	while (intIter != intEOF) {
		num.push_back(*(intIter++));
	}

	//Output
	for (vector<int>::iterator iter = num.begin(); iter != num.end(); iter++) {
		if (*iter % 2 == 0) {
			outeven << *iter << endl;
		}
		else {
			outodd << *iter << ' ';
		}
	}

	//Close the files
	outodd.close();
	outeven.close();

	return 0;
}