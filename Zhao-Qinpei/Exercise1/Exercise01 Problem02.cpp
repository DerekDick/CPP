#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(void) {
	//Output file
	ofstream outfile("output2.txt");
	
	//The vector to store floating numbers 
	vector<float> numbers(25);
	
	//Store the initial value of all the elements in vector numbers  and display them
	for (int i = 1; i <= 25; i++) {
		numbers[i - 1] = i + 0.1f;
		outfile << numbers[i - 1] << endl;
		cout << numbers[i - 1] << endl;
	}

	outfile << endl;
	cout << endl;
	
	//Calculate the square of all the elements in vactor numbers and output the results
	for (int i = 1; i <= 25; i++) {
		numbers[i - 1] = numbers[i - 1] * numbers[i - 1];
		outfile << numbers[i - 1] << endl;
		cout << numbers[i - 1] << endl;
	}

	return 0;
}
