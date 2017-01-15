/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 11:14:56 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/08 13:07:08 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

Victim::Victim( void ) : _name(std::string("Anon")) {
	this->proclaim_birth();
	return;
}

Victim::Victim( std::string const & name ) : _name(name) {
	this->proclaim_birth();
	return;
}

Victim::Victim( Victim const & obj ) {
	*this = obj;
	this->proclaim_birth();
	return;
}

Victim::~Victim( void ) {
	std::cout << "Victim " << this->_name << " just died for no apparent reason !" << std::endl;
	return;
}

Victim & Victim::operator=( Victim const & rhs ) {
	this->_name = rhs._name;
	return *this;
}

void Victim::proclaim_birth( void ) const {
	std::cout << "Some random victim called " << this->_name << " just popped !" << std::endl;
	return;
}

void Victim::getPolymorphed( void ) const {
	std::cout << this->_name << " has been turned into a cute little sheep !" << std::endl;
	return;
}

std::string const & Victim::getName( void )  const { return this->_name;  }

std::ostream & operator<<(std::ostream & o, Victim const & rhs) {
	o << "I'm " << rhs.getName() << " and I like otters !" << std::endl;
	return o;
}
