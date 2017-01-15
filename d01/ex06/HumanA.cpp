/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 16:20:30 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/05 17:26:59 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon & club ) : _weapon(club), _name(name) {
	return;
}

HumanA::~HumanA( void ) {
	return;
}

void HumanA::attack( void ) const {
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
	return;
}
