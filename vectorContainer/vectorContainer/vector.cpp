#include <iostream>
#include "vector.h"

template<class _SType>
void vector<_SType>::pushBack(_SType pushd)
{
	if (vecSize < arrCap)
	{
		arr[vecSize] = pushd;
	}
	else
	{
		arrCap *= 2;
		_SType *tempArr = new _SType[arrCap];
		for (size_t index = 0; index < arrCap / 2; ++index)
		{
			tempArr[index] = arr[index];
		}
		delete[] arr;
		arr = tempArr;
		arr[vecSize] = pushd;
	}
	++vecSize;
}

template<class _SType>
void vector<_SType>::printVec()
{
	for (size_t index = 0; index < vecSize; ++index)
	{
		std::cout << arr[index] << ' ';
	}
	std::cout << std::endl;
}

template<class _SType>
size_t vector<_SType>::size()
{
	return vecSize;
}