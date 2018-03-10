#include <iostream>
#include <string>
#include "Project Files\Parser\Parser.h"

int main()
{
	std::string ent;
	std::getline(std::cin, ent);
	Parser parse(ent.c_str());
	std::cout << parse.getRes() << std::endl;
	system("pause");
	return 0;
}