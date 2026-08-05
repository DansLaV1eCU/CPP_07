#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array
{
public:
	class OutOfBoundsException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	Array( void );
	Array( unsigned int n );
	Array( const Array& other );
	Array& operator=( const Array& other );
	~Array( void );

	T& operator[]( unsigned int index );
	const T& operator[]( unsigned int index ) const;
	unsigned int size( void ) const;

private:
	T* _array;
	unsigned int _size;
};

#include "Array.tpp"

#endif