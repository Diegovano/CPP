#include <iostream>
#include <string>
//#include <stdexcept>
//#include <vector>

std::string::size_type find_char(const std::string &str, char ch, int &occurs) {
	size_t ret = str.size();
	for (decltype(str.size()) i = 0; i != str.size(); ++i) {
		if (str[i] == ch) {
			++occurs;
			if (ret == str.size())ret = i;
		}
	}
	if (ret == str.size()) throw std::runtime_error("Char not present in string!");
	return ret;
}

int main(void) {
	try {
		std::string entd;
		char charT;
		int occurs = 0;
		std::getline(std::cin, entd);
		std::cin >> charT;
		int loc = find_char(entd, charT, occurs);
		std::string particle = (loc == 0) ? "st" :
			(loc == 1) ? "nd" :
			(loc == 2) ? "rd" : "th";
		std::string time = (occurs == 1) ? " Time." : " Times.";
		std::cout << "In the String \"" << entd << "\" the Character '" << charT << "' Occurs "
			<< occurs << time << std::endl << "Its First Apperearence is at the " << loc + 1
			<< particle << " Character." << std::endl;
		system("pause");
		return 0;
	}
	catch (std::runtime_error err) {
		std::cout << err.what()
			<< std::endl << "Please restart the program and enter a character present in the string!"
			<< std::endl;
		system("pause");
	}
}