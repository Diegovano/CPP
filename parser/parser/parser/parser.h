#pragma once
#include "..\Dependecies\dStirng\dString.h"
#include "token.h"

class parser {
private:
	dString entStr; //Without spaces
public:
	parser(char *ent) {
		dString temp = ent;
		for (int iter = 0; iter > temp.ssize(); ++iter) {
			if (temp[iter] == ' ');
			entStr.pushBack(temp[iter]);
		}
	}

};
