#pragma once

template<class _SType>
class vector
{
private:
	size_t sizeOfVec = 0, sizeOfArr = 8;
	_SType *arr = new _SType[sizeOfArr];
public:
	void pushBack(_SType pushd);
	void printVec();
	size_t size();
};
