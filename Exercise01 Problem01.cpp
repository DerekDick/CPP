#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(void) {
	ifstream infile("input1.txt");
	ofstream outfile("output1.txt");

	//Count the occurrence of the word "that"
	string word;
	unsigned count = 0;
	while (infile >> word) {
		//Attention please! Some "that" may be followed by a punctuation, like "that.", "that?", etc And some may be "That"
		if (word == "that" || word == "that." || word == "that!" 
		|| word == "that?" || word == "that;" || word == "that," || word == "that:" || word == "That")
			count++;
	}
	//Output the result into a file called "output.txt"
	outfile << "There are " << count << " \"that\" in input.txt." << endl;
	cout << "There are " << count << " \"that\" in input.txt." << endl;
	
	return 0;
}
