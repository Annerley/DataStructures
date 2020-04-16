#include "MyVector.h"
#include <stdexcept>
#include <cmath>
#include <stdlib.h>
#include <algorithm>

MyVector::MyVector(size_t size, ResizeStrategy strategy, float coef)
{
	if (strategy == ResizeStrategy::Multiplicative) _capacity = (1.0 * size) * coef +1;
	else if (strategy == ResizeStrategy::Additive) _capacity = (size  + coef)+1;
	_coef = coef;
	_size = size;
	_strategy = strategy;
	_data = new ValueType[_capacity];
}

MyVector::MyVector(size_t size, ValueType value, ResizeStrategy strategy, float coef)
{
	if (strategy == ResizeStrategy::Multiplicative) _capacity = (1.0 * size) * coef + 1;
	else if (strategy == ResizeStrategy::Additive) _capacity = (size * coef)+1;
	_coef = coef;
	_size = size;
	_strategy = strategy;
	_data = new ValueType[_capacity ];
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

MyVector& MyVector::operator=(const MyVector& copy)
{

	if (this == &copy)
		return *this;
	if(_data == nullptr) return *this;
	_size = copy._size;
	_capacity = copy._capacity;
	_coef = copy._coef;

	delete[] _data;
	_data = new ValueType[_capacity];
	for (size_t i = 0; i < _size; ++i) {
		_data[i] = copy._data[i];
	}

	return *this;
}

MyVector::~MyVector()
{
	delete[] _data;
	
}

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
	return 1.0*_size/_capacity;
}

ValueType& MyVector::operator[](const size_t i) const
{
	if (i >= 0 && i <= _size) return _data[i];
	//throw std::out_of_range("Incorrect index"); 
		
}

void MyVector::pushBack(const ValueType& value)
{
	if (_size >= _capacity)
	{
		reserve(_size * _coef);
	}
	_data[_size] = value;
	_size++;
}

void MyVector::insert(const size_t i, const ValueType& value)
{
	if (_size >= _capacity)
	{
		reserve(_size * _coef);
	}
	if (i == 0)
	{
		for (int j = _size; j > i; j--) _data[j] = _data[j - 1];
		_data[0] = value;
		return;
	}
	for (int j = _size; j >= i; j--)
	{
		if (j == i) _data[j] = value;
		else _data[j] = _data[j - 1];

	}
	_size++;
}

void MyVector::insert(const size_t idx, const MyVector& value)
{
	
	int offset = value._size;
	if (_capacity < _size + offset) reserve(+_size + offset + 1);
	for (size_t i = _size + offset; i > idx + offset; i--)
	{
		_data[i] = _data[i - offset];
	}
	int j = 0;
	_size += offset;
	for (size_t i = idx; i < idx+offset; i++)
	{
		_data[i] = value._data[j];
	}

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

long long int MyVector::find(const ValueType& value, bool isBegin) const
{
	int tmp=-1;
	for (size_t i = 0; i < _size; i++)
	{
		if (_data[i] == value)
		{
			tmp = i;
			if (isBegin) return tmp;
		}
	}

	return tmp;
}

void MyVector::reserve(const size_t capacity, float _coef, ResizeStrategy _strategy)
{
	//if(_capacity<_size) throw  std::out_of_range("Incorrect capacity"); 
	MyVector Buf(*this);
	delete[] _data;
	_data = new ValueType[capacity];

	for (size_t i = 0; i < Buf.size(); i++)
	{
		_data[i] = Buf._data[i];
	}
	_capacity = capacity;
	
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
		_size = size;
	}
	else if (size < _size)
	{
		MyVector Buf(*this);
		delete[] _data;
		_data = new ValueType[size];
		_size = size;
		_capacity = size;
		for (size_t i = 0; i < _size; i++)
		{
			_data[i] = Buf._data[i];
		}
	}
}

void MyVector::clear()
{
	for (size_t i = 0; i < _size; i++)
	{
		_data[i] = 0;
	}
}

MyVector MyVector::sortedSquares(const MyVector& vec, SortedStrategy strategy)
{
	MyVector squares(vec);
	
	int right = _size-1;
	int left = 0;
	int i;
	if (strategy == SortedStrategy::Top) i = 0;
	else if (strategy == SortedStrategy::Bot) i = _size-1;
	//else throw 
	while (left != right)
	{
		if (abs(vec[left]) > abs(vec[right]))
		{
			squares._data[i] = vec[left] * vec[left];
			left++;
			if (strategy == SortedStrategy::Top) i++;
			else if (strategy == SortedStrategy::Bot) i--;
			continue;
		}
		else if (abs(vec[left]) < abs(vec[right]))
		{
			squares._data[i] = vec[right] * vec[right];
			right--;
			if (strategy == SortedStrategy::Top) i++;
			else if (strategy == SortedStrategy::Bot) i--;
			continue;
		}
		else
		{
			squares._data[i] = vec[right] * vec[right];
			if (strategy == SortedStrategy::Top) i++;
			else if (strategy == SortedStrategy::Bot) i--;
			squares._data[i] = vec[left] * vec[left];
			left++;
			right--;
			if (strategy == SortedStrategy::Top) i++;
			else if (strategy == SortedStrategy::Bot) i--;
		}
		
	}
	squares._data[i] = vec[left];
	
	return squares;
}

