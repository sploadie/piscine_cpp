/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 19:54:06 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/08 22:27:39 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice( void ) : AMateria("ice") {}

Ice::Ice( Ice const & obj ) : AMateria("ice") { *this = obj; }

Ice::~Ice( void ) {}

Ice & Ice::operator=( Ice const & rhs ) {
	this->AMateria::operator=(rhs);
	return *this;
}

AMateria* Ice::clone( void ) const { return new Ice(*this); }

void Ice::use( ICharacter& target ) {
	this->AMateria::use(target);
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
