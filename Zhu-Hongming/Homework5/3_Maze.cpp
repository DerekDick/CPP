#include <iostream>

int n, m, k;
char matrix[500][500];
int tag[500][500];
int count = 0; //Count the number of the remaining empty cells
int emptyNum = 0, remainedNum; //The number of original empyt cells and remained empty cells
void stretch(int i, int j);

int main(void) {
	//Input
	std::cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> matrix[i][j];
			//Count the number of the original empty cells
			if (matrix[i][j] == '.') {
				emptyNum++;
			}
		}
	}

	//Tag the matrix
	remainedNum = emptyNum - k; //The number of the remained empty cells
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == '.') {
				stretch(i, j);
			}
		}
	}
	
	//Revise the matrix
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == '.' && tag[i][j] != 1) {
				matrix[i][j] = 'X';
			}
		}
	}

	//Output the revised matrix
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cout << matrix[i][j];
		}
		std::cout << std::endl;
	}

	return 0;
}

void stretch(int i, int j) {
	if (count == remainedNum) {
		return;
	}
	count++;
	tag[i][j] = 1;
	
	//Find the last position and set its tag to 1
	char last = '\0';
	if (i != 0) {
		if (tag[i - 1][j] == -1) {
			last = 'u';
			tag[i - 1][j] = 1;
		}
	}
	if (j != m - 1) {
		if (tag[i][j + 1] == -1) {
			last = 'r';
			tag[i][j + 1] = 1;
		}
	}
	if (i != n - 1) {
		if (tag[i + 1][j] == -1) {
			last = 'd';
			tag[i + 1][j] = 1;
		}
	}
	if (j != 0) {
		if (tag[i][j - 1] == -1) {
			last = 'l';
			tag[i][j - 1] = 1;
		}
	}

	//Stretch up
	if (i != 0) {
		if (matrix[i - 1][j] == '.' && last != 'u' && tag[i - 1][j] != 1) {
			tag[i][j] = -1;
			stretch(i - 1, j);
		}
	}
	
	//Stretch right
	if (j != m - 1) {
		if (matrix[i][j + 1] == '.' && last != 'r' && tag[i][j + 1] != 1) {
			tag[i][j] = -1;
			stretch(i, j + 1);
		}
	}
	
	//Stretch down
	if (i != n - 1) {
		if (matrix[i + 1][j] == '.' && last != 'd' && tag[i + 1][j] != 1) {
			tag[i][j] = -1;
			stretch(i + 1, j);
		}
	}

	//Stretch left
	if (j != 0) {
		if (matrix[i][j - 1] == '.' && last != 'l' && tag[i][j - 1] != 1) {
			tag[i][j] = -1;
			stretch(i, j - 1);
		}
	}

	tag[i][j] = 1;

	return;
}
