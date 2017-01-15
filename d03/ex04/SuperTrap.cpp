/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 14:54:02 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/07 16:26:46 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

SuperTrap::SuperTrap( std::string const & name ) : ClapTrap(name), FragTrap(name), NinjaTrap(name) {
	this->_name = std::string(SuperTrap::_prefix).append(name);
	this->_hit_points = SuperTrap::_Max_Hit_Points;
	this->_energy = SuperTrap::_Max_Energy;
	std::cout << '<' << this->_name << "> Ready for action!" << std::endl;
	return;
}

SuperTrap::SuperTrap( SuperTrap const & obj ) : ClapTrap(obj), FragTrap(obj), NinjaTrap(obj) {
	std::cout << obj._name << " cloned! (SuperTrap)" << std::endl;
	this->_name       = std::string(obj._name).append("I");
	this->_hit_points = obj._hit_points;
	this->_energy     = obj._energy;
	return;
}

SuperTrap::~SuperTrap( void ) {
	std::cout << this->_name << " (SuperTrap) was scrapped..." << std::endl;
	return;
}

SuperTrap & SuperTrap::operator=( SuperTrap const & rhs ) {
	std::cout << this->_name << " converted to copy of " << rhs._name << std::endl;
	this->_name       = std::string(rhs._name).append("I");
	this->_hit_points = rhs._hit_points;
	this->_energy     = rhs._energy;
	return *this;
}

std::string const SuperTrap::_prefix = "5UP3R-TP ";
