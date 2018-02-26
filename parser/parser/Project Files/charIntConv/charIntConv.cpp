#include "..\..\Dependecies\dStirng\dString.h"

unsigned int retDigits(unsigned int ent);

int castCharIntToInt(char *ent)
{
	int conv = 0;
	unsigned int sizeOfEnt = 0;
	for (; ent[sizeOfEnt] != '\0'; ++sizeOfEnt);
		for (unsigned int index = 0; index < sizeOfEnt; ++index)
		{
			conv += (ent[sizeOfEnt - index - 1] - 48) * static_cast<int>(pow(10, index));
		}
	return conv;
}

char* castIntToCharInt(int ent) 
{
	unsigned int numDigits = retDigits(ent);
	dString res(numDigits);
	for (unsigned int iter = 0; iter < numDigits; ++iter)
	{
		res[numDigits - iter - 1] = char(ent % 10 + '0');
		ent -= ent % 10;
		ent /= 10;
	}
	std::cout << res << std::endl;
	return res.str;
}
unsigned int retDigits(unsigned int ent)
{
	unsigned int digits = 0;
	if (ent == 0)return 1;
	while (ent)
	{
		ent /= 10;
		++digits;
	}
	return digits;
}