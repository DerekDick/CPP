#include <iostream>

using namespace std;

bool square[4][4]; //The 4x4 square

bool isPossible(int i, int j);

int main() {
	//Input the 4x4 square
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			char c;
			cin >> c;
			if (c == '.') {
				square[i][j] = true;
			}
			else {
				square[i][j] = false;
			}
		}
	}

	//Judge if it is possible
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (isPossible(i, j)) {
				cout << "YES" << endl;
				exit(1);
			}
		}
	}
	cout << "NO" << endl;

	return 0;
}

bool isPossible(int i, int j) {
	/*This function is used to check if it is possible 
	to make a 2x2 square start at (i, j) with the same color*/
	int judgeNum = square[i][j] + square[i][j + 1] + square[i + 1][j] + square[i + 1][j + 1];
	if (judgeNum == 0 || judgeNum == 1 || judgeNum == 4 || judgeNum == 3) {
		return true;
	}
	else {
		return false;
	}
}
