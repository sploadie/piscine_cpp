/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 20:17:09 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/08 22:26:37 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria( void ) : _type("None") {}

AMateria::AMateria( std::string const & type ) : _type(type) {}

AMateria::AMateria( AMateria const & obj ) { *this = obj; }

AMateria::~AMateria( void ) {}

AMateria & AMateria::operator=( AMateria const & rhs ) {
	this->_xp = rhs._xp;
	return *this;
}

std::string  const & AMateria::getType( void ) const { return this->_type; }
unsigned int         AMateria::getXP( void )   const { return this->_xp; }

void AMateria::use( ICharacter& target ) { (void)target; this->_xp++; }
