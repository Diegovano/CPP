#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "..\Token\Token.h"


class Parser
{
	std::string m_str;
	std::vector<OprtrToken*> m_oprtrToken;
	std::vector<OprdToken*> m_oprdToken;

	double res;

	bool checkOprtrs();
	void tokenise();
	void parse();
	void resolve(OprdToken* lhOprd, double res);
	Token* searchFor(unsigned int searchFor);
	OprdToken* searchOprd(unsigned int searchFor);
	OprtrToken* searchOprtr(unsigned int searchFor);
	unsigned int retIndexOprtrVec(OprtrToken *oprtr);
	unsigned int retIndexOprdVec(OprdToken *oprd);
public:
	Parser(const char *entStr)
	{
		for (unsigned int iter = 0; entStr[iter] != '\0'; iter++)
		{
			if (entStr[iter] != ' ')m_str.push_back(entStr[iter]);
		}
		if (!checkOprtrs())
		{
			std::cerr << "Parser: Constr char*: 2 Operators in succession, invalid String!" << std::endl;
			system("pause");
			throw;
		}
		tokenise();
		parse();
	}

	double getRes();
	void printTokens();

	~Parser()
	{
		delete m_oprdToken[0];
	}
};

bool isOperator(char ent);