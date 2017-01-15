/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 16:10:58 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/08 16:50:14 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( void ) : _name(std::string("Sole Survivor")), _ap(Character::_MaxAP) {
	this->_weapon = NULL;
	return;
}

Character::Character( std::string const & name ) : _name(name), _ap(Character::_MaxAP) {
	this->_weapon = NULL;
	return;
}

Character::Character( Character const & obj ) {
	*this = obj;
	return;
}

Character::~Character( void ) {
	return;
}

Character & Character::operator=( Character const & rhs ) {
	this->_name   = rhs._name;
	this->_ap     = rhs._ap;
	this->_weapon = rhs._weapon;
	return *this;
}

void Character::recoverAP( void ) {
	this->_ap += 10;
	if (this->_ap > Character::_MaxAP) { this->_ap = Character::_MaxAP; }
}

void Character::equip( AWeapon * weapon ) {
	this->_weapon = weapon;
}

void Character::attack( Enemy * enemy ) {
	if (this->_weapon == NULL) { return; };
	AWeapon const & weapon = *(this->_weapon);
	if (this->_ap < weapon.getAPCost()) { return; };
	this->_ap -= weapon.getAPCost();
	std::cout << this->_name << " attacks " << enemy->getType() << " with a " << weapon.getName() << std::endl;
	weapon.attack();
	enemy->takeDamage(weapon.getDamage());
	if (enemy->getHP() == 0) { delete enemy; }
}

std::string	const &	Character::getName( void )		const { return this->_name; }
int					Character::getAP( void )		const { return this->_ap; }
AWeapon			  *	Character::getWeapon( void )	const { return this->_weapon; }

std::ostream & operator<<(std::ostream & o, Character const & rhs) {
	o << rhs.getName() << " has " << rhs.getAP() << " AP and ";
	if (rhs.getWeapon() != NULL) {
		o << "wields a " << rhs.getWeapon()->getName();
	} else { o << "is unarmed";	}
	o << std::endl;
	return o;
}
