#include "parser.h"
#include"..\charIntConv\charIntConv.h"

void parser::tokeniseStr()
{
	for (unsigned int iter = 0; iter < entStr.ssize(); ++iter)
	{
		if (isCharOperator(entStr[iter]) && isCharOperator(entStr[iter + 1]))
		{
			std::cout << "'" << entStr[iter] << "' and '" << entStr[iter + 1] << "'" << std::endl;
			throw std::exception("parser: tokeniseStr(): Math Error, cannot have two operators in succession!");
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
		switch (oprtrToken[iter]->retCont())
		{
		case('*'):
		{
			int res = castCharIntToInt(searchID(oprtrToken[iter]->retTokNo() - 1)->retCont().str) *
				castCharIntToInt(searchID(oprtrToken[iter]->retTokNo() + 1)->retCont().str);
			searchID(oprtrToken[iter]->retTokNo() - 1)->chgTok(castIntToCharInt(res));
			resolveToken(searchID(oprtrToken[iter]->retTokNo() - 1), iter);
			break;
		}
		case('/'):
		{
			int res = castCharIntToInt(searchID(oprtrToken[iter]->retTokNo() - 1)->retCont().str) /
				castCharIntToInt(searchID(oprtrToken[iter]->retTokNo() + 1)->retCont().str);
			searchID(oprtrToken[iter]->retTokNo() - 1)->chgTok(castIntToCharInt(res));
			resolveToken(searchID(oprtrToken[iter]->retTokNo() - 1), iter);
			break;
		}
		}
	}
	for (unsigned int iter = 0; iter < oprtrToken.size(); ++iter)
	{
		switch (oprtrToken[iter]->retCont())
		{
		case('+'):
		{
			int res = castCharIntToInt(searchID(oprtrToken[iter]->retTokNo() - 1)->retCont().str) +
				castCharIntToInt(searchID(oprtrToken[iter]->retTokNo() + 1)->retCont().str);
			searchID(oprtrToken[iter]->retTokNo() - 1)->chgTok(castIntToCharInt(res));
			resolveToken(searchID(oprtrToken[iter]->retTokNo() - 1), iter);
			break;
		}
		case('-'):
		{
			int res = castCharIntToInt(searchID(oprtrToken[iter]->retTokNo() - 1)->retCont().str) -
				castCharIntToInt(searchID(oprtrToken[iter]->retTokNo() + 1)->retCont().str);
			searchID(oprtrToken[iter]->retTokNo() - 1)->chgTok(castIntToCharInt(res));
			resolveToken(searchID(oprtrToken[iter]->retTokNo() - 1), iter);
			break;
		}
		}
	}
}

void parser::resolveToken(Token *tok, const unsigned int &indexOfTok)
{
	delete searchID(tok->retTokNo() + 1);
	delete searchID(tok->retTokNo() + 2);
	oprtrToken.remove(indexOfTok);
//	oprdToken.remove()
	if (Token::retTokQuant() == 3)
	{
		Token::tokQuant = 1;
		return;
	}
	for (unsigned int iter = tok->retTokNo() + 3; iter < Token::retTokQuant() - 1; ++iter)
	{
		searchID(iter)->tokNo = iter - 2;
	}
	Token::tokQuant -= 2;
}

Token* parser::searchID(unsigned int searchID)
{
	if (searchID > Token::retTokQuant() - 1)throw std::exception("parser: searchID(unsigned int searchID): There is no token with that identifier!");
	for (unsigned int index = 0; index < oprdToken.size(); ++index)
	{
		if (oprdToken[index]->retTokNo() == searchID)return oprdToken[index];
	}
	for (unsigned int index = 0; index < oprtrToken.size(); ++index)
	{
		if (oprtrToken[index]->retTokNo() == searchID)return oprtrToken[index];
	}
	return nullptr;
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

void parser::printRes()
{
	std::cout << castCharIntToInt(oprdToken[0]->retCont().str) << std::endl;
}

bool isCharOperator(char ent)
{
	if (ent == '/' || ent == '*' || ent == '+' || ent == '-')
	{
		return true;
	}
	return false;
}