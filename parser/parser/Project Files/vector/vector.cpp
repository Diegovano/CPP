#include "vector.h"

template<class _SType>
void vector<_SType>::pushBack(_SType pushd)
{
	if (sizeOfVec < sizeOfArr)
	{
		arr[sizeOfVec] = pushd;
	}
	else
	{
		sizeOfArr *= 2;
		_SType *tempArr = new _SType[sizeOfArr];
		for (size_t index = 0; index < sizeOfArr / 2; ++index)
		{
			tempArr[index] = arr[index];
		}
		delete[] arr;
		arr = tempArr;
		arr[sizeOfVec] = pushd;
	}
}

template<class _SType>
void vector<_SType>::printVec()
{
	for (size_t index = 0; index < sizeOfVec; ++index)
	{
		std::cout << arr[index] << ' ';
	}
}

template<class _SType>
size_t vector<_SType>::size()
{
	return sizeOfVec;
}