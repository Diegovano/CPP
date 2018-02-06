#include <iostream>
#include "stack.h"

template <class _SType>
bool stack<_SType>::empty(){
	
}

template <class _SType>
size_t stack<_SType>::size() {
	return sizeof(this->arr) / sizeof(_SType);
}

int main() {
	system("pause");
	return 0;
}