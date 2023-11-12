#pragma once
#include <stdexcept>
#include <iostream>
#include <string>

template <typename T>
class Array
{
private:
		T*			 	_array;
		unsigned int	_arraySize;

public:
			Array()
			{
				this->_arraySize = 0;
				this->_array = new T();
			}
			Array(unsigned int n)
			{
				this->_arraySize = n;
				this->_array = new T[_arraySize];
			}
			Array(const Array & cpy)
			{
					this->_arraySize = cpy._arraySize;
					this->_array = new T[_arraySize];
					for(unsigned int  i = 0; i < _arraySize; i++)
						_array[i] = cpy._array[i];
			}
			Array& operator=(Array const & cpy)
			{
				if (this != cpy)
				{
					delete[] this->_arraySize;
					this->_arraySize = cpy._arraySize;
					this->_array = new T[this->_arraySize];
					for(unsigned int i = 0; i < this->_arraySize; i++)
						this->_array[i] = cpy._array[i];
				}
				return (*this);
			}
			class OutOfBounds : public std::exception
			{
			public:
				virtual const char* what() const throw()
				{
					return ("Out of Bounds!");
				}
			};
			T& operator[](unsigned int idx)
			{
				if (idx >= this->_arraySize)
					throw Array::OutOfBounds();
				return (this->_array[idx]);
			}
			unsigned int size()
			{
				if (this->_arraySize)
					return(this->_arraySize);
			}
			~Array()
			{
				delete[] this->_array;
			}
};