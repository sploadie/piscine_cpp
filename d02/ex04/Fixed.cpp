/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 13:39:05 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/06 17:51:30 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) : _value(0) {
	return;
}

Fixed::Fixed( Fixed const & obj ) : _value(obj._value) {
	return;
}

Fixed::Fixed( int i ) : _value( i << Fixed::_b_point ) {
	return;
}

Fixed::Fixed( int i, bool ) : _value( i ) {
	return;
}

Fixed::Fixed( float f ) : _value( roundf(f * (1 << Fixed::_b_point)) ) {
	return;
}


Fixed::~Fixed( void ) {
	return;
}

Fixed & Fixed::operator=( int const i ) {
	this->_value = i << Fixed::_b_point;

	return *this;
}

Fixed & Fixed::operator=( float const f ) {
	this->_value = roundf(f * (1 << Fixed::_b_point));

	return *this;
}

Fixed & Fixed::operator=( Fixed const & rhs ) {
	this->_value = rhs._value;

	return *this;
}

Fixed	Fixed::operator+( Fixed const & rhs ) const {
	return Fixed( this->_value + rhs._value, true );
}

Fixed	Fixed::operator-( Fixed const & rhs ) const {
	return Fixed( this->_value - rhs._value, true );
}

Fixed	Fixed::operator*( Fixed const & rhs ) const {
	return Fixed( (this->_value * rhs._value) / (1 << Fixed::_b_point), true );
}

Fixed	Fixed::operator/( Fixed const & rhs ) const {
	return Fixed( (this->_value * (1 << Fixed::_b_point)) / rhs._value, true );
}

Fixed &	Fixed::operator++( void ) {
	this->_value++;
	return *this;
}

Fixed &	Fixed::operator--( void ) {
	this->_value--;
	return *this;
}

Fixed	Fixed::operator++( int ) {
	Fixed p(*this);
	this->_value++;
	return p;
}

Fixed	Fixed::operator--( int ) {
	Fixed p(*this);
	this->_value--;
	return p;
}


bool	Fixed::operator==( Fixed const & rhs ) const {
	return ( this->_value == rhs._value );
}

bool	Fixed::operator!=( Fixed const & rhs ) const {
	return ( this->_value != rhs._value );
}

bool	Fixed::operator< ( Fixed const & rhs ) const {
	return ( this->_value < rhs._value );
}

bool	Fixed::operator> ( Fixed const & rhs ) const {
	return ( this->_value > rhs._value );
}

bool	Fixed::operator<=( Fixed const & rhs ) const {
	return ( this->_value <= rhs._value );
}

bool	Fixed::operator>=( Fixed const & rhs ) const {
	return ( this->_value >= rhs._value );
}

int		Fixed::getRawBits( void ) const {
	return this->_value;
}
void	Fixed::setRawBits( int const raw ) {
	this->_value = raw;
}

float	Fixed::toFloat( void ) const {
	float f = this->_value;
	return (f / (1 << Fixed::_b_point));
}
int		Fixed::toInt( void ) const {
	return (this->_value >> Fixed::_b_point);
}

Fixed &			Fixed::max(Fixed & lhs, Fixed & rhs) {
	if (lhs._value >= rhs._value)
		return lhs;
	return rhs;
}

Fixed const &	Fixed::max(Fixed const & lhs, Fixed const & rhs) {
	if (lhs._value >= rhs._value)
		return lhs;
	return rhs;
}

Fixed &			Fixed::min(Fixed & lhs, Fixed & rhs) {
	if (lhs._value <= rhs._value)
		return lhs;
	return rhs;
}

Fixed const &	Fixed::min(Fixed const & lhs, Fixed const & rhs) {
	if (lhs._value <= rhs._value)
		return lhs;
	return rhs;
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs) {
	o << rhs.toFloat(); // FIXME
	return o;
}
