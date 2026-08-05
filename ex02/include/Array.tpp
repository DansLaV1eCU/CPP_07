#ifndef ARRAY_TPP
#define ARRAY_TPP

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw()
{
	return "Array index out of bounds";
}

template <typename T>
Array<T>::Array( void ) : _array(0), _size(0)
{
}

template <typename T>
Array<T>::Array( unsigned int n ) : _array(0), _size(n)
{
	if (n > 0)
	{
		this->_array = new T[n]();
	}
}

template <typename T>
Array<T>::Array( const Array& other ) : _array(0), _size(0)
{
	*this = other;
}

template <typename T>
Array<T>& Array<T>::operator=( const Array& other )
{
	if (this != &other)
	{
		T* newArray = 0;

		if (other._size > 0)
		{
			newArray = new T[other._size]();
			for (unsigned int i = 0; i < other._size; ++i)
			{
				newArray[i] = other._array[i];
			}
		}
		delete[] this->_array;
		this->_array = newArray;
		this->_size = other._size;
	}
	return *this;
}

template <typename T>
Array<T>::~Array( void )
{
	delete[] this->_array;
}

template <typename T>
T& Array<T>::operator[]( unsigned int index )
{
	if (index >= this->_size)
	{
		throw OutOfBoundsException();
	}
	return this->_array[index];
}

template <typename T>
const T& Array<T>::operator[]( unsigned int index ) const
{
	if (index >= this->_size)
	{
		throw OutOfBoundsException();
	}
	return this->_array[index];
}

template <typename T>
unsigned int Array<T>::size( void ) const
{
	return this->_size;
}

#endif