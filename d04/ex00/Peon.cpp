/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 11:14:56 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/08 12:41:23 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"

Peon::Peon( void ) : Victim() {
	this->proclaim_birth();
	return;
}

Peon::Peon( std::string const & name ) : Victim(name) {
	this->proclaim_birth();
	return;
}

Peon::Peon( Peon const & obj ) : Victim(obj._name) {
	*this = obj;
	this->proclaim_birth();
	return;
}

Peon::~Peon( void ) {
	std::cout << "Bleuark..." << std::endl;
	return;
}

Peon & Peon::operator=( Peon const & rhs ) {
	this->_name = rhs._name;
	return *this;
}

void Peon::proclaim_birth( void ) const {
	std::cout << "Zog zog." << std::endl;
	return;
}

void Peon::getPolymorphed( void ) const {
	std::cout << this->_name << " has been turned into a pink pony !" << std::endl;
	return;
}
