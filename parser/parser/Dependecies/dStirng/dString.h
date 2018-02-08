#pragma once
#include <iostream>

class dString {
public:
	char* str;
	dString(const char *ent) {
		size_t nCharLoc = 0; // equivalent to the size of the string without the null char
		for (; ent[nCharLoc] != '\0'; ++nCharLoc);
		this->str = new char[nCharLoc + 1];
		for (size_t index = 0; index <= nCharLoc; ++index) this->str[index] = ent[index];
	}

	dString(const size_t sze) {
		this->str = new char[sze + 1];
		this->str[sze] = '\0';
	}
	dString() {
		this->str = new char[1];
		this->str[0] = '\0';
	}
	~dString() {
		delete str;
	}
	const size_t ssize();
	static const void dString::getlne(std::istream& is, dString &obj);
	const char operator[](const size_t loc);
	void pushBack(const char *ent);
	void pushBack(const char ent);
	const dString& operator+=(dString &obj);
	const dString& operator+=(const size_t sze);
	const dString operator+(dString &obj);
	const dString operator+(const size_t sze);
	const bool dString::operator==(dString &obj);
	const bool dString::operator!=(dString &obj);
	friend std::ostream& operator<<(std::ostream &os, const dString &obj);
	friend std::istream& operator>>(std::istream &is, const dString &obj);
	const dString& dString::operator=(const char *ent);
};