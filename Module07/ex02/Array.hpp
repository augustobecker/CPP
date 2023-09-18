#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array 
{
private:
	unsigned int	_size;
	T*				_elements;

public:

	Array ( void )
	{
		this->_elements = new T[0];
		this->_size = 0;
	};

	Array ( unsigned int n )
	{
		this->_elements = new T[n];
		this->_size = n;
	};

	~Array ( void )
	{
		delete[] this->_elements;
	};

	Array(const Array& toCopyFrom) : _size(toCopyFrom.size()), _elements(new T[toCopyFrom.size()])
	{
		for (unsigned int i = 0; i < this->_size; i++)
		{
			this->_elements[i] = toCopyFrom[i];
		}
	};

	Array& operator=( const Array& toCopyFrom )
	{
		if (this != &toCopyFrom)
		{
			for (unsigned int i = 0; i < this->_size; i++)
			{
				this->_elements[i] = i < toCopyFrom._size ? toCopyFrom[i] : 0;
			}
		}
		return (*this);
	};

	unsigned int	size(void) const
	{
		return (this->_size);
	}

	T&	operator[](unsigned int index) const
	{
		if (index >= this->_size)
			throw std::out_of_range("Exception: Index out of bounds. Attempted to access an element beyond the valid index range.");
		return (this->_elements[index]);
	};

};

#endif