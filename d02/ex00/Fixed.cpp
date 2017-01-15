/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 13:39:05 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/06 13:55:27 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) : _value(0) {
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed( Fixed const & obj ) {
	std::cout << "Copy constructor called" << std::endl;
	this->_value = obj.getRawBits();
	return;
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
	return;
}

Fixed & Fixed::operator=( Fixed const & rhs ) {
	std::cout << "Assignation operator called" << std::endl;
	this->_value = rhs.getRawBits();

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