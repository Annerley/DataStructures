#include "ListStack.h"

void ListStack::push(const ValueType& value)
{
	if (_size == 0) {
		pushFront(value);
		return;
	}
	insert(_size, value);
}

void ListStack::pop()
{
	removeBack();
}

ValueType& ListStack::top()
{
	return getNode(_size)->value;
}

const ValueType& ListStack::top() const
{
	return getNode(_size)->value;
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
