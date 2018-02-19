#pragma once
#include "..\..\Dependecies\dStirng\dString.h"

class Token 
{
protected:
	dString tokn;
	Token() = default;
	Token(char *entTok) 
	{
		tokn = entTok;
	}
public:
	dString retCont();
};

class operatorToken : public Token 
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

class operandToken : public Token 
{
private:
	int toknContInt;
	unsigned int numOfNumerals;
	void castCharIntToInt();
public:
	operandToken() = default;
	operandToken(char *tok) : Token::Token(tok)
	{
		for (unsigned int sizeOfEnt = 0; tokn.str[sizeOfEnt] != '\0'; ++sizeOfEnt)
		{
			if (tokn.str[sizeOfEnt] - 48 < 0 || tokn.str[sizeOfEnt] - 48 > 9)throw std::runtime_error("Invalid Character present! Cannot convert numbers!");
		}
		dString temp(tok);
		numOfNumerals = temp.ssize();
		castCharIntToInt();
	}
	int retNumNumerals();
};

class bracketToken : public Token 
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
