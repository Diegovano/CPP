#pragma once
#include "string.h"
#include <iostream>

dString::dString(const char *ent) {
	size_t nullChar = 0;
	for (; ent[nullChar] != '\0'; ++nullChar);
	size = nullChar;
	endLoc = &ent[nullChar];
	beginLoc = &ent[nullChar - nullChar];
	if (sizeof(char)*(nullChar + 1) > 28) convStr = new char[nullChar + 1];
	else char *convStr = static_cast<char*>(_alloca(nullChar + 1));
	convStr[nullChar] = '\0';
	for (unsigned int index = 0; index < nullChar; ++index) {
		convStr[index] = ent[index];
	}
}

dString::dString(size_t sze) {
	size_t nChar = sze + 1;
	if (sizeof(char)*nChar > 28)convStr = new char[nChar];
	else char *convStr = static_cast<char*>(_alloca(nChar));
	endLoc = &convStr[size];
	beginLoc = &convStr[size - size];
	convStr[size] = '\0';
}

const char* dString::begin() {
	return &str[0];
}

const char* dString::end() {
	return &str[size];
}

const dString& dString::operator+=(const dString &obj) {
	size_t newSize = this->size + obj.size;
	dString toRet(newSize);
	for (unsigned int iter = 0; iter < this->size; ++iter) {
		toRet.convStr[iter] = this->convStr[iter];
	}
	for (unsigned int iter = this->size; iter < this->size + obj.size; ++iter) {
		toRet.convStr[iter] = obj.convStr[iter - this->size];
	}
	this->convStr = toRet.convStr;
	this->size = toRet.size;
	return *this;
}

const dString dString::operator+(const dString &obj) {
	dString temp(this->convStr);
	temp += obj;
	return temp;
}

const dString& dString::operator+(const int ent) {
	dString tempStr(ent);
	*this += tempStr;
	return *this;
}

const bool dString::operator==(const dString &obj) {
	if (this->size != obj.size)return false;
	for (size_t iter = 0; iter < this->size; ++iter) {
		if (this->convStr[iter] != obj.convStr[iter])return false;
	}
	return true;
}

const dString& dString::operator=(const char *ent) {
	return *this;
}

int main() {
	dString intro("Hello, "), greeting("How Are You?"), response("Very Well!");
	dString fullQue(intro + greeting);
	std::cout << fullQue.convStr;

	//if ( == ) std::cout << "The Strings Are Equal" << std::endl;
	//else std::cout << "Strings do not match" << std::endl;
	system("pause");
}