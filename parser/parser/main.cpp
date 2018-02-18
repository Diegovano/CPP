#include <iostream>
#include "Project Files\parser\parser.h"

int main() {
	dString entered;
	dString::getlne(std::cin, entered);
	parser parse(entered.str);
	parse.printAllTokens();
	system("pause");
	return 0;
}