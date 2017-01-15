/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 18:04:37 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/05 15:39:33 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( void ) {
	this->_type = "Zombie";
	this->_name = Zombie::_random_name();
	std::cout << "Zombie " << this->_name << " showed up..." << std::endl;
	return;
}

Zombie::Zombie( std::string name, std::string type ) : _name(name), _type(type) {
	std::cout << "Zombie " << name << " showed up..." << std::endl;
	return;
}

Zombie::~Zombie( void ) {
	std::cout << "Zombie " << this->_name << " flopped over." << std::endl;
	return;
}

void Zombie::announce( void ) {
	// srand(time(NULL));
	std::string quote;
	if (this->_type.compare("Old Friend") == 0) {
		quote = "To be, or to zombie? That is the question~";
	} else if (this->_type.compare("Lawyer") == 0) {
		quote = "Objection overwritten; I need BRAINS!";
	} else {
		quote = "Ra";
		quote.append(rand() % 12, 'a');
		quote.append("ah!");
	}
	std::cout << '<' << this->_name << " (" << this->_type << ")> " << quote << std::endl;
}

std::string Zombie::_random_name( void ) {
	// srand(time(NULL));
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
	return name;
}

Zombie* Zombie::randomChump(std::string type) {
	return (new Zombie(Zombie::_random_name(), type));
}
