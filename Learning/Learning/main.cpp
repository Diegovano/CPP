#include <iostream>

class baseClass
{
private:
	char *str;
public:
	baseClass() = default;
	baseClass(char *ent) : str(ent)
	{
	}
	void changeStr(char *ent)
	{
		str = ent;
	}
};

class derivedClass : public baseClass
{
private:
	bool isItA;
public:
	derivedClass() = default;
	derivedClass(char *ent) : baseClass(ent), isItA(0)
	{
		if (*ent == 'A')isItA = 1;
	}
	bool isA()
	{
		return isItA;
	}
};

int main()
{
	derivedClass derCl("BAll is good!");
	if (derCl.isA()) std::cout << "True!\n";
	else std::cout << "False!\n";
	derivedClass *arrOfDer = new derivedClass[5];
	arrOfDer->changeStr("Anything!");
	if (arrOfDer->isA()) std::cout << "True!\n";
	else std::cout << "False!\n";
	system("pause");
}