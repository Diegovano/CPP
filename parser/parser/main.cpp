#include <iostream>
#include "Project Files\parser\parser.h"

int main() {
	dString entered;
	dString::getlne(std::cin, entered);
	parser parse(entered.str);
	system("pause");
	return 0;
}