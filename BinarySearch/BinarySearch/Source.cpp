/*
* Source.cpp
*
*  Created on: Oct 24, 2015
*      Author: Sadra
*/

#include <iostream>
#include <cstdlib>

using namespace std;

void sort(int[], int);
bool search(int[], int, int, int);

int main() {
	int size, user_number;
	cout << "Please enter the size of your array : ";
	cin >> size;
	int array[size];
	for (int i = 0; i < size; i++) {
		cout << "Number, " << i + 1 << " : ";
		cin >> array[i];
	}
	cout << "==================================================" << endl;
	sort(array, size);
	cout << "Sorted array : " << endl;
	for (int i = 0; i < size; i++) {
		cout << array[i] << "\t";
	}
	cout << endl;
	cout << "==================================================" << endl;
	cout << "Enter a number to search in array : ";
	cin >> user_number;
	if (search(array, 0, size - 1, user_number)) {
		cout << "Your number was found !" << endl;
	}
	else {
		cout << "Your number was not found !!!" << endl;
	}
	system("pause");
	return 0;
}

void sort(int array[], int size) {
	for (int i = size - 1; i >= 0; i--) {
		int max_index = i;
		for (int j = 0; j < i; j++) {
			if (array[j] > array[max_index]) {
				max_index = j;
			}
		}
		int tmp = array[i];
		array[i] = array[max_index];
		array[max_index] = tmp;
	}
}

bool search(int array[], int a, int b, int target) {
	if (a == b) {
		return false;
	}
	int middle_index = (b + a) / 2;
	if (target < array[middle_index]) {
		return search(array, a, middle_index, target);
	}
	else if (target > array[middle_index]) {
		return search(array, middle_index, b, target);
	}
	else {
		return true;
	}
}
