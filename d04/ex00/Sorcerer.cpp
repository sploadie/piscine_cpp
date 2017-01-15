/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 11:14:56 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/08 13:05:41 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

Sorcerer::Sorcerer( void ) : _name(std::string("Anon")), _title(std::string("One with the Crowd")) {
	this->proclaim_birth();
	return;
}

Sorcerer::Sorcerer( std::string const & name, std::string const & title ) : _name(name), _title(title) {
	this->proclaim_birth();
	return;
}

Sorcerer::Sorcerer( Sorcerer const & obj ) {
	*this = obj;
	this->proclaim_birth();
	return;
}

Sorcerer::~Sorcerer( void ) {
	std::cout << this->_name << ", " << this->_title << ", is dead. Consequences will never be the same !" << std::endl;
	return;
}

Sorcerer & Sorcerer::operator=( Sorcerer const & rhs ) {
	this->_name  = rhs._name;
	this->_title = rhs._title;

	return *this;
}

void Sorcerer::proclaim_birth( void ) const {
	std::cout << this->_name << ", " << this->_title << ", is born !" << std::endl;
	return;
}

void Sorcerer::polymorph(Victim const & victim) const {
	victim.getPolymorphed();
	return;
}

std::string const & Sorcerer::getName( void )  const { return this->_name;  }
std::string const & Sorcerer::getTitle( void ) const { return this->_title; }

std::ostream & operator<<(std::ostream & o, Sorcerer const & rhs) {
	o << "I am " << rhs.getName() << ", " << rhs.getTitle() << ", and I like ponies !" << std::endl;
	return o;
}
