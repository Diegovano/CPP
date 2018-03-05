#include <iostream>
#include <string>
#include <sstream>

int txtTobin();
int pwr(int, int);
std::string binTotxt(std::string);

int main() {
	int base1, exp1;
	bool selection = true;
	int mainInput;
	while (selection == true) {
		std::cout << "If you want to use the Text to Binary Converter, type 1. If you want to calculate powers of numbers type 2. If you want to use the Binary To Text Converter, type 3.\n";
		std::cin >> mainInput;
		std::cin.ignore();
		if (mainInput != 1 && mainInput != 2 && mainInput != 3) {
			std::cout << "What you entered wasn't one of the options proposed to you above.\n";
		}
		else if (mainInput == 1) {
			selection = false;
			txtTobin();
		}
		else if (mainInput == 2) {
			selection = false;
			std::cout << "Please enter the base of the number that you wish to raise to the power.\n";
			std::cin >> base1;
			std::cout << "Please enter the power that you wish to raise to.\n";
			std::cin >> exp1;
			pwr(base1, exp1);
		}
		else {
			std::string input;
			std::cout << "Enter a binary number to be converted into ASCII characters.\n";
			//			std::cin >> input;
			std::getline(std::cin, input);
			selection = false;
			std::cout << binTotxt(input) << std::endl;
		}
	}
	system("pause");
}

int pwr(int base, int exp) {
	if (exp == 0) return 1;
	const int origBase = base;
	for (; exp > 0; exp--) {
		base *= origBase;
	}
	return base;
}

int txtTobin() {
	std::string input;
	std::cout << "Enter a string to be converted to binary.\n";
	std::getline(std::cin, input);
	for (unsigned int i = 0; i < input.length(); i++) {
		char nthChar = input[i];
		int ascii = (int)nthChar;
		for (int i2 = 7; i2 >= 0; i2--) {
			std::cout << (ascii >> i2) % 2;
		}
		std::cout << ' ';
	}
	std::cout << std::endl;


	return 0;
}

std::string binTotxt(std::string input) {
//	int remainder = input.length() % 8;
	int sizeOfString = input.length();
	if (input.length() % 8 != 0) {
		return"failure";
	}
	int size = input.length() / 8;
	//	std::cout << size;
	std::string* bytes = new std::string[size];
	int bit = 0;
	for (int index = 0; index < size; index++) {
		int limitOfByte = bit + 8;
		for (; bit < limitOfByte; bit++) {
			bytes[index] += input[bit];
		}
	}
	std::string result;
	int pbits = 0;
	for (int pbytes = 0; pbytes < size; pbytes++) {
		char charOfByte = 0;
		for (pbits = 0; pbits < 8; pbits++) {
			int tempBit = (int)(bytes[pbytes][pbits]) % 2 << 7 - pbits;
			charOfByte += tempBit;
		}
		result += charOfByte;
	}
	return result;
}