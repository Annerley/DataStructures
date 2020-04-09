#include "MyVector.h"
#include <stdexcept>
#include <cmath>

MyVector::MyVector(size_t size, ResizeStrategy strategy, float coef)
{
	if (strategy == ResizeStrategy::Multiplicative) _capacity = (1.0 * size) * coef;
	else if (strategy == ResizeStrategy::Additive) _capacity = (size *coef);
	_coef = coef;
	_size = size;
	_data = new ValueType[_capacity];
}

MyVector::MyVector(size_t size, ValueType value, ResizeStrategy strategy, float coef)
{
	if (strategy == ResizeStrategy::Multiplicative) _capacity = (1.0 * size) * coef;
	else if (strategy == ResizeStrategy::Additive) _capacity = (size * coef);
	coef = _coef;
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
	if (i >= 0 && i < _size) return _data[i];
	//throw std::length_error("Incorrect index"); 
		
}

void MyVector::pushBack(const ValueType& value)
{
	if (_size >= _capacity)
	{
		reserve(_size + 1);
	}
	_data[_size] = value;
	_size++;
}

void MyVector::insert(const size_t i, const ValueType& value)
{
	if (_size >= _capacity)
	{
		reserve(_size + 1);
	}
	
	for (size_t j = _size; j >= i; j--)
	{
		if (j == i) _data[j] = value;
		else _data[j] = _data[j - 1];

	}
	_size++;
}

void MyVector::insert(const size_t idx, const MyVector& value)
{
	
	int sdvig = value._size;
	if (_capacity < _size + sdvig) reserve(+_size + sdvig + 1);
	for (size_t i = _size + sdvig; i > idx + sdvig; i--)
	{
		_data[i] = _data[i - sdvig];
	}
	int j = 0;
	_size += sdvig;
	for (size_t i = idx; i < idx+sdvig; i++)
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
	ValueType tmp=-1;
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

void MyVector::reserve(const size_t capacity)
{
	MyVector Buf(*this);
	delete[] _data;
	_data = new ValueType[_capacity];
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
		MyVector(Buf);
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
	while (left != right)
	{
		if (abs(vec[left]) > abs(vec[right]))
		{
			squares._data[i] = vec[left] * vec[left];
			left++;
		}
		else if (abs(vec[left]) < abs(vec[right]))
		{
			squares._data[i] = vec[right] * vec[right];
			right--;
		}
		else
		{
			squares._data[i] = vec[right] * vec[right];
			if (strategy == SortedStrategy::Top) i++;
			else if (strategy == SortedStrategy::Bot) i--;
			squares._data[i] = vec[left] * vec[left];
			left++;
			right--;
		}
		if (strategy == SortedStrategy::Top) i++;
		else if (strategy == SortedStrategy::Bot) i--;
	}
	return squares;
}

