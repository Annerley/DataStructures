#include "MyVector.h"

MyVector::MyVector(size_t size, ResizeStrategy, float coef)
{
	_capacity = size * coef;
	_size = size;
	_data = new ValueType[_capacity];
}

MyVector::MyVector(size_t size, ValueType value, ResizeStrategy, float coef)
{
	_capacity = size * coef;
	_size = size;
	_data = new ValueType[_capacity];
	for (size_t i = 0; i < _size; i++)
	{
		_data[i] = value;
	}
}

MyVector::MyVector(const MyVector& copy)
{
	_capacity = copy._capacity;
	_size = copy._size;
	_data = new ValueType[_capacity];
	for (size_t i = 0; i < _size; i++)
	{
		_data[i] = copy._data[i];
	}
}

/*MyVector::~MyVector()
{
	delete[] _data;
	
}*/

size_t MyVector::capacity() const
{
	return _capacity;
}

size_t MyVector::size() const
{
	return _size;
}

float MyVector::loadFactor()
{
	return _size/_capacity;
}

ValueType& MyVector::operator[](const size_t i) const
{
	return _data[i];
}

void MyVector::pushBack(const ValueType& value)
{
	if (_size >= _capacity)
	{
		//reserve(_capacity * 1.5);
	}
	_data[_size + 1] = value;
	_size++;
}

void MyVector::insert(const size_t i, const ValueType& value)
{
	if (_size >= _capacity)
	{
	//	reserve(_capacity * 1.5);
	}
	
	for (size_t j = _size; j >= i; j--)
	{
		if (j == i) _data[j] = value;
		else _data[j] = _data[j - 1];

	}
	_size++;
}

void MyVector::popBack()
{
	_size--;
}

void MyVector::erase(const size_t i)
{
	for (size_t j = i; j < _size-1; j++)
	{
		_data[j] = _data[j + 1];
	}
	_size--;

}

void MyVector::erase(const size_t i, const size_t len)
{
	for (size_t j = i; j < _size; j++)
	{
		_data[j] = _data[j + len];
	}
	_size -= len;
}

void MyVector::reserve(const size_t capacity)
{
	MyVector Buf(*this);
	delete[] (*this)._data;
	_data = new ValueType[_capacity];
	for (size_t i = 0; i < Buf.size(); i++)
	{
		_data[i] = Buf._data[i];
	}
	_capacity = capacity;
	delete[] Buf._data; 
}

void MyVector::resize(const size_t size, const ValueType value)
{
	if (size > _size)
	{
		if (size > _capacity)
		{
			reserve(size);
		}
		for (size_t i = _size; i < _capacity; i++)
		{
			_data[i] = value;
		}
		
	}
	else if (size < _size)
	{

	}
}

