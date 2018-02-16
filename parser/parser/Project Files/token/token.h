#pragma once
#include "..\..\Dependecies\dStirng\dString.h"

class Token 
{
protected:
	dString tokn;
	Token(char *entTok) 
	{
		tokn = entTok;
	}
};

class operatorToken : protected Token 
{
private:
	int precedence;
public:
	operatorToken() = default;
	operatorToken(char tok) : Token::Token(&tok)
	{
		if (tok == '*' || tok == '/')precedence = 1;
		else if (tok == '+' || tok == '-')precedence = 0;
	}
};

class operandToken : protected Token 
{
private:
	unsigned int numOfNumerals;
public:
	operandToken(char *tok) : Token::Token(tok)
	{
		dString temp(tok);
		numOfNumerals = temp.ssize();
	}
	int retNumNumerals();
};

class bracketToken : protected Token 
{
private:
	dString contOfBrack;
public:
	bracketToken(char *tok) : Token::Token(tok) 
	{
		dString temp(tok);
		for (unsigned int iter = 1; iter < temp.ssize() - 1; ++iter) 
		{
			contOfBrack.pushBack(temp[iter]);
		}
	}
};
