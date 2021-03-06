#include "ListStack.h"


ListStack::ListStack()
{
	
}

void ListStack::push(const ValueType& value)
{
	pushFront(value);
}

void ListStack::pop()
{
	
	removeFront();
}


const ValueType& ListStack::top() const
{
	return getNode(0) -> value;
}

bool ListStack::isEmpty() const
{
	if (_size == 0) return true;
	return false;
}

size_t ListStack::size() const
{
	return _size;
}
