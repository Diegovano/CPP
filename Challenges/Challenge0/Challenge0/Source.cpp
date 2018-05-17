#include <iostream>

const int size = 10;

int * sort(int * toSort, int * toSortCopy) {
	int * sortedInts = new int[size];
	bool sorted = false;
	for (int prog = 0; prog < size * 10; prog++) {
		for (int i = 0; i < size; i++) {
//			std::cout << toSort[i] << " " << i << std::endl;
			if (i + 1 > size - 1);
			else if (toSort[i] < toSort[i + 1]) {
			}
			else {
				toSort[i] = toSort[i + 1];
				toSort[i + 1] = toSortCopy[i];
				for (int i2 = 0; i2 < size; i2++) {
					toSortCopy[i2] = toSort[i2];
				}
			}
			for (int i2 = 0; i2 < size; i2++) {
				if (i2 + 1 > size - 1)sorted = true;
				if (toSort[i2] <= toSort[i2 + 1]) sorted = true;
				else {
					sorted = false;
					break;
				}
			}
		}
	}
//	for (int i = 0; i < size; i++)sortedInts[i] = toSort[i];
	return toSort;
}

int main() {
	int range;
	int srtdNums[size];
	int*numbersCopy = new int[size];
	int * numbers = new int[size];
	int init[size] = { 234, 12, 51, 51, 542, 4, 6, 2165, 784, 68 };
	for (int i = 0; i < size; i++) {
		numbers[i] = init[i];
		numbersCopy[i] = init[i];
	}
	int * sortedArray = new int[size];
	sort(numbers, numbersCopy);
	range = numbers[size-1] - numbers[(size-1) - (size-1)];
	std::cout << "The Range of the numbers is " << range << ".\n";
	int  i = 0;
	int average = 0;
	for (; i < size; i++)average = average + numbers[i];
	average = average / (i + 1);
	std::cout << "The Average of the numbers is " << average << ".\n";
	std::cout << "The Numbers are: ";
	for (int i = 0; i < size; i++)std::cout << numbers[i] << ", ";
	std::cout << "\n";
//	for (int i = 0; i < 10; i++) std::cout << numbers[i] << std::endl;
	system("pause");
}