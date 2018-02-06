#pragma once

template <class _SType>
class stack {
private:
	_SType* arr;
public:
	stack() {
		if (sizeof(_SType) > 512) {
			std::cerr << "The size of your type is too large to make this container have a use.";
			throw range_error("The size of your type is too large to make this container have a use.");
		}
		arr = new _SType[1024 / sizeof(_SType)];
	}
	bool empty();
	size_t size();
	void pushBack(_SType ent);
	void popBack();
	void popBack(size_t toPop);
};
