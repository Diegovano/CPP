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

/*int main()
{
	derivedClass derCl("BAll is good!");
	if (derCl.isA()) std::cout << "True!\n";
	else std::cout << "False!\n";
	derivedClass *arrOfDer = new derivedClass[5];
	arrOfDer->changeStr("Anything!");
	if (arrOfDer->isA()) std::cout << "True!\n";
	else std::cout << "False!\n";
	system("pause");
}*/

int main()
{
	char *foo = "192";
	int bar = 0;
	unsigned int sizeOfFoo = 0;
	for (; foo[sizeOfFoo] != '\0'; ++sizeOfFoo);
	for (unsigned int index = 0; index < sizeOfFoo; ++index)
	{
		bar += (foo[sizeOfFoo - index - 1] - 48) * pow(10, index);
	}
	std::cout << bar << std::endl;
	system("pause");
}