#include <iostream>
#include <string>
#include <vector>
#include "Header.h"

int main()
{
	while (1)
	{
		unsigned short base;
		std::string ent;
		std::cout << "What is the base of the input?" << std::endl;
		std::cin >> base;
		std::cout << "Please enter value to convert." << std::endl;
		std::cin >> ent;
		std::vector<int> vec = retValDecVal(ent);
		int res = 0;
		for (unsigned int iter = 0; iter < vec.size(); ++iter)
		{
			res += vec[iter] * pow(base, vec.size() - iter - 1);
		}
		std::cout << res << std::endl;
		system("pause");
	}
	return 0;
}

inline std::vector<int> retValDecVal(std::string str)
{
	std::vector<int> convVec;
	for (char &ch : str)
	{
		if (ch < 91 && ch > 64) //if btwn A & Z
		{
			convVec.push_back(ch - 55); //(int)A = 65  65 - 55 = 10 1,2,3,4,5,6,7,8,9,A etc...
		}
		else if (ch < 58 && ch > 47) //if btwn 0 & 9
		{
			convVec.push_back(ch - 48);
		}
		else
		{
			std::cerr << "Invalid character!" << std::endl;
			system("pause");
			throw;
		}
	}
	return convVec;
}