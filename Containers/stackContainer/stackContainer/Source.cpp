#include <iostream>
#include "stack.h"

template <class _SType>
bool stack<_SType>::empty(){
	if (!isValid)throw std::runtime_error("Cannot use member functions of an invalid Stack!");
	if (occSize == 0)return true;
	return false;
}

template <class _SType>
size_t stack<_SType>::size() {
	if (!isValid)throw std::runtime_error("Cannot use member functions of an invalid Stack!");
	return occSize;
}

template <class _SType>
void stack<_SType>::pushBack(_SType ent) {
	if (!isValid)throw std::runtime_error("Cannot use member functions of an invalid Stack!");
	if ((occSize + 1) * sizeof(_SType) > 0xFA000) {
		std::cerr << "Stack cannot contain more elements." << std::endl;
		system("pause");
		return;
	}
	*lastElem = ent;
	++lastElem;
	++occSize;
}

template <class _SType>
void stack<_SType>::popBack() {
	if (!isValid)throw std::runtime_error("Cannot use member functions of an invalid Stack!");
	if (occSize == 0) {
		std::cerr << "Cannot remove element as none exists!" << std::endl;
		return;
	}
	--lastElem;
	--occSize;
}

template <class _SType>
const _SType stack<_SType>::operator[](const size_t ent) {
	if (!isValid)throw std::runtime_error("Cannot use member functions of an invalid Stack!");
	if (ent >= occSize) {
		std::cerr << "Subscript value out of range." << std::endl;
		return _SType();
	}
	_SType *tempPtr = arr;
	for (unsigned int iter = 0; iter < ent; ++iter) {
		++tempPtr;
	}
	return *tempPtr;
}

struct bigThing {
	char vBig[300000];
};

int main() {
	try {
		bigThing vvBigTing;
		stack<int> intCont;
		int ent;
		while (std::cin >> ent) {
			if (ent == 42)break;
			intCont.pushBack(ent);
		}
		std::cout << intCont[2] << std::endl;
		std::cout << intCont.size();
		intCont.popBack();
		std::cout << " " << intCont.size() << std::endl;
		intCont.pushBack(128);
		std::cout << intCont[2] << std::endl;
		stack<bigThing> vBigTing;
		vBigTing.pushBack(vvBigTing);
		system("pause");
		return 0;
	}
	catch (std::runtime_error& e) {
		std::cout << e.what() << std::endl;
		system("pause");
		return -1;
	}
}