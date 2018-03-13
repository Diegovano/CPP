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
			std::getline(std::cin, ent);
			Parser parse(ent.c_str());
//			Parser parse("65+6-5*2-1");
			std::cout << parse.getRes() << std::endl;
			system("pause");
		}
		catch (std::runtime_error)
		{
		}
	}
	return 0;
}