#include "VectorStack.h"

void VectorStack::push(const ValueType& value)
{
	if (_size + 1 >= _capacity) reserve(_capacity * _coef);
	_data[_size + 1] = value;
}

void VectorStack::pop()
{
	_size--;
}

ValueType& VectorStack::top()
{
	return _data[_size];
}

const ValueType& VectorStack::top() const
{
	return _data[_size];
}

bool VectorStack::isEmpty() const
{
	if (_size == 0) return true;
	return false;
}

size_t VectorStack::size() const
{
	return _size;
}
