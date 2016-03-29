/*
This program is to compare the two ways of passing by reference andf passing by pointer.
*/
#include <iostream>
#include <string>

using namespace std;

//Two functions to reverse a string
void reverse(string *pstr);
void reverse(string &str);

int main(void) {
	//Declare two string objects and initialize them the same
	string str1 = "ABCDEFG";
	string str2 = str1;
	
	//Print the initial string
	cout << "Before operation, str is: \"" << str1 << '\"' << endl;
	
	//Passing string* to function1 and print the result
	reverse(&str1);
	cout << "After passing string* to function1, str is: \"" << str1 << '\"' << endl;
	
	//Passing string& to function2 and print the result
	reverse(str2);
	cout << "After passing string& to function2, str is: \"" << str2 << '\"' << endl;
	
	cout << "Attention please! Although the two ways to modify string objects work correctly, "
	"but it is better to use reference rather than pointer for reference is more safer." << endl;
	
	return 0;
}

void reverse(string *pstr) {
	string temp = *pstr;
	unsigned size = (*pstr).size();
	for (int i = 0; i <= size - 1; i++) {
		(*pstr)[i] = temp[size - 1 - i];
	}
}

void reverse(string &str) {
	string temp = str;
	unsigned size = str.size();
	for (int i = 0; i <= size - 1; i++) {
		str[i] = temp[size - 1 - i];
	}
}
