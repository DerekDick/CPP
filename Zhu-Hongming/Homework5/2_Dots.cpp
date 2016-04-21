#include <iostream>
#include <cstdlib>

using namespace std;

int n, m;
char matrix[50][50]; //The two dimention array to store the dots
int status[50][50]; //The status means whether the element (i, j) has been considered

void stretch(int i, int j, int id);

int main() {
	//Input
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
		}
	}

	//Generating the graph
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!status[i][j]) { //If this Dot has not been considered
				/*Creat a stretching road*/
				count++;
				stretch(i, j, count);
			}
		}
	}
	cout << "No" << endl;

	return 0;
}

void stretch(int i, int j, int id) {
	char color = matrix[i][j];
	status[i][j] = id;

	//Stretch up
	if (i != 0) {
		if (matrix[i - 1][j] == color) {
			status[i][j] = -1;
			if (status[i - 1][j] == id) {
				cout << "YES" << endl;
				exit(0);
			}
			else if (status[i - 1][j] == -1) {
				status[i - 1][j] = id;
			}
			else {
				stretch(i - 1, j, id);
			}
		}
	}
	
	//Stretch right
	if (j != m - 1) {
		if (matrix[i][j + 1] == color) {
			status[i][j] = -1;
			if (status[i][j + 1] == id) {
				cout << "Yes" << endl;
				exit(0);
			}
			else if (status[i][j + 1] == -1) {
				status[i][j + 1] = id;
			}
			else {
				stretch(i, j + 1, id);
			}
		}
	}
	
	//Stretch down
	if (i != n - 1) {
		if (matrix[i + 1][j] == color) {
			status[i][j] = -1;
			if (status[i + 1][j] == id) {
				cout << "Yes" << endl;
				exit(0);
			}
			else if (status[i + 1][j] == -1) {
				status[i + 1][j] = id;
			}
			stretch(i + 1, j, id);
		}
	}

	//Stretch left
	if (j != 0) {
		if (matrix[i][j - 1] == color) {
			status[i][j] = -1;
			if (status[i][j - 1] == id) {
				cout << "Yes" << endl;
				exit(0);
			}
			else if (status[i][j - 1] == -1) {
				status[i][j - 1] = id;
			}
			else {
				stretch(i, j - 1, id);
			}
		}
	}

	status[i][j] = id;

	return;
}
