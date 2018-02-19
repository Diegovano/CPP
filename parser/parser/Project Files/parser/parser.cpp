#include "parser.h"

void parser::tokeniseStr()
{
	for (unsigned int iter = 0; iter < entStr.ssize(); ++iter)
	{
		if (isCharOperator(entStr[iter]) && isCharOperator(entStr[iter + 1]))
		{
			std::cout << "'" << entStr[iter] << "' and '" << entStr[iter + 1] << "'" << std::endl;
			throw std::exception("Math Error, cannot have two operators in succession!");
		}
	}
	for (size_t iter = 0; iter < entStr.ssize(); ++iter)
	{
		dString tempStr; 
		for (; !isCharOperator(entStr[iter]) && iter < entStr.ssize(); ++iter)
		{
			tempStr.pushBack(entStr[iter]);
		}
		oprdToken.pushBack(new operandToken(tempStr.str));
		if(iter < entStr.ssize())
		oprtrToken.pushBack(new operatorToken(entStr[iter]));
	}
}

void parser::parse()
{
	for (unsigned int iter = 0; iter < oprtrToken.size(); ++iter)
	{
		if (oprtrToken[iter]->retPrecedence() == 2)
		{
			if (oprtrToken[iter]->retCont == '*')
			{
				resTokens.pushBack(new operandToken()
			}
		}
	}
}

Token* parser::searchID(unsigned int searchID)
{
	if (searchID > Token::retTokQuant())throw std::exception("There is no token with that identifier!");
	for (unsigned int index = 0; index < Token::retTokQuant();)
	{
		for (; index < oprdToken.size(); ++index)
		{
			if (oprdToken[index]->retTokNo == searchID)return oprdToken[index];
		}
		for (; index - oprdToken.size() < oprtrToken.size(); ++index)
		{
			if (oprtrToken[index]->retTokNo == searchID)return oprtrToken[index];
		}
	}
}

dString parser::retStr() 
{ 
	return entStr;
}

void parser::printAllTokens()
{
	std::cout << "Printing Operand Tokens...\n";
	for (size_t iter = 0; iter < oprdToken.size(); ++iter)
	{
		std::cout << oprdToken[iter]->retCont() << " Token Number is: " << oprdToken[iter]->retTokNo() << std::endl;
	}
	std::cout << "Printing Operator Tokens...\n";
	for (size_t iter = 0; iter < oprtrToken.size(); ++iter)
	{
		std::cout << oprtrToken[iter]->retCont() << " Token Number is: " << oprtrToken[iter]->retTokNo() << std::endl;
	}
}

bool isCharOperator(char ent)
{
	if (ent == '/' || ent == '*' || ent == '+' || ent == '-')
	{
		return true;
	}
	return false;
}