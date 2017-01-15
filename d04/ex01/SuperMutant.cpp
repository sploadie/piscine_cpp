/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 15:58:34 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/08 16:46:31 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"

SuperMutant::SuperMutant( void ) : Enemy(170, std::string("Super Mutant")) {
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
	return;
}

SuperMutant::SuperMutant( SuperMutant const & obj ) : Enemy(obj) {
	// *this = obj;
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
	return;
}

SuperMutant::~SuperMutant( void ) {
	std::cout << "Aaargh ..." << std::endl;
	return;
}

SuperMutant & SuperMutant::operator=( SuperMutant const & rhs ) {
	this->Enemy::operator=(rhs);
	return *this;
}

void SuperMutant::takeDamage( int damage ) {
	this->Enemy::takeDamage(damage - 3);
	return;
}
