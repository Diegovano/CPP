#include <iostream>

int number1 = 1;
int number2 = 1;

/* int main() {
	std::cout << number1 << std::endl << number2 << std::endl;
	for (int i = 0; i < 10; i++) {
		std::cout << (number1 + number2) << std::endl;
		number1 = number1 + number2;
		std::cout << (number1 + number2) << std::endl;
		number2 = number2 + number1;
//		11235813
//		system("pause");
	}
	system("pause");
} */

int main() {
	const unsigned int sizeOfSequence = 10;
	int fibSequence[sizeOfSequence];
	fibSequence[0] = 0;
	fibSequence[1] = 1;
	for (unsigned int index = 2; index < sizeOfSequence; index++) 
		fibSequence[index] = fibSequence[index - 1] + fibSequence[index - 2];
	for (unsigned int index = 0; index < sizeOfSequence; index++)
		std::cout << fibSequence[index] << std::endl;
	system("pause");
}