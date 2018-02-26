#include "token.h"

unsigned int Token::tokQuant = 0;


//getters
int operandToken::retNumNumerals()
{
	return numOfNumerals;
}

void Token::chgTok(const char *ent)
{
	tokn = ent;
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