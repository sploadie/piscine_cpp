/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 14:54:02 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/07 15:52:12 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap( std::string const & name ) : ClapTrap(name) {
	this->_name = std::string(NinjaTrap::_prefix).append(name);
	this->_hit_points = NinjaTrap::_Max_Hit_Points;
	this->_energy = NinjaTrap::_Max_Energy;
	std::cout << '<' << this->_name << "> Ready for action!" << std::endl;
	return;
}

NinjaTrap::NinjaTrap( NinjaTrap const & obj ) : ClapTrap(obj) {
	std::cout << obj._name << " cloned! (NinjaTrap)" << std::endl;
	this->_name       = std::string(obj._name).append("I");
	this->_hit_points = obj._hit_points;
	this->_energy     = obj._energy;
	return;
}

NinjaTrap::~NinjaTrap( void ) {
	std::cout << this->_name << " (NinjaTrap) was scrapped..." << std::endl;
	return;
}

NinjaTrap & NinjaTrap::operator=( NinjaTrap const & rhs ) {
	std::cout << this->_name << " converted to copy of " << rhs._name << std::endl;
	this->_name       = std::string(rhs._name).append("I");
	this->_hit_points = rhs._hit_points;
	this->_energy     = rhs._energy;
	return *this;
}

void NinjaTrap::ninjaShoebox(ClapTrap  const & trap) const {
	std::cout << this->_name << " hides in " << trap.getName() << "'s shadow." << std::endl;
	return;
}
void NinjaTrap::ninjaShoebox(FragTrap  const & trap) const {
	std::cout << this->_name << " pulls " << trap.getName() << "'s pin and throws them." << std::endl;
	return;
}
void NinjaTrap::ninjaShoebox(ScavTrap  const & trap) const {
	std::cout << this->_name << " rewires " << trap.getName() << " to be 10x more deadly." << std::endl;
	return;
}
void NinjaTrap::ninjaShoebox(NinjaTrap const & trap) const {
	std::cout << this->_name << " passes by " << trap._name << " silently, each acknowledging the other with a curt nod." << std::endl;
	return;
}

std::string const NinjaTrap::_prefix = "N1NJ4-TP ";
