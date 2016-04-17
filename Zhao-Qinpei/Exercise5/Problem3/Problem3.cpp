#include <iostream>
#include <string>
#include "student.h"

using namespace std;

int main(int argc, char* argv[]) {
	//Declare a Student instance Derek
	Student Derek;

	//Initialize the Student Derek
	Derek.init("Hou", "Jianfeng", 1552719);

	cout << "Student Derek's basic information: " << endl
		<< "student identification number :" << Derek.id() << endl
		<< "full name: " << Derek.fullName() << endl;

	return 0;
}