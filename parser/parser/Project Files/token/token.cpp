#include "token.h"

dString Token::retCont()
{
	return tokn;
}

int operandToken::retNumNumerals()
{
	return numOfNumerals;
}

void operandToken::castCharIntToInt()
{
	int conv = 0;
	unsigned int sizeOfEnt = 0;
	for (; tokn.str[sizeOfEnt] != '\0'; ++sizeOfEnt)
	for (unsigned int index = 0; index < sizeOfEnt; ++index)
	{
		conv += (tokn.str[sizeOfEnt - index - 1] - 48) * static_cast<int>(pow(10, index));
	}
	toknContInt = conv;
}
