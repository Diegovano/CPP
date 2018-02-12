#include <iostream>
#include "string.h"

const char* dString::returnStr() const
{
	return str;
}

const size_t dString::ssize(void) {
	size_t nCharLoc = 0;
	for (; this->str[nCharLoc] != '\0'; ++nCharLoc);
	return nCharLoc;
}

const void dString::getlne(std::istream& is, dString &obj) {
	dString cont;
	while (std::cin >> cont) {
		obj.pushBack(cont.str);
		if (is.peek()=='\n') return;
		obj.pushBack(' ');
	}
	
}

const char dString::operator[](const size_t loc) {
	return this->str[loc];
}

void dString::pushBack(const char *ent) {
	dString temp(ent);
	*this += temp;
}

void dString::pushBack(const char ent) {
	dString temp(&ent);
	*this += temp;
}

const dString& dString::operator+=(dString obj) {
	dString temp(this->ssize() + obj.ssize());
	for (size_t index = 0; index < this->ssize(); ++index) temp.str[index] = this->str[index];
	for (size_t index = 0; index <= obj.ssize(); ++index) temp.str[this->ssize() + index] = obj.str[index]; //index<=obj.size to inc '\0'
	this->str = temp.str;
	return *this;
}

const dString& dString::operator+=(const size_t sze) {
	dString temp(sze);
	return *this += temp;
}

const dString dString::operator+(dString &obj) {
	dString temp("");
	temp += *this;
	temp += obj;
	return temp;
}

const dString dString::operator+(const size_t sze) {
	dString temp(this->str);
	temp += sze;
	return temp;
}

const bool dString::operator==(dString &obj) {
	if (this->ssize() != obj.ssize()) return false;
	for (size_t index = 0; index < this->ssize(); ++index) {
		if (this->str[index] != obj.str[index]) return false;
	}
	return true;
}

const bool dString::operator!=(dString &obj) {
	return !(this->operator==(obj));
}

const dString& dString::operator=(const char *ent) {
	this->dString::dString(ent);
	return *this;
}

std::ostream& operator<<(std::ostream& os, const dString &obj) {
	os << obj.returnStr();
	return os;
}

std::istream& operator>>(std::istream& is, const dString &obj) {
	is >> obj.str; //recurive on all paths if use function to return string
	return is;
}

int main() {
	dString foo = "Hello";
	std::cout << foo.returnStr() << " " << foo.ssize() << std::endl;
	dString bar = " World!";
	foo += bar;
	std::cout << foo.returnStr() << " " << foo.ssize() << std::endl;
	dString foobar = foo + bar;
	std::cout << foobar.returnStr() << " " << foobar.ssize() << std::endl;
	foobar += 5;
	std::cout << foobar.returnStr() << " " << foobar.ssize() << std::endl;
	dString barfoo(bar + 5);
	std::cout << barfoo.returnStr() << " " << barfoo.ssize() << std::endl;
	barfoo.pushBack('a');
	std::cout << barfoo << " " << barfoo.ssize() << std::endl;
	std::cout << ((barfoo==foo) ? "Equal" : "Not Equal")  << " " << foo << std::endl;
	dString foofoo;
	dString::getlne(std::cin, foofoo);
	std::cout << foofoo << " " << foofoo.ssize() << std::endl;
	system("pause");
	return 0;
}