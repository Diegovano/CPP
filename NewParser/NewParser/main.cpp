#include <iostream>
#include "Project Files\Token\Token.h"

int main()
{
	OprdToken pi("3.1415");
	OprdToken e(2.71828);
	OprtrToken oprtr1('*');
	std::cout << pi.retCont() << std::endl;
	std::cout << oprtr1.retCont() << std::endl;
	std::cout << e.retCont() << std::endl;
	system("pause");
	return 0;
}