/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 18:04:37 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/05 11:29:19 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.class.hpp"
#include <time.h>
#include <iostream>

Pony::Pony( void ) {
	std::cout << "Pony created" << std::endl;
	this->_legs = 4;
	return;
}

Pony::~Pony( void ) {
	std::cout << "Pony deleted" << std::endl;
	return;
}


int Pony::legs() {
	return this->_legs;
}
int Pony::legsConst() const {
	return this->_legs;
}
int* Pony::legsPointer() {
	return &(this->_legs);
}
int const * Pony::legsPointerConst() const {
	return &(this->_legs);
}
int& Pony::legsRef() {
	return this->_legs;
}
int const & Pony::legsRefConst() const {
	return this->_legs;
}
