#include <iostream>
#include <cstdlib>
//#include <iomanip>

int n, m;
char matrix[50][50]; //The two dimention array to store the dots
int status[50][50]; //0 means not considered, positive integer means considered, -1 means the last one
void stretch(int i, int j, int id);
//void print();

int main() {
	//Input
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> matrix[i][j];
		}
	}

	//Generating the graph
	int count = 0; //The id(status) of a trail of dots
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!status[i][j]) { //If this Dot has not been considered
				//Generate a stretching road
				count++;
				stretch(i, j, count);
			}
		}
	}
	std::cout << "No" << std::endl;

	return 0;
}

void stretch(int i, int j, int id) {
	//print(); //Track the process
	char color = matrix[i][j];
	status[i][j] = id;
	
	//Find the last position and set its status to id
	char last = '\0';
	if (i != 0) {
		if (status[i - 1][j] == -1) {
			last = 'u';
			status[i - 1][j] = id;
		}
	}
	if (j != m - 1) {
		if (status[i][j + 1] == -1) {
			last = 'r';
			status[i][j + 1] = id;
		}
	}
	if (i != n - 1) {
		if (status[i + 1][j] == -1) {
			last = 'd';
			status[i + 1][j] = id;
		}
	}
	if (j != 0) {
		if (status[i][j - 1] == -1) {
			last = 'l';
			status[i][j - 1] = id;
		}
	}
	
	//std::cout << "Last one: " << last << std::endl; //Track the last move

	//Stretch up
	if (i != 0) {
		if (matrix[i - 1][j] == color && last != 'u') {
			if (status[i - 1][j] == id) {
				std::cout << "Yes" << std::endl;
				exit(0);
			}
			status[i][j] = -1;
			stretch(i - 1, j, id);
		}
	}
	
	//Stretch right
	if (j != m - 1) {
		if (matrix[i][j + 1] == color && last != 'r') {
			if (status[i][j + 1] == id) {
				std::cout << "Yes" << std::endl;
				exit(0);
			}
			status[i][j] = -1;
			stretch(i, j + 1, id);
		}
	}
	
	//Stretch down
	if (i != n - 1) {
		if (matrix[i + 1][j] == color && last != 'd') {
			if (status[i + 1][j] == id) {
				std::cout << "Yes" << std::endl;
				exit(0);
			}
			status[i][j] = -1;
			stretch(i + 1, j, id);
		}
	}

	//Stretch left
	if (j != 0) {
		if (matrix[i][j - 1] == color && last != 'l') {
			if (status[i][j - 1] == id) {
				std::cout << "Yes" << std::endl;
				exit(0);
			}
			status[i][j] = -1;
			stretch(i, j - 1, id);
		}
	}

	status[i][j] = id;

	return;
}

/*void print() {
	//This function is used to print the status of the matrix of dots, mainly for debugging
	std::cout << "---------------" << std::endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cout << std::setw(2) << status[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << "---------------" << std::endl;
}*/

