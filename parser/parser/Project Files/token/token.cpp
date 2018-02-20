#include "token.h"

unsigned int Token::tokQuant = 0;


//getters
int operandToken::retNumNumerals()
{
	return numOfNumerals;
}
dString Token::retCont()
{
	return tokn;
}

char operatorToken::retCont()
{
	return oprtr;
}

unsigned int Token::retTokNo()
{
	return tokNo;
}

unsigned int Token::retTokQuant()
{
	return tokQuant;
}

unsigned int operatorToken::retPrecedence()
{
	return precedence;
}

//outside class
int castCharIntToInt(char *ent)
{
	int conv = 0;
	unsigned int sizeOfEnt = 0;
	for (; ent[sizeOfEnt] != '\0'; ++sizeOfEnt)
	for (unsigned int index = 0; index < sizeOfEnt; ++index)
	{
		conv += (ent[sizeOfEnt - index - 1] - 48) * static_cast<int>(pow(10, index));
	}
	return conv;
}

char* castIntToCharInt(int ent)
{
	dString temp(retDigits(ent));
	for (unsigned int iter = 0; iter < retDigits(ent); ++iter)
	{
		temp.pushBack(char(ent / pow(10, retDigits(ent) - iter)+'0'));
//		ent -= ent/pow(10,retDigits())
	}
	return temp.str;
}

unsigned int retDigits(unsigned int ent)
{
	unsigned int digits = 0;
	if (ent == 0)return 1;
	while (ent)
	{
		ent /= 10;
		++digits;
	}
	return digits;
}