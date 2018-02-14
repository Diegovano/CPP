#include <iostream>
#include "Dependecies\vector\vector.h"
//#include "Project Files\parser\parser.h"

int main() {
	vector<int> vec;
	for (unsigned int index = 0; index < 100; ++index)
	{
		vec.pushBack(index);
	}
	vec.printVec();
/*	dString entered;
	dString::getlne(std::cin, entered);
	parser parse(entered.str);*/
	system("pause");
	return 0;
}