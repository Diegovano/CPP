#include <iostream>
#include "Project Files\Token\Token.h"

int main()
{
	OprdToken pi("3.1415");
	OprdToken e(2.71828);
	OprtrToken oprtr1('*');
	std::cout << pi.retCont() << ' ' << pi.tokNo() << std::endl;
	std::cout << (char)oprtr1.retCont() << ' ' << oprtr1.tokNo() << std::endl;
	std::cout << e.retCont() << ' ' << e.tokNo() << std::endl;
	system("pause");
	return 0;
}