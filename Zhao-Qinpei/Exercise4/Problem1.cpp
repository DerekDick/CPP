#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>
#include <functional>

using namespace std;

int main() {
	ifstream infile("article.txt");//Input file(the article)
	ofstream desoutfile("descending.txt");//Output file in descendin order
	ofstream lexoutfile("lexicographic.txt");//Output file in lexicographic order
	map<string, size_t> countWord;

	//Store the words into a map(with whitespaaces ignored and all characters set to lowercase) 
	char c;
	string word;
	while (infile >> noskipws >> c) {
		if (isalpha(c)) {
			c = tolower(c);//Set all characters to lowercase
			word += c;
		}
		else {
			if (!word.empty()) {
				++countWord[word];
				word = "";
			}
		}
	}

	//Sorting
	vector<int> sortingVec;//The vector of int for sorting
	int i = 0;
	for (map<string, size_t>::const_iterator iter = countWord.begin(); iter != countWord.end(); i++, iter++) {
		sortingVec.push_back(iter->second);
	}
	sort(sortingVec.begin(), sortingVec.end(), greater<int>());//Sort the frequency value

	//Output in lexicographic order
	for (map<string, size_t>::const_iterator iter = countWord.begin(); iter != countWord.end(); iter++) {
		lexoutfile << setw(20) << '\"' + iter->first << "\" occurs " << setw(3) << iter->second 
			<< ((iter->second == 1) ? " time." : " times.") << endl;
	}

	//Output in descending frequency order
	for (vector<int>::iterator freIter = sortingVec.begin(); freIter != sortingVec.end(); freIter++) {
		if (freIter == sortingVec.begin()) {
			for (map<string, size_t>::iterator iter = countWord.begin(); iter != countWord.end(); iter++) {
				if (iter->second == *freIter) {
					desoutfile << setw(20) << '\"' + iter->first << "\" occurs " << setw(3) << iter->second
						<< ((iter->second != 1) ? " times." : " time.") << endl;
				}
			}
		}
		else if (*freIter != *(freIter - 1)) {
			for (map<string, size_t>::iterator iter = countWord.begin(); iter != countWord.end(); iter++) {
				if (iter->second == *freIter) {
					desoutfile << setw(20) << '\"' + iter->first << "\" occurs " << setw(3) << iter->second
						<< ((iter->second != 1) ? " times." : " time.") << endl;
				}
			}
		}
	}

	return 0;
}
