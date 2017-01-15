/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 14:25:01 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/08 15:11:40 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon( void ) : _name(std::string("None")), _ap_cost(0), _damage(0) {
	return;
}

AWeapon::AWeapon( std::string const & name, int apcost, int damage ) : _name(name), _ap_cost(apcost), _damage(damage) {
	return;
}

AWeapon::AWeapon( AWeapon const & obj ) {
	*this = obj;
	return;
}

AWeapon::~AWeapon( void ) {
	return;
}

AWeapon & AWeapon::operator=( AWeapon const & rhs ) {
	this->_name = rhs._name;
	this->_ap_cost = rhs._ap_cost;
	this->_damage = rhs._damage;
	return *this;
}

std::string const &	AWeapon::getName( void ) const {
	return this->_name;
}
int 				AWeapon::getAPCost( void ) const {
	return this->_ap_cost;
}
int 				AWeapon::getDamage( void ) const {
	return this->_damage;
}
