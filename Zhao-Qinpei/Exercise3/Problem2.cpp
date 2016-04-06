#include <iostream>
#include <string>

using namespace std;

template <typename T>
void bubbleSort(T arr[], int length) {
	//This function is used to sort the array by Bubble sorting algorithm
	for (int i = 0; i <= length - 2; i++) {
		for (int j = 0; j <= length - 2 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				T temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	return;
}

template <typename T>
void displaySorting(T arr[], int length) {
	//Print out initial order
	cout << "Before sorting: ";
	for (int i = 0; i <= length - 1; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;

	bubbleSort(arr, length);

	//Print out sorted order
	cout << "After sorting: ";
	for (int i = 0; i <= length - 1; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;

	return;
}

int main() {
	int intArr[10] = { 3, 5, 7, 6, 4, 2, 9, 10, 1, 8 };
	displaySorting(intArr, 10);
	
	float floatArr[5] = { 3.14f, 6.66f, 2.7f, 1024.2048f, 17.25f };
	displaySorting(floatArr, 5);
	
	string strArr[5] = { "Derek", "Dick", "Frank", "XXX", "DerekDick" };
	displaySorting(strArr, 5);
	
	return 0;
}