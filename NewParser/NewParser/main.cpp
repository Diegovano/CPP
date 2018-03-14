#include <iostream>
#include <string>
#include "Project Files\Parser\Parser.h"

int main()
{
	while (1)
	{
		try
		{
			system("cls");
			std::string ent;
//			std::getline(std::cin, ent);
//			Parser* parse = new Parser(ent.c_str());
			Parser* parse = new Parser("20*(4+(2/(4-2)))");
			std::cout << parse->getRes() << std::endl;
			system("pause");
			delete parse;
		}
		catch (std::runtime_error)
		{
		}
	}
	return 0;
}