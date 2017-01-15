/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 22:06:03 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/08 22:14:51 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( void ) {}

Character::Character( std::string const & name ) : _name(name) {
	this->_materias = new AMateria * [Character::_MaxMateria];
	for (int i=0;i<Character::_MaxMateria;i++) { this->_materias[i] = NULL; }
}

Character::Character( Character const & obj ) {
	this->_materias = new AMateria * [Character::_MaxMateria];
	for (int i=0;i<Character::_MaxMateria;i++) { this->_materias[i] = NULL; }
	*this = obj;
}

Character::~Character( void ) {
	for (int i=0;i<Character::_MaxMateria;i++) {
		if (this->_materias[i] != NULL) { delete this->_materias[i]; }
	}
	delete this->_materias;
	return;
}

Character & Character::operator=( Character const & rhs ) {
	this->_name = rhs._name;
	for (int i=0;i<Character::_MaxMateria;i++) {
		if (this->_materias[i] != NULL) { delete this->_materias[i]; this->_materias[i] = NULL; }
		if (rhs._materias[i]   != NULL) { this->_materias[i] = rhs._materias[i]->clone(); }
	}
	return *this;
}

std::string const & Character::getName( void ) const { return this->_name; }

void Character::equip(AMateria* m) {
	for (int i=0;i<Character::_MaxMateria;i++) {
		if (this->_materias[i] == NULL) {
			this->_materias[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= Character::_MaxMateria) { return; }
	this->_materias[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= Character::_MaxMateria || this->_materias[idx] == NULL) { return; }
	this->_materias[idx]->use(target);
}
