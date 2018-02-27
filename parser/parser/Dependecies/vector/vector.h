#pragma once
#include <iostream>

template<class _SType>
class vector
{
private:
	size_t vecSize, arrCap;
	_SType *arr;
public:
	vector() :vecSize(0), arrCap(8), arr(new _SType[arrCap])
	{
	}
	void pushBack(_SType pushd)
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
	void printVec()
	{
		for (size_t index = 0; index < vecSize; ++index)
		{
			std::cout << arr[index] << ' ';
		}
		std::cout << std::endl;
	}
	size_t size()
	{
		return vecSize;
	}
	_SType operator[](unsigned int index)
	{
		if (index > vecSize) throw std::runtime_error("[] Operator: Trying to access a non-existing element. Subscript out of range");
		return arr[index];
	}
	void remove(unsigned int index)
	{
		if (index > vecSize) throw std::runtime_error("Remove: Trying to delete a non-existing element!");
		for (unsigned int iter = index; iter < vecSize; ++iter)
		{
			arr[iter] = arr[iter + 1];
		}
		vecSize--;
	}
};
