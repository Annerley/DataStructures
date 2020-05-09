#include "ListStack.h"


ListStack::ListStack()
{
	LinkedList();
}

void ListStack::push(const ValueType& value)
{
	reverse();
	pushFront(value);
}

void ListStack::pop()
{
	reverse();
	removeFront();
}


const ValueType& ListStack::top() const
{
	reverse();
	return getNode(0) -> value ;
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
