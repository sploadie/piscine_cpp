/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 18:04:37 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/05 14:55:47 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent( void ) {
	std::cout << "An explosion can be heard in the distance..." << std::endl;
	this->_type = "Typical";
	return;
}

ZombieEvent::~ZombieEvent( void ) {
	std::cout << "The zombie horde dissapated over time." << std::endl;
	return;
}

void ZombieEvent::setZombieType(std::string type){
	this->_type = type;
}

Zombie* ZombieEvent::newZombie(std::string name){
	return (new Zombie(name, this->_type));
}
