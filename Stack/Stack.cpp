#include "Stack.h"
#include "ListStack.h"
#include "VectorStack.h"
#include "StackImplementation.h"

#include <stdexcept>

Stack::Stack(StackContainer container)
	: _containerType(container)
{
	switch (container)
	{
	case StackContainer::List: {
		_pimpl = new ListStack();	// конкретизируйте под ваши конструкторы, если надо
		break;
	}
	case StackContainer::Vector: {
		_pimpl = new VectorStack();	// конкретизируйте под ваши конструкторы, если надо
		break;
	}
	default:
		throw std::runtime_error("Unknown type");
	}
}

Stack::Stack(const ValueType* valueArray, const size_t arraySize, StackContainer container)
	: _containerType(container)
{
	switch (container)
	{
	case StackContainer::List: {
		_pimpl = new ListStack();
		break;
	}
	case StackContainer::Vector: {
		_pimpl = new VectorStack();	
		break;
	}
	default:
		throw std::runtime_error("Unknown type");
	}
	for (size_t i = 0; i < arraySize; i++)
	{
		this->push(valueArray[i]);
	}
}

Stack::Stack(const Stack& copyStack)
{
	_containerType = copyStack._containerType;
	switch (_containerType)
	{
	case StackContainer::List: {
		_pimpl = new ListStack(*(static_cast<ListStack*>(copyStack._pimpl)));	
		break;
	}
	case StackContainer::Vector: {
		_pimpl = new VectorStack(*(static_cast<VectorStack*>(copyStack._pimpl)));	
		break;
	}
	default:
		throw std::runtime_error("Unknown type");
	}
}


Stack& Stack::operator=(const Stack& copyStack)
{
	_containerType = copyStack._containerType;
	if (this == &copyStack)
		return *this;
	delete _pimpl;
	switch (_containerType)
	{
	case StackContainer::List: {
		_pimpl = new ListStack(*(static_cast<ListStack*>(copyStack._pimpl)));	
		break;
	}
	case StackContainer::Vector: {
		_pimpl = new VectorStack(*(static_cast<VectorStack*>(copyStack._pimpl)));	
		break;
	}
	default:
		throw std::runtime_error("Unknown type");
	}
	return *this;
}

Stack::~Stack()
{
	delete _pimpl;		// композиция!
}

void Stack::push(const ValueType& value)
{
	// можно, т.к. push определен в интерфейсе
	_pimpl->push(value);
}

void Stack::pop()
{
	_pimpl->pop();
}


const ValueType& Stack::top() const
{
	return _pimpl->top();
}

bool Stack::isEmpty() const
{
	return _pimpl->isEmpty();
}

size_t Stack::size() const
{
	return _pimpl->isEmpty();
}
