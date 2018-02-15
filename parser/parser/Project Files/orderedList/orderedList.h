#pragma once
#include "..\..\Dependecies\vector\vector.h"

template<class _SType>
class orderedList
{
private:
	vector<_SType> list;
public:
	size_t listSize()
	{
		return list.size();
	}
	const _SType operator[](unsigned int index)
	{
		return list[index];
	}
	void pushBack(_SType pushd)
	{
		list.pushBack(pushd);
	}
};