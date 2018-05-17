#pragma once
#include "..\..\Dependecies\dStirng\dString.h"
#include "..\token\token.h"
#include "..\..\Dependecies\vector\vector.h"

class parser 
{
private:
	double res;
	dString entStr; //Without spaces
	vector<operandToken*> oprdToken;
	vector<operatorToken*> oprtrToken;
	void tokeniseStr();
	void parse();
	void resolveToken(Token *tok, const unsigned int &indexOfTok);
	Token* searchID(unsigned int searchID);
public:
	parser(char *ent) 
	{
		dString temp = ent;
		for (size_t iter = 0; iter < temp.ssize(); ++iter) 
		{
			if (temp[iter] != ' ')entStr.pushBack(temp[iter]);
		}
		tokeniseStr();
		parse();
	}
	dString retStr();
	void printAllTokens();
	void printRes();
};

bool isCharOperator(char ent);