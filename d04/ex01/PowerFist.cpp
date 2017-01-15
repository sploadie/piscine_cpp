/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 12:50:58 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/08 15:27:44 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"

PowerFist::PowerFist( void ) : AWeapon(PowerFist::_Name, PowerFist::_ApCost, PowerFist::_Damage) {
	return;
}

PowerFist::PowerFist( PowerFist const & obj ) {
	*this = obj;
	return;
}

PowerFist::~PowerFist( void ) {
	return;
}

PowerFist & PowerFist::operator=( PowerFist const & rhs ) {
	this->AWeapon::operator=(rhs);
	return *this;
}

void PowerFist::attack( void ) const {
	std::cout <<  "* pschhh... SBAM! *" << std::endl;
}

std::string const PowerFist::_Name = "Power Fist";
