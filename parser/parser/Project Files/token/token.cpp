#include "token.h"

dString Token::retCont()
{
	return tokn;
}

int operandToken::retNumNumerals()
{
	return numOfNumerals;
}

int operandToken::castCharIntToInt()
{
	int conv = 0;
	unsigned int sizeOfEnt = 0;
	//check that all chars are numbers
	for (; tokn.str[sizeOfEnt] != '\0'; ++sizeOfEnt)
	{
		if (tokn.str[sizeOfEnt] - 48 < 0 || tokn.str[sizeOfEnt] - 48 > 9)throw std::runtime_error("Invalid Character present! Cannot convert numbers!");
	}
	for (unsigned int index = 0; index < sizeOfEnt; ++index)
	{
		conv += (tokn.str[sizeOfEnt - index - 1] - 48) * static_cast<int>(pow(10, index));
	}
	return conv;
}
