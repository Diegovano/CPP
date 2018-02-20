#pragma once
#include "..\..\Dependecies\dStirng\dString.h"

class Token 
{
protected:
	static unsigned int tokQuant;
	unsigned int tokNo;
	dString tokn;
	Token() = default;
	Token(char *entTok) 
	{
		tokNo = tokQuant++;
		tokn = entTok;
	}
public:
	dString retCont();
	unsigned int retTokNo();
	static unsigned int retTokQuant();
};

class operatorToken : public Token 
{
private:
	unsigned int precedence;
	char oprtr;
public:
	operatorToken() = default;
	operatorToken(char tok) : Token::Token(&tok)
	{
		oprtr = tok;
		if (tok == '*' || tok == '/')precedence = 1;
		else if (tok == '+' || tok == '-')precedence = 0;
	}
	unsigned int retPrecedence();
	virtual char retCont();
};

class operandToken : public Token 
{
private:
	int toknContInt;
	unsigned int numOfNumerals;
public:
	operandToken() = default;
	operandToken(unsigned int tok)
	{

	}
	operandToken(char *tok) : Token::Token(tok)
	{
		for (unsigned int sizeOfEnt = 0; tokn.str[sizeOfEnt] != '\0'; ++sizeOfEnt)
		{
			if (tokn.str[sizeOfEnt] - 48 < 0 || tokn.str[sizeOfEnt] - 48 > 9) 
			{
				std::cout << "'" << tokn.str[sizeOfEnt] << "'" << std::endl;
				throw std::runtime_error("Invalid Character present! Cannot convert to numbers!");
			}
		}
		dString temp(tok);
		numOfNumerals = temp.ssize();
//		toknContInt = castCharIntToInt(tokn.str);
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

int castCharIntToInt(char *ent);
char* castIntToCharInt(int ent);
unsigned int retDigits(unsigned int ent);