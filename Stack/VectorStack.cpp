#include "VectorStack.h"



VectorStack::VectorStack()
{
	MyVector();
}

void VectorStack::push(const ValueType& value)
{
	if (_size + 1 >= _capacity) reserve(_capacity * _coef);
	_data[_size + 1] = value;
}

void VectorStack::pop()
{
	_size--;
}


const ValueType& VectorStack::top() const
{
	return back();
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
