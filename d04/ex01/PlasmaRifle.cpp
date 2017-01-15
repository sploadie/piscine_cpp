/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 15:18:12 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/08 15:24:38 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle( void ) : AWeapon(PlasmaRifle::_Name, PlasmaRifle::_ApCost, PlasmaRifle::_Damage) {
	return;
}

PlasmaRifle::PlasmaRifle( PlasmaRifle const & obj ) {
	*this = obj;
	return;
}

PlasmaRifle::~PlasmaRifle( void ) {
	return;
}

PlasmaRifle & PlasmaRifle::operator=( PlasmaRifle const & rhs ) {
	this->AWeapon::operator=(rhs);
	return *this;
}

void PlasmaRifle::attack( void ) const {
	std::cout <<  "* piouuu piouuu piouuu *" << std::endl;
}

std::string const PlasmaRifle::_Name = "Plasma Rifle";
