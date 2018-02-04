#include <iostream>
#include <string>

int main() {
	std::string str, tempStr;
	while (std::cin >> tempStr) {
		if (tempStr == '\n')break;
		str += tempStr;
		str += ' ';
	}
	std::cout << str << std::endl;
	system("pause");
}