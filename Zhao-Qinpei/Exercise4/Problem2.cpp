#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

template <class T> struct shorter : binary_function <T, T, bool> {
	bool operator() (const T& x, const T& y) const { return x.size() < y.size(); }
};

int main() {
	ifstream infile("article.txt");//The input file(the article.txt)
	ofstream outfile("lengthOrder.txt");

	//Store the words into a set(with whitespaces ignored and all characters set to lowercase)
	set<string> wordSet;
	char c;
	string word;
	while (infile >> noskipws >> c) {
		if (isalpha(c)) {
			c = tolower(c);//Set all characters to lowercase
			word += c;
		}
		else {
			if (!word.empty()) {
				wordSet.insert(word);
				word = "";
			}
		}
	}

	//Store the unrepeated words into a vector
	vector<string> wordVec;
	for (set<string>::iterator iter = wordSet.begin(); iter != wordSet.end(); iter++) {
		wordVec.push_back(*iter);
	}

	//Sort the words in the vector in increasing length order
	sort(wordVec.begin(), wordVec.end(), shorter<string>());

	//Output
	for (vector<string>::iterator iter = wordVec.begin(); iter != wordVec.end(); iter++) {
		outfile << *iter << endl;
	}

	//Close the file
	infile.close();
	outfile.close();

	return 0;
}