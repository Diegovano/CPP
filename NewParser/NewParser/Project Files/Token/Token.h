#pragma once
#include <iostream>

class Token
{
protected:
	Token(double entTok) : m_tokn(entTok), m_tokenNo(++m_tokenQuant)
	{
	}

	double m_tokn;
	unsigned int m_tokenNo;
	static int m_tokenQuant;
	double charPtrDouble(const char *ent);
public:
	virtual ~Token()
	{
		m_tokenQuant--;
	}

	static unsigned int tokQuant();

	unsigned int tokNo();
	virtual double retCont();
	void chgTokNo(unsigned int chgTokNo);
};

class OprtrToken : public Token
{
	char m_oprtr;
	unsigned int preced;
public:
	OprtrToken(const char entTok) : m_oprtr(entTok), Token(charPtrDouble(&entTok) + '0')
	{
		if (m_oprtr != '*' && m_oprtr != '/' && m_oprtr != '+' && m_oprtr != '-') throw std::runtime_error("OprtrToken() : Invalid Operator!");
		if (m_oprtr == '*' || m_oprtr == '/')preced = 2;
		else preced = 1;
	}

	unsigned int retPreced();

};

class OprdToken : public Token
{
	double m_oprd;
	unsigned int retDigits(int ent);
public:
	OprdToken(double entTok) : m_oprd(entTok), Token(entTok)
	{
	}
	OprdToken(const char *entTok) : m_oprd(charPtrDouble(entTok)), Token(charPtrDouble(entTok))
	{
	}

	void chgTokCont(double chgdTok);
};

class BrackToken : public Token
{

};