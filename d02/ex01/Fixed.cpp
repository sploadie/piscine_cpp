/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 13:39:05 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/06 15:12:14 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) : _value(0) {
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed( Fixed const & obj ) {
	std::cout << "Copy constructor called" << std::endl;
	this->_value = obj._value;
	return;
}

Fixed::Fixed( int i ) : _value( i << Fixed::_b_point ) {
	std::cout << "Int constructor called" << std::endl;
	return;
}

Fixed::Fixed( float f ) : _value( roundf(f * (1 << Fixed::_b_point)) ) {
	std::cout << "Float constructor called" << std::endl;
	return;
}


Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
	return;
}

Fixed & Fixed::operator=( Fixed const & rhs ) {
	std::cout << "Assignation operator called" << std::endl;
	this->_value = rhs._value;

	return *this;
}

int		Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}
void	Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

float	Fixed::toFloat( void ) const {
	float f = this->_value;
	return (f / (1 << Fixed::_b_point));
}
int		Fixed::toInt( void ) const {
	return (this->_value >> Fixed::_b_point);
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs) {
	o << rhs.toFloat(); // FIXME
	return o;
}
