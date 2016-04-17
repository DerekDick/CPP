#include <string>

using namespace std;

class Student {
	//Data
	string firstName;
	string lastName;
	int studentId;

	//Methods
public:
	void init(string str1, string str2, int id) {
		//Function to initialize a Student instance
		firstName = str1;
		lastName = str2;
		studentId = id;

		return;
	}

	int id(void) {
		return studentId;
	}

	string fullName(void) {
		return firstName + ' ' + lastName;
	}
};
