/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 18:04:37 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/05 15:01:07 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( std::string name, std::string type ) : _name(name), _type(type) {
	std::cout << "Zombie " << name << " showed up..." << std::endl;
	return;
}

Zombie::~Zombie( void ) {
	std::cout << "Zombie " << this->_name << " flopped over." << std::endl;
	return;
}

void Zombie::announce( void ) {
	std::string quote;
	if (this->_type.compare("Old Friend") == 0) {
		quote = "To be, or to zombie? That is the question~";
	} else if (this->_type.compare("Lawyer") == 0) {
		quote = "Objection overwritten; I need BRAINS!";
	} else {
		quote = "* PROCEEDS TO EAT BRAINS *";
	}
	std::cout << '<' << this->_name << " (" << this->_type << ")> " << quote << std::endl;
}

Zombie* Zombie::randomChump(std::string type) {
	srand(time(NULL));
	char vowels[] = "aieouy";
	char consonants[] = "bcdfghjklmnpqrstvwxz";
	std::string name;
	int i;
	int len = rand() % 4 + 4;
	name.append(1, toupper(consonants[rand() % 20]));
	for (i=0;i<len;i++) {
		if (i % 2) {
			name.append(1, consonants[rand() % 20]);
		} else {
			name.append(1, vowels[rand() % 6]);
		}
	}
	return (new Zombie(name, type));
}
