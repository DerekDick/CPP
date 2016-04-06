#include <iostream>
#include <vector>

using namespace std;

int josephPerm(int n, int m);

int main() {
	//Prompt to input
	int n, m;
	cout << "Please input n(a positive integer) :" << endl;
	cin >> n;
	cout << "Please input m(a positive integer) :" << endl;
	cin >> m;

	cout << "The lucky one alive: " << josephPerm(n, m) << endl;

	return 0;
}

int josephPerm(int n, int m) {
	//This function is used to find the lucky one in a group sorted by Josephus Permutation
	//Declaration and initialization of the container
	vector<int> vec;
	for (int i = 1; i <= n; i++) {
		vec.push_back(i);
	}

	for (int i = 1, j = 0; i <= (n - 1)*m; i++) {
		//Find the next one alive
		while (vec[j] == 0) {
			if (j == n - 1)
				j = 0;
			else
				j++;
		}

		//Kill the current one if he is unlucky
		if (i % m == 0) {
			vec[j] = 0;
		}

		//Set to the next one
		if (j == n - 1)
			j = 0;
		else
			j++;
	}

	//Find the lucky one who is sitll alive
	for (int i = 0; i <= n - 1; i++) {
		if (vec[i] != 0)
			return vec[i];
	}
}