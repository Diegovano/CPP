#include <iostream>
#include "Token.h"

int Token::m_tokenQuant = 0;

double Token::retCont()
{
	return m_tokn;
}

double Token::charPtrDouble(const char *ent)
{
	unsigned int strSize = 0, numNums = 0;
	for (; ent[strSize] != '\0'; strSize++)
	{
		if (ent[strSize] != '.')numNums++;
	}
	if (numNums == 1 && *ent == '0') return 0;
	std::string intStr, dblStr;
	for (unsigned int iter = 0; iter < strSize; iter++)
	{
		if (ent[iter] == '.')
		{
			iter++;
			for (; iter < strSize; iter++)
			{
				dblStr.push_back(ent[iter]);
			}
		}
		else intStr.push_back(ent[iter]);
	}
	double convInt = 0, convDbl = 0;
	if (intStr.size() != 0)
	{
		for (unsigned int iter = 0; iter < intStr.size(); iter++)
		{
			convInt += (intStr[iter] - '0') * pow(10, intStr.size() - iter - 1);
		}
	}
	if (dblStr.size() != 0)
	{
		for (unsigned int iter = 0; iter < dblStr.size(); iter++)
		{
			convDbl += (dblStr[iter] - '0') * pow(10, dblStr.size() - iter - 1);
		}
		convDbl /= pow(10, dblStr.size());
	}
	return convInt + convDbl;
}

unsigned int OprdToken::retDigits(int ent)
{
	unsigned int digCount = 0;
	if (ent == 0) return 1;
	while (ent != 0)
	{
		ent /= 10;
		digCount++;
	}
	return digCount;
}