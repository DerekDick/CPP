#include <iostream>
#include <string>

using namespace std;

struct person {
	string name;
	string homeland;
	int age;
	
	//A function to print the contents of this struct person, which are the information of this person
	void printInfo() {
		cout << "Before:" << endl 
		<< "Name: " << name << endl 
		<< "Homeland: " << homeland << endl 
		<< "Age: " << age << endl;
	}
};

typedef struct person person;

int main(void) {
	//Declare an instance of struct person and initialize it
	person student = {
		"Derek", "China", 19
	};
	
	//Print the initial contents of student
	student.printInfo();
	
	cout << "=====================" << endl;//Delimiter
	
	person *pPerson = &student;//Assign the address of the instance to a pointer to it
	
	//Modifying...
	(*pPerson).name = "Dick";
	(*pPerson).homeland = "USA";
	(*pPerson).age = 18;
	
	//Print the modified contents of student
	(*pPerson).printInfo();
	
	return 0;
}
