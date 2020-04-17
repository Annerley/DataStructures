#pragma once

#include "StackImplementation.h"
#include "LinkedList.h"

// вариант с использованием ранее написанного списка и множественного наследования
// если бы список не был реализован, то было бы наследование только от интерфейса
// множественное наследование можно заменить на композицию
class ListStack : public StackImplementation, public LinkedList
{
	void push(const ValueType& value) ;
	
	void pop();
	
	 ValueType& top();

	const ValueType& top() const;
	
	bool isEmpty() const;
	
	size_t size() const;
};

