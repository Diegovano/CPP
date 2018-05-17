#pragma once

template<class _SType>
class vector
{
private:
	size_t vecSize = 0, arrCap = 8;
	_SType *arr = new _SType[arrCap];
public:
	void pushBack(_SType pushd);
	void printVec();
	size_t size();
};
