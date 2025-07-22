#pragma once

#include <iostream>
#define V template <typename T>

template <typename T>
class MyVector {
public:
	MyVector();
	MyVector(size_t capacity);

	MyVector(const MyVector<T>& other);
	MyVector(MyVector<T>&& other);

	MyVector<T>& operator=(const MyVector<T>& other);
	MyVector<T>& operator=(MyVector<T>&& other);

	T& operator[](size_t index);
	const T& operator[](size_t index) const;

	~MyVector();

	size_t getSize() const;
	size_t getCapacity() const;
	bool isEmpty() const;
	void clear();

	void push_back(const T& element);
	void push_back(T&& element);
	void insert(size_t index, const T& element);
	void insert(size_t index, T&& element);
	void insert(const T& element);
	void insert(T* element);

	void remove(const T& element);
	void pop(size_t index);
	void pop();

	size_t find(const T& element) const;
	bool contains(const T& element) const;

	void display() const;

private:
	static const int INITIAL_CAP = 1;
	static const int RESIZE_COEFF = 2;

	T* data;
	size_t size;
	size_t capacity;

	void free();
	void copyFrom(const MyVector<T>& other);
	void moveFrom(MyVector<T>&& other);
	void resize(size_t newCap);
};


V
void MyVector<T>::free()
{
	delete[] data;
	data = nullptr;
	size = capacity = 0;
}

V
void MyVector<T>::copyFrom(const MyVector<T>& other)
{
	this->size = other.size;
	this->capacity = other.capacity;
	this->data = new T[capacity];
	for (size_t i = 0; i < size; i++)
	{
		this->data[i] = other.data[i];
	}
}

V
void MyVector<T>::moveFrom(MyVector<T>&& other)
{
	this->size = other.size;
	this->capacity = other.capacity;
	this->data = other.data;
	other.size = other.capacity = 0;
	other.data = nullptr;
}

V
void MyVector<T>::resize(size_t newCap)
{
	if (newCap <= capacity) return;
	T* newData = new T[newCap];
	for (size_t i = 0; i < size; i++)
	{
		newData[i] = std::move(data[i]);
	}
	delete[] data;
	data = newData;
	capacity = newCap;
}

template <typename T>
MyVector<T>::MyVector() : MyVector<T>(INITIAL_CAP) {}

template <typename T>
MyVector<T>::MyVector(size_t capacity) : size(0), capacity(capacity)
{
	this->data = new T[capacity];
}

template <typename T>
MyVector<T>::MyVector(const MyVector<T>& other)
{
	copyFrom(other);
}

template <typename T>
MyVector<T>::MyVector(MyVector<T>&& other)
{
	moveFrom(std::move(other));
}


V
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

V
MyVector<T>& MyVector<T>::operator=(MyVector<T>&& other)
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template <typename T>
MyVector<T>::~MyVector()
{
	free();
}

V
T& MyVector<T>::operator[](size_t index)
{
	if (index >= size) throw std::invalid_argument("Invalid index!");
	return this->data[index];
}

V
const T& MyVector<T>::operator[](size_t index) const
{
	if (index >= size) throw std::invalid_argument("Invalid index!");
	return this->data[index];
}

V
size_t MyVector<T>::getSize() const
{
	return this->size;
}

V
size_t MyVector<T>::getCapacity() const
{
	return this->capacity;
}

V
bool MyVector<T>::isEmpty() const
{
	return this->size == 0;
}

V
void MyVector<T>::clear()
{
	this->size = 0;
}

V
void MyVector<T>::push_back(const T& element)
{
	if (size >= capacity) resize(capacity * RESIZE_COEFF);
	this->data[size++] = element;
}

V
void MyVector<T>::push_back(T&& element)
{
	if (size >= capacity) resize(capacity * RESIZE_COEFF);
	this->data[size++] = std::move(element);
}

V
void MyVector<T>::insert(size_t index, const T& element)
{
	if (index >= size) throw std::invalid_argument("Invalid index!");

	if (size >= capacity) resize(capacity * RESIZE_COEFF);

	for (int i = size - 1; i >= index; i--)
	{
		this->data[i + 1] = this->data[i];
	}

	this->data[index] = element;

	size++;
}

V
void MyVector<T>::insert(size_t index, T&& element)
{
	if (index >= size) throw std::invalid_argument("Invalid index!");

	if (size >= capacity) resize(capacity * RESIZE_COEFF);

	for (int i = size - 1; i >= index; i--)
	{
		this->data[i + 1] = this->data[i];
	}

	this->data[index] = std::move(element);

	size++;
}

V
void MyVector<T>::pop()
{
	if (isEmpty()) throw std::logic_error("Vector is empty!");
	size--;
}

V
void MyVector<T>::pop(size_t index)
{
	if (isEmpty()) throw std::logic_error("Vector is empty!"); \

		if (index >= size) throw std::invalid_argument("Invalid index!");

	for (size_t i = index; i < size - 1; i++)
	{
		this->data[i] = this->data[i + 1];
	}

	size--;
}

V
void MyVector<T>::remove(const T& element)
{
	if (isEmpty()) throw std::logic_error("Vector is empty!");

	size_t index = find(element);

	pop(index);
}

V
size_t MyVector<T>::find(const T& element) const
{
	for (size_t i = 0; i < size; i++)
	{
		if (this->data[i] == element) return i;
	}
	throw std::invalid_argument("Couldn't find that element!");
}

V
void MyVector<T>::display() const
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << data[i];
	}
}

V
void MyVector<T>::insert(const T& element)
{
	//
	if (!contains(element)) push_back(element);
}
V
void MyVector<T>::insert(T* element)
{
	//
	if (!contains(element)) push_back(*element);
}
V
bool MyVector<T>::contains(const T& element) const
{
	for (size_t i = 0; i < size; i++)
	{
		if (data[i] == element) return true;
	}
	return false;
}