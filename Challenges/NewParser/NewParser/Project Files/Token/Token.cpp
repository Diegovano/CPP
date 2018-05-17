#include "Token.h"

unsigned int Token::tokNo()
{
	return m_tokenNo;
}

double Token::retCont()
{
	return m_tokn;
}

void Token::chgTokNo(unsigned int chgTokNo)
{
	m_tokenNo = chgTokNo;
}


double Token::charPtrDouble(const char *ent)
{
	unsigned int strSize = 0, numNums = 0;
	for (; ent[strSize] != '\0'; strSize++)
	{
		if (ent[strSize] != '.')numNums++;
	}
	if (numNums == 1 && *ent == '0') return 0;
	std::string intStr, dblStr;
	for (unsigned int iter = 0; iter < strSize; iter++)
	{
		if (ent[iter] == '.')
		{
			iter++;
			for (; iter < strSize; iter++)
			{
				dblStr.push_back(ent[iter]);
			}
		}
		else intStr.push_back(ent[iter]);
	}
	double convInt = 0, convDbl = 0;
	if (intStr.size() != 0)
	{
		for (unsigned int iter = 0; iter < intStr.size(); iter++)
		{
			convInt += (intStr[iter] - '0') * pow(10, intStr.size() - iter - 1);
		}
	}
	if (dblStr.size() != 0)
	{
		for (unsigned int iter = 0; iter < dblStr.size(); iter++)
		{
			convDbl += (dblStr[iter] - '0') * pow(10, dblStr.size() - iter - 1);
		}
		convDbl /= pow(10, dblStr.size());
	}
	return convInt + convDbl;
}

unsigned int OprtrToken::retPreced()
{
	return preced;
}

void OprtrToken::chgOprtr(const char ent)
{
	if (ent != '*' && ent != '/' && ent != '+' && ent != '-')
	{
		std::cerr << "chgOprtr() : Invalid Operator!" << std::endl;
		throw;
	}
	if (ent == '*' || ent == '/')preced = 2;
	else preced = 1;
	m_oprtr = ent;
	m_tokn = charPtrDouble(&ent) + '0';
}

unsigned int OprdToken::retDigits(int ent)
{
	unsigned int digCount = 0;
	if (ent == 0) return 1;
	while (ent != 0)
	{
		ent /= 10;
		digCount++;
	}
	return digCount;
}

void OprdToken::chgTokCont(double chgdTok)
{
	m_oprd = chgdTok;
	m_tokn = chgdTok;
}

double Bracket::getRes()
{
	return res;
}