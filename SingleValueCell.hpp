#pragma once

#include "Cell.h"

template <typename T>
class SingleValueCell : public Cell
{
private:
	T value;
public:
	SingleValueCell();
	SingleValueCell(const T& value);

	Cell* clone() const override;
};

template<typename T>
inline SingleValueCell<T>::SingleValueCell()
{
}

template<typename T>
inline SingleValueCell<T>::SingleValueCell(const T& value) : value(value)
{
}

template<typename T>
inline Cell* SingleValueCell<T>::clone() const
{
	return new SingleValueCell<T>(*this);
}
