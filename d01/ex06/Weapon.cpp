/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 16:20:30 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/05 17:26:48 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type ) : _type(type) {
	return;
}

Weapon::~Weapon( void ) {
	return;
}

void Weapon::setType( std::string type ) {
	this->_type = type;
}

std::string const & Weapon::getType( void ) const {
	return (this->_type);
}
