/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 18:45:58 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/08 19:08:21 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine( void ) {
	std::cout << TacticalMarine::_FirstCall << std::endl;
	return;
}

TacticalMarine::TacticalMarine( TacticalMarine const & obj ) {
	*this = obj;
	std::cout << TacticalMarine::_FirstCall << std::endl;
	return;
}

TacticalMarine::~TacticalMarine( void ) {
	std::cout << "Aaargh ..." << std::endl;
	return;
}

TacticalMarine & TacticalMarine::operator=( TacticalMarine const & rhs ) {
	(void)rhs; // Nothing to assign...
	return *this;
}

TacticalMarine * TacticalMarine::clone( void ) const {
	return new TacticalMarine(*this);
}

void TacticalMarine::battleCry( void ) const {
	std::cout << "For the holy PLOT !" << std::endl;
}

void TacticalMarine::rangedAttack( void ) const {
	std::cout << "* attacks with bolter *" << std::endl;
}

void TacticalMarine::meleeAttack( void ) const {
	std::cout << "* attacks with chainsword *" << std::endl;
}

std::string const TacticalMarine::_FirstCall = "Tactical Marine ready for battle";
