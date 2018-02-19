#include <iostream>
#include "Project Files\parser\parser.h"

int main() {
	try
	{
		/*	dString entered;
			dString::getlne(std::cin, entered);
			parser parse(entered.str);
			parse.printAllTokens();*/
		std::cout << parser::castCharIntToInt("198") << std::endl;
		system("pause");
		return 0;
	}
	catch (std::runtime_error err)
	{
		std::cout << err.what() << std::endl;
		system("pause");
	}
}