/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 18:04:37 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/05 15:57:10 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde( int n ) : _size(n) {
	std::cout << "An explosion can be heard in the distance, followed by the cries of over " << n << " zombies..." << std::endl;
	this->_zombies = new Zombie[n];
	return;
}

ZombieHorde::~ZombieHorde( void ) {
	delete[] this->_zombies;
	std::cout << "The zombie horde dissapated over time..." << std::endl;
	return;
}

void ZombieHorde::announce( void ){
	for (int i=0;i<this->_size;i++) { this->_zombies[i].announce(); }
}
