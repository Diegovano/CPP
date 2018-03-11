#include <iostream>
#include <string>
#include "Project Files\Parser\Parser.h"

int main()
{
BEGIN:
	try
	{
		system("cls");
		std::string ent;
		std::getline(std::cin, ent);
		Parser parse(ent.c_str());
//		Parser parse("329.99*60/100");
		std::cout << parse.getRes() << std::endl;
		system("pause");
		goto BEGIN;
	}
	catch (std::runtime_error)
	{
		goto BEGIN;
	}
	return 0;
}