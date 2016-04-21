#include <iostream>

using namespace std;

int n, m, k;
char matrix[500][500];
int tag[500][500];
int Count = 0; //Count the number of the remaining empty cells(here use Count instead of count to avoid contradictation with std::count)
int length; //The length of the stretching road
void stretch(int i, int j);

int main(void) {
	//Input
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
		}
	}

	//Revising the matrix
	int emptyNum = 0; //The number of the original empty cells
	for (int i = 0; i < n; i++) { //Count the number of the empty cells
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == '.') {
				emptyNum++;
			}
		}
	}
	int remainedNum = emptyNum - k; //The number of the remained empty cells
	length = remainedNum;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == '.') {
				//Tag the remaining empty cells
				stretch(i, j);
				//Revising...
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) {
						if (matrix[i][j] == '.' && tag[i][j] != 1) {
							matrix[i][j] = 'X';
						}
					}
				}
				goto endLoop;
			}
		}
	}
endLoop:
	;

	//Output the revised matrix
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << matrix[i][j];
		}
		cout << endl;
	}

	////////////////////////////////////////
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << tag[i][j];
		}
		cout << endl;
	}*/
	////////////////////////////////////////

	return 0;
}

void stretch(int i, int j) {
	if (Count == length) {
		return;
	}

	Count++;
	tag[i][j] = 1;

	//Stretch up
	if (i != 0) {
		if (matrix[i - 1][j] == '.') {
			tag[i][j] = -1;
			if (tag[i - 1][j] == 1) {
				;
			}
			else if (tag[i - 1][j] == -1) {
				tag[i - 1][j] = 1;
			}
			else {
				stretch(i - 1, j);
			}
		}
	}

	//Stretch right
	if (j != m - 1) {
		if (matrix[i][j + 1] == '.') {
			tag[i][j] = -1;
			if (tag[i][j + 1] == 1) {
				;
			}
			else if (tag[i][j + 1] == -1) {
				tag[i][j + 1] = 1;
			}
			else {
				stretch(i, j + 1);
			}
		}
	}

	//Stretch down
	if (i != n - 1) {
		if (matrix[i + 1][j] == '.') {
			tag[i][j] = -1;
			if (tag[i + 1][j] == 1) {
				;
			}
			else if (tag[i + 1][j] == -1) {
				tag[i + 1][j] = 1;
			}
			else {
				stretch(i + 1, j);
			}
		}
	}

	//Stretch left
	if (j != 0) {
		if (matrix[i][j - 1] == '.') {
			tag[i][j] = -1;
			if (tag[i][j - 1] == 1) {
				;
			}
			else if (tag[i][j - 1] == -1) {
				tag[i][j - 1] = 1;
			}
			else {
				stretch(i, j - 1);
			}
		}
	}

	tag[i][j] = 1;

	return;
}
