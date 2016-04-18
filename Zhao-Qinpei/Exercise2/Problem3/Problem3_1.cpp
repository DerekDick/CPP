#include <iostream>
#include <string>
#include <vector>

using namespace std;

int max(vector<int> vec) {
	int current = vec[0];
	for (int i = 1; i < vec.size(); i++) {
		if (vec[i] > current)
			current = vec[i];
	}
	return current;
}

float max(vector<float> vec) {
	float current = vec[0];
	for (int i = 1; i < vec.size(); i++) {
		if (vec[i] > current)
			current = vec[i];
	}
	return current;
}

string max(vector<string> vec) {
	string current = vec[0];
	for (int i = 1; i < vec.size(); i++) {
		if (vec[i] > current)
			current = vec[i];
	}
	return current;
}

int max(int arr[], int length) {
	int current = arr[0];
	for (int i = 1; i < length; i++) {
		if (arr[i] > current)
			current = arr[i];
	}
	return current;
}

float max(float arr[], int length) {
	float current = arr[0];
	for (int i = 1; i < length; i++) {
		if (arr[i] > current)
			current = arr[i];
	}
	return current;
}

string max(string arr[], int length) {
	string current = arr[0];
	for (int i = 0; i < length; i++) {
		if (arr[i] > current)
			current = arr[i];
	}
	return current;
}

int main() {
	//Maximum among the elements of a vector of integers
	vector<int> intVec{ 233, 666, 999, 1024, 520, 110 };
	cout << "vector<int> intVec{ 233, 666, 999, 1024, 520, 110 };" << endl
		<< "max(intVec) = " << max(intVec) << endl << endl;

	//Maximum among the elements of a vector of floating numbers
	vector<float> floatVec{ 2.7f, 9.9999f, 2.33f, 3.14f };
	cout << "vector<float> floatVec{ 2.7f, 9.9999f, 2.33f, 3.14f };" << endl
		<< "max(floatVec) = " << max(floatVec) << endl << endl;

	//Maximum among the elements of a vector of strings
	vector<string> strVec{ "aaab", "aaac", "aaad", "zzz", "Aaaa" };
	cout << "vector<string> strVec{ \"aaab\", \"aaac\", \"aaad\", \"zzz\", \"Aaaa\" };" << endl
		<< "max(strVec) = \"" << max(strVec) << '\"' << endl << endl;

	//Maximum among an array of integers
	int intArr[] = { 666, 233, 999, 520, 1024, 110 };
	cout << "int intArr[6] = {666, 233, 999, 520, 1024, 110};" << endl
		<< "max(intArr, 6) = " << max(intArr, 6) << endl << endl;

	//Maximum among an array of floating numbers
	float floatArr[4] = { 3.14f, 2.7f, 9.9999f, 2.33f };
	cout << "float floatArr[4] = { 3.14f, 2.7f, 9.9999f, 2.33f };" << endl
		<< "max(floatArr, 4) = " << max(floatArr, 4) << endl << endl;

	//Maximum among an array of strings
	string stringArr[5] = { "aaab", "aaac", "aaad", "zzz", "Aaaa" };
	cout << "string stringArr[5] = { \"aaab\", \"aaac\", \"aaad\", \"zzz\", \"Aaaa\" };" << endl
		<< "max(stringArr, 5) = \"" << max(stringArr, 5) << '\"' << endl << endl;

	return 0;
}