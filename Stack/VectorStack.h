#pragma once
#include "StackImplementation.h"
#include "MyVector.h" // меняете на include вашего вектора
#include <iostream>


using namespace std;
// вариант с использованием ранее написанного вектора и множественного наследования
// если бы вектор не был реализован, то было бы наследование только от интерфейса
// множественное наследование можно заменить на композицию
class VectorStack : public StackImplementation, public MyVector
{
public:
	void push(const ValueType& value);

	void pop();

	ValueType& top();

	const ValueType& top() const;

	bool isEmpty() const;

	size_t size() const;
};

