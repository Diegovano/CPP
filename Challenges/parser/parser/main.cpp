#include <iostream>
#include "Project Files\parser\parser.h"

int main() {
BEGIN:	try
	{
		dString entered;
		dString::getlne(std::cin, entered);
		parser parse(entered.str);
//		parser parse("12*5+5");
//		parse.printAllTokens();
		parse.printRes();
		system("pause");
		return 0;
	}
	catch (std::exception err)
	{
		std::cout << err.what() << std::endl;
		system("pause");
		goto BEGIN;
	}
}