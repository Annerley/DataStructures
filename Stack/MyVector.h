#pragma once

// стратегия изменения capacity
enum class ResizeStrategy {
	Additive,
	Multiplicative
};

//стратегия сортировки
enum class SortedStrategy {
	Top, 
	Bot
};


// тип значений в векторе
// потом будет заменен на шаблон
using ValueType = double;




class MyVector
{
	class Iterator
	{
		ValueType* cur;
	public:
		Iterator(ValueType* first) : cur(first)
		{}
		ValueType& operator+ (int n) { return *(cur + n); }
		ValueType& operator- (int n) { return *(cur - n); }

		ValueType& operator++(int) { return *cur++; }
		ValueType & operator-- (int) { return *cur--; }
		ValueType & operator++ () { return *++cur; }
		ValueType & operator-- () { return *--cur; }

		bool operator!=(const Iterator& it) { return cur != it.cur; }
		bool operator==(const Iterator& it) { return cur == it.cur; }
		ValueType& operator* () { return *cur; }
	};
public:
	MyVector(size_t size = 0, ResizeStrategy = ResizeStrategy::Multiplicative, float coef = 1.5f);
	MyVector(size_t size, ValueType value, ResizeStrategy = ResizeStrategy::Multiplicative, float coef = 1.5f);

	MyVector(const MyVector& copy);
	MyVector& operator=(const MyVector& copy);

	~MyVector();

	// для умненьких — реализовать конструктор и оператор для перемещения

	size_t capacity() const;
	size_t size() const;
	float loadFactor();

	// доступ к элементу, 
	// должен работать за O(1)
	ValueType& operator[](const size_t i) const;

	// добавить в конец,
	// должен работать за amort(O(1))
	void pushBack(const ValueType& value);
	// вставить,
	// должен работать за O(n)
	void insert(const size_t i, const ValueType& value);	// версия для одного значения
	void insert(const size_t idx, const MyVector& value);		// версия для вектора

	// удалить с конца,
	// должен работать за amort(O(1))
	void popBack();
	// удалить
	// должен работать за O(n)
	void erase(const size_t i);
	void erase(const size_t i, const size_t len);			// удалить len элементов начиная с i

	// найти элемент,
	// должен работать за O(n)
	// если isBegin == true, найти индекс первого элемента, равного value, иначе последнего
	// если искомого элемента нет, вернуть -1
	long long int find(const ValueType& value, bool isBegin = true) const;

	// зарезервировать память (принудительно задать capacity)
	void reserve(const size_t capacity);

	// изменить размер
	// если новый размер больше текущего, то новые элементы забиваются дефолтными значениями
	// если меньше - обрезаем вектор
	void resize(const size_t size, const ValueType = 0.0);

	// очистка вектора, без изменения capacity
	void clear();

	Iterator begin() { return _data; }
	Iterator end() {return _data + _size;}

	static MyVector sortedSquares(const MyVector& vec, SortedStrategy strategy);

	const ValueType& front() const;
	const ValueType& back() const;
	
	
protected:
	ValueType* _data;
	size_t _size;
	size_t _capacity;
	float _coef;
	ResizeStrategy _strategy;
};

