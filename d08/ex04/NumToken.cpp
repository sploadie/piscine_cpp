/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NumToken.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 20:07:17 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/14 20:44:07 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NumToken.hpp"

NumToken::NumToken( void ) {}
NumToken::NumToken( int i ) : Fixed(i) {}
NumToken::NumToken( NumToken const & obj ) { *this = obj; }
NumToken::~NumToken( void ) {}

NumToken & NumToken::operator=( NumToken const & rhs ) {
	this->Fixed::operator=(rhs);
	return *this;
}

bool NumToken::isNum( void ) const { return true; }

std::string const & NumToken::toString( void ) const {
	std::stringstream ss;
	ss << this->toInt();
	return ss.str();
}
