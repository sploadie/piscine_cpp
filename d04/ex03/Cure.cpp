/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 19:54:06 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/08 22:27:44 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure( void ) : AMateria("cure") {}

Cure::Cure( Cure const & obj ) : AMateria("cure") { *this = obj; }

Cure::~Cure( void ) {}

Cure & Cure::operator=( Cure const & rhs ) {
	this->AMateria::operator=(rhs);
	return *this;
}

AMateria* Cure::clone( void ) const { return new Cure(*this); }

void Cure::use( ICharacter& target ) {
	this->AMateria::use(target);
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
