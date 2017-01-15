/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 14:54:02 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/07 15:21:13 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( std::string const & name ) : ClapTrap(name) {
	this->_name = std::string(FragTrap::_prefix).append(name);
	this->_hit_points = FragTrap::_Max_Hit_Points;
	this->_energy = FragTrap::_Max_Energy;
	std::cout << '<' << this->_name << "> Ready for action!" << std::endl;
	return;
}

FragTrap::FragTrap( FragTrap const & obj ) : ClapTrap(obj) {
	std::cout << obj._name << " cloned! (FragTrap)" << std::endl;
	this->_name       = std::string(obj._name).append("I");
	this->_hit_points = obj._hit_points;
	this->_energy     = obj._energy;
	return;
}

FragTrap::~FragTrap( void ) {
	std::cout << this->_name << " (FragTrap) was scrapped..." << std::endl;
	return;
}

FragTrap & FragTrap::operator=( FragTrap const & rhs ) {
	std::cout << this->_name << " converted to copy of " << rhs._name << std::endl;
	this->_name       = std::string(rhs._name).append("I");
	this->_hit_points = rhs._hit_points;
	this->_energy     = rhs._energy;
	return *this;
}

void FragTrap::vaulthunter_dot_exe(std::string const & target) {
	if (this->_energy < 25) { std::cout << this->_name << " is too low on energy!" << std::endl; return; }
	this->_energy -= 25;
	unsigned int damage = 20 + (rand() % 51);
	switch (rand() % 5) {
		case 0:
			std::cout << '<' << this->_name << "> This time it'll be awesome, I promise! (" << target << " takes " << damage << " points of damage but has no idea what happened)" << std::endl;
			break;
		case 1:
			std::cout << '<' << this->_name << "> Recompiling my combat code! (" << this->_name << " rips " << target << "'s heart out for a meager " << (damage + 900) << " points of damage)" << std::endl;
			break;
		case 2:
			std::cout << '<' << this->_name << "> It's happening... it's happening! (" << target << " explodes)" << std::endl;
			break;
		case 3:
			std::cout << '<' << this->_name << "> You can't just program this level of excitement! (" << target << " is stunned by " << this->_name << "'s sweet moves)" << std::endl;
			break;
		default:
			std::cout << '<' << this->_name << "> Don't ask me where this ammo's coming from! (" << target << " soaks " << damage << " damage like the bullet sponge they are)" << std::endl;
	}
	return;
}

std::string const FragTrap::_prefix = "FR4G-TP ";
