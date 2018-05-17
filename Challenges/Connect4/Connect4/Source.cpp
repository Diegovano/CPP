#include <iostream>

void printArr(bool p_arr[7][6]);

int main() {
	bool horiz[7][6];
	for (int index = 0; index < 6; index++) {
		for (int index2 = 0; index2 < 7; index2++) {
			horiz[index][index2] = false;
		}
	}
	printArr(horiz);
	bool done = false;
	while (!done) {
		int select;
		std::cin >> select;
		if (!horiz[5][select - 1]) {
			horiz[5][select - 1] = true;
		}
		else if (horiz[0][select - 1]) {
			std::cout << "chose another row, this one is full.\n";
		}
		else {
			for (int index = 0; index < 6; index++) {
				if (horiz[index][select - 1]) {
					horiz[index - 1][select - 1] = true;
					break;
				}
			}
		}
		printArr(horiz);
		std::cout << "\n\n\n\n\n";
	}
	system("pause");
}

void printArr(bool p_arr[7][6]) {
	std::cout << "1 2 3 4 5 6 7" << std::endl;
	for (int index = 0; index < 6; index++) { //vert
		std::cout << std::endl;
		for (int index2 = 0; index2 < 7; index2++) { //horiz
			if (p_arr[index][index2]) std::cout << "X ";
			else std::cout << "O ";
		}
	}
	std::cout << std::endl;
}