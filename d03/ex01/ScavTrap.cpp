/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 10:38:25 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/07 14:44:14 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( std::string const & name ) : _name(std::string(ScavTrap::_prefix).append(name)), _hit_points(ScavTrap::_Max_Hit_Points), _energy(ScavTrap::_Max_Energy) {
	std::cout << '<' << this->_name << "> Ready for action!" << std::endl;
	return;
}

ScavTrap::ScavTrap( ScavTrap const & obj ) {
	std::cout << obj._name << " cloned!" << std::endl;
	this->_name       = std::string(obj._name).append("I");
	this->_hit_points = obj._hit_points;
	this->_energy     = obj._energy;
	return;
}

ScavTrap::~ScavTrap( void ) {
	std::cout << this->_name << " was scrapped..." << std::endl;
	return;
}

ScavTrap & ScavTrap::operator=( ScavTrap const & rhs ) {
	std::cout << this->_name << " converted to copy of " << rhs._name << std::endl;
	this->_name       = std::string(rhs._name).append("I");
	this->_hit_points = rhs._hit_points;
	this->_energy     = rhs._energy;
	return *this;
}

void ScavTrap::rangedAttack(std::string const & target) const {
	std::cout << this->_name << " throws a doorknob at " << target << ", inflicting " << ScavTrap::_Melee_Dmg << " points of damage!" << std::endl;
	return;
}

void ScavTrap::meleeAttack(std::string const & target) const {
	std::cout << this->_name << " slams " << target << " with the door for " << ScavTrap::_Ranged_Dmg << " points of damage!" << std::endl;
	return;
}

void ScavTrap::takeDamage(unsigned int amount) {
	if (ScavTrap::_Armor >= amount) {
		std::cout << this->_name << "'s armor soaks " << amount << " points of damage!" << std::endl;
		return;
	}
	amount -= ScavTrap::_Armor;
	if (this->_hit_points <= amount) {
		this->_hit_points = 0;
		std::cout << this->_name << " was rendered inoperative!" << std::endl;
		return;
	}
	this->_hit_points -= amount;
	std::cout << this->_name << " received " << amount << " points of damage!" << std::endl;
	return;
}

void ScavTrap::beRepaired(unsigned int amount) {
	if (ScavTrap::_Max_Hit_Points <= this->_hit_points + amount) {
		this->_hit_points = ScavTrap::_Max_Hit_Points;
		std::cout << this->_name << " was fully repaired!" << std::endl;
		return;
	}
	this->_hit_points += amount;
	std::cout << this->_name << " was repaired to " << ((this->_hit_points * 100) / ScavTrap::_Max_Hit_Points) << "% health!" << std::endl;
	return;
}


void ScavTrap::challengeNewcomer(std::string const & target) {
	if (this->_energy < 25) { std::cout << this->_name << " is too low on energy!" << std::endl; return; }
	this->_energy -= 25;
	unsigned int damage = 20 + (rand() % 51);
	switch (rand() % 5) {
		case 0:
			std::cout << '<' << this->_name << "> What is the creature that walks on four legs in the morning, two legs at noon and three in the evening?" << std::endl;
			break;
		case 1:
			std::cout << '<' << this->_name << "> You want to enter? Make a ticket. Then send me an email. Then come by and verify if your ticket was validated. Thank you~" << std::endl;
			break;
		case 2:
			std::cout << '<' << this->_name << "> You should always tip the doorman! (" << this->_name << " punches " << target << " for " << damage << " damage)" << std::endl;
			break;
		case 3:
			std::cout << '<' << this->_name << "> A pit under the doormat is challenge enough. (" << target << " takes " << damage << " points of damage from falling down the pit under said doormat)" << std::endl;
			break;
		default:
			std::cout << '<' << this->_name << "> I've got a challenge for you, " << target << "... come up with five funny challenges!" << std::endl;
	}
	return;
}

std::string const ScavTrap::_prefix = "5C4V-TP ";
