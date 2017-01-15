/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 17:07:25 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/08 19:09:04 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator( void ) {
	std::cout << AssaultTerminator::_FirstCall << std::endl;
	return;
}

AssaultTerminator::AssaultTerminator( AssaultTerminator const & obj ) {
	*this = obj;
	std::cout << AssaultTerminator::_FirstCall << std::endl;
	return;
}

AssaultTerminator::~AssaultTerminator( void ) {
	std::cout << "I'll be back ..." << std::endl;
	return;
}

AssaultTerminator & AssaultTerminator::operator=( AssaultTerminator const & rhs ) {
	(void)rhs; // Nothing to assign...
	return *this;
}

AssaultTerminator * AssaultTerminator::clone( void ) const {
	return new AssaultTerminator(*this);
}

void AssaultTerminator::battleCry( void ) const {
	std::cout << "This code is unclean. PURIFY IT !" << std::endl;
}

void AssaultTerminator::rangedAttack( void ) const {
	std::cout << "* does nothing *" << std::endl;
}

void AssaultTerminator::meleeAttack( void ) const {
	std::cout << "* attacks with chainfists *" << std::endl;
}

std::string const AssaultTerminator::_FirstCall = "* teleports from space *";
