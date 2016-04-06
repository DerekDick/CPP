#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

ofstream comparison("comparison.txt");
ofstream result("result.txt");

unsigned long long fibonacci_arr(int index);
unsigned long long fibonacci_recursive(int index);
void compare(int length);

int main() {
	cout << "This program is used to compare the time efficiency of the two ways to generate Fibonacci sequence." << endl
		<< "Please wait patiently. The comparison ordinarily ends in a minute" << endl << "Comparing..." << endl;
	
	//Compare 40 times in loops
	for (int i = 1; i <= 40; i++) {
		compare(i);
	}

	cout << "Comparison ended. Please check the two files(comparison.txt and result.txt) to see the result" << endl;
	
	return 0;
}

unsigned long long fibonacci_arr(int index) {
	unsigned long long series[50] = { 1, 1 };
	for (int i = 2; i < index; i++) {
		series[i] = series[i - 1] + series[i - 2];
	}
	return series[index - 1];
}

unsigned long long fibonacci_recursive(int index) {
	if (index <= 2) {
		return 1;
	}
	else {
		return fibonacci_recursive(index - 1) + fibonacci_recursive(index - 2);
	}
}

void compare(int length) {
	clock_t start, end;
	start = clock();
	result << "Array(" << length << "): " << endl;
	for (int i = 1; i <= length; i++) {
		result << fibonacci_arr(i) << ' ';
	}
	end = clock();
	result << endl;

	comparison << "Array(" << length << "): " << (end - start) / double(CLOCKS_PER_SEC) << "s" << "      ";

	result << "Recursive(" << length << "): " << endl;
	start = clock();
	for (int i = 1; i <= length; i++) {
		result << fibonacci_recursive(i) << ' ';
	}
	end = clock();
	result << endl << endl;

	comparison << "Recursive(" << length << "): " << (end - start) / double(CLOCKS_PER_SEC) << "s" << endl;
}