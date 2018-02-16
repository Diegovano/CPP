#pragma once
#include "..\..\Dependecies\dStirng\dString.h"
#include "..\token\token.h"
#include "..\..\Dependecies\vector\vector.h"

class parser 
{

private:
	dString entStr; //Without spaces
	vector<operandToken> oprdToken;
	vector<operatorToken> oprtrToken;
public:
	parser(char *ent) 
	{
		dString temp = ent;
		for (size_t iter = 0; iter < temp.ssize(); ++iter) 
		{
			if (temp[iter] != ' ')entStr.pushBack(temp[iter]);
		}
		tokeniseStr();
	}
	void tokeniseStr();
	dString retStr();
};

bool isCharOperator(char ent);