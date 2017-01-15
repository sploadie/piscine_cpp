/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 10:38:25 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/07 15:21:05 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string const & name ) : _name(std::string(ClapTrap::_prefix).append(name)), _hit_points(ClapTrap::_Max_Hit_Points), _energy(ClapTrap::_Max_Energy) {
	std::cout << '<' << this->_name << "> Ready for action!" << std::endl;
	return;
}

ClapTrap::ClapTrap( ClapTrap const & obj ) {
	std::cout << obj._name << " cloned! (ClapTrap)" << std::endl;
	this->_name       = std::string(obj._name).append("I");
	this->_hit_points = obj._hit_points;
	this->_energy     = obj._energy;
	return;
}

ClapTrap::~ClapTrap( void ) {
	std::cout << this->_name << " (ClapTrap) was scrapped..." << std::endl;
	return;
}

ClapTrap & ClapTrap::operator=( ClapTrap const & rhs ) {
	std::cout << this->_name << " converted to copy of " << rhs._name << std::endl;
	this->_name       = std::string(rhs._name).append("I");
	this->_hit_points = rhs._hit_points;
	this->_energy     = rhs._energy;
	return *this;
}

void ClapTrap::rangedAttack(std::string const & target) const {
	std::cout << this->_name << " attacks " << target << " at range, causing " << ClapTrap::_Melee_Dmg << " points of damage!" << std::endl;
	return;
}

void ClapTrap::meleeAttack(std::string const & target) const {
	std::cout << this->_name << " melee attacks " << target << " for " << ClapTrap::_Ranged_Dmg << " points of damage!" << std::endl;
	return;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (ClapTrap::_Armor >= amount) {
		std::cout << this->_name << "'s armor soaks " << amount << " points of damage!" << std::endl;
		return;
	}
	amount -= ClapTrap::_Armor;
	if (this->_hit_points <= amount) {
		this->_hit_points = 0;
		std::cout << this->_name << " was rendered inoperative!" << std::endl;
		return;
	}
	this->_hit_points -= amount;
	std::cout << this->_name << " received " << amount << " points of damage!" << std::endl;
	return;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (ClapTrap::_Max_Hit_Points <= this->_hit_points + amount) {
		this->_hit_points = ClapTrap::_Max_Hit_Points;
		std::cout << this->_name << " was fully repaired!" << std::endl;
		return;
	}
	this->_hit_points += amount;
	std::cout << this->_name << " was repaired to " << ((this->_hit_points * 100) / ClapTrap::_Max_Hit_Points) << "% health!" << std::endl;
	return;
}

std::string const ClapTrap::_prefix = "CL4P-TP ";
