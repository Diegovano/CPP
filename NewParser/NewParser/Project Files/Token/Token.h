#pragma once
#include <iostream>

class Token
{
protected:
	Token(double entTok, unsigned int entTokNo) : m_tokn(entTok), m_tokenNo(entTokNo)
	{
	}

	double m_tokn;
	unsigned int m_tokenNo;
	double charPtrDouble(const char *ent);
public:
	virtual ~Token()
	{
//		std::cout << "Destructor called!" << std::endl;
	}

	unsigned int tokNo();
	virtual double retCont();
	void chgTokNo(unsigned int chgTokNo);
};

class OprtrToken : public Token
{
	char m_oprtr;
	unsigned int preced;
public:
	OprtrToken(const char entTok, unsigned int entTokNo) : m_oprtr(entTok), Token(charPtrDouble(&entTok) + '0', entTokNo)
	{
		if (m_oprtr != '*' && m_oprtr != '/' && m_oprtr != '+' && m_oprtr != '-')
		{
			std::cerr << "OprtrToken() : Invalid Operator!" << std::endl;
			system("pause");
			throw;
		}
		if (m_oprtr == '*' || m_oprtr == '/')preced = 2;
		else preced = 1;
	}

	unsigned int retPreced();
	void chgOprtr(const char ent);

};

class OprdToken : public Token
{
	double m_oprd;
	unsigned int retDigits(int ent);
public:
	OprdToken(double entTok, unsigned int entTokNo) : m_oprd(entTok), Token(entTok, entTokNo)
	{
	}
	OprdToken(const char *entTok, unsigned int entTokNo) : m_oprd(charPtrDouble(entTok)), Token(charPtrDouble(entTok), entTokNo)
	{
	}

	void chgTokCont(double chgdTok);
};

class Bracket
{
	const char* contBrack;
	double res;
public:
	Bracket(const char* entCont); //Defined in Parser.cpp

	double getRes();
};