/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 13:17:24 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/13 14:21:34 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_T
# define ARRAY_T

//****************************
// CLASS TEMPLATE DECLARATION
//****************************

template <class T> class Array {
public:
	Array( void );
	Array( unsigned int size );
	Array( Array const & obj );
	~Array( void );
	Array & operator=( Array const & rhs );
	T & operator[]( std::ptrdiff_t );
	unsigned int size( void ) const;

private:
	T* _array;
	unsigned int _size;
};

//****************************
// CLASS TEMPLATE DEFINITION
//****************************

template <class T> Array<T>::Array( void ) : _array(new T[0]), _size(0) {}
template <class T> Array<T>::Array( unsigned int size ) : _array(new T[size]), _size(size) {}
template <class T> Array<T>::Array( Array<T> const & obj ) { *this = obj; }
template <class T> Array<T>::~Array( void ) { delete[] this->_array; }
template <class T> Array<T> & Array<T>::operator=( Array<T> const & rhs ) {
	delete[] this->_array;
	this->_array = new T[rhs._size];
	for (unsigned int i=0;i<rhs._size;i++) { this->_array[i] = rhs._array[i]; }
	this->_size = rhs._size;
	return *this;
}
template <class T> T & Array<T>::operator[]( std::ptrdiff_t pos ) {
	if (pos < 0 || pos >= this->_size) throw std::exception();
	return this->_array[pos];
}
template <class T> unsigned int Array<T>::size( void ) const { return this->_size; }

#endif
