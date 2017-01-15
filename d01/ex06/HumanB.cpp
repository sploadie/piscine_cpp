/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 16:20:30 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/05 17:35:36 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : _name(name) {
	this->_weapon = NULL;
	return;
}

HumanB::~HumanB( void ) {
	return;
}

void HumanB::setWeapon( Weapon & club ) {
	this->_weapon = &club;
}

void HumanB::attack( void ) const {
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	return;
}
