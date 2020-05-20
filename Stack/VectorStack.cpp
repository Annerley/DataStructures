#include "VectorStack.h"



VectorStack::VectorStack()
{
	
}

void VectorStack::push(const ValueType& value)
{
	pushBack(value);
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
