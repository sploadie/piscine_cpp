/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 10:38:25 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/07 14:19:14 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( std::string const & name ) : _name(std::string(FragTrap::_prefix).append(name)), _hit_points(FragTrap::_Max_Hit_Points), _energy(FragTrap::_Max_Energy) {
	std::cout << '<' << this->_name << "> Ready for action!" << std::endl;
	return;
}

FragTrap::FragTrap( FragTrap const & obj ) {
	std::cout << obj._name << " cloned!" << std::endl;
	this->_name       = std::string(obj._name).append("I");
	this->_hit_points = obj._hit_points;
	this->_energy     = obj._energy;
	return;
}

FragTrap::~FragTrap( void ) {
	std::cout << this->_name << " was scrapped..." << std::endl;
	return;
}

FragTrap & FragTrap::operator=( FragTrap const & rhs ) {
	std::cout << this->_name << " converted to copy of " << rhs._name << std::endl;
	this->_name       = std::string(rhs._name).append("I");
	this->_hit_points = rhs._hit_points;
	this->_energy     = rhs._energy;
	return *this;
}

void FragTrap::rangedAttack(std::string const & target) const {
	std::cout << this->_name << " attacks " << target << " at range, causing " << FragTrap::_Melee_Dmg << " points of damage!" << std::endl;
	return;
}

void FragTrap::meleeAttack(std::string const & target) const {
	std::cout << this->_name << " melee attacks " << target << " for " << FragTrap::_Ranged_Dmg << " points of damage!" << std::endl;
	return;
}

void FragTrap::takeDamage(unsigned int amount) {
	if (FragTrap::_Armor >= amount) {
		std::cout << this->_name << "'s armor soaks " << amount << " points of damage!" << std::endl;
		return;
	}
	amount -= FragTrap::_Armor;
	if (this->_hit_points <= amount) {
		this->_hit_points = 0;
		std::cout << this->_name << " was rendered inoperative!" << std::endl;
		return;
	}
	this->_hit_points -= amount;
	std::cout << this->_name << " received " << amount << " points of damage!" << std::endl;
	return;
}

void FragTrap::beRepaired(unsigned int amount) {
	if (FragTrap::_Max_Hit_Points <= this->_hit_points + amount) {
		this->_hit_points = FragTrap::_Max_Hit_Points;
		std::cout << this->_name << " was fully repaired!" << std::endl;
		return;
	}
	this->_hit_points += amount;
	std::cout << this->_name << " was repaired to " << ((this->_hit_points * 100) / FragTrap::_Max_Hit_Points) << "% health!" << std::endl;
	return;
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


// class FragTrap {

// public:

// 	FragTrap( void );
// 	FragTrap( FragTrap const & obj );

// 	~FragTrap( void );

// 	FragTrap & operator=( FragTrap const & rhs );


// 	void rangedAttack(std::string const & target) const;
// 	void meleeAttack(std::string const & target) const;
// 	void takeDamage(unsigned int amount);
// 	void beRepaired(unsigned int amount);

// 	void vaulthunter_dot_exe(std::string const & target);

// private:

// 	std::string			_name;

// 	static int const	_Level = 1;
// 	static int const	_Max_Hit_Points	= 100;
// 	int					_hit_points;
// 	static int const	_Max_Energy		= 100;
// 	int					_energy;

// 	static int const	_Melee_Dmg	= 30;
// 	static int const	_Ranged_Dmg	= 20;
// 	static int const	_Armor		= 5;
// };
