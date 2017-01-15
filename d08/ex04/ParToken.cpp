/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParToken.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 20:52:18 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/14 20:52:29 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ParToken.hpp"

ParToken::ParToken( void ) {}
ParToken::ParToken( char c ) : std::string(1,c) {}
ParToken::ParToken( ParToken const & obj ) { *this = obj; }
ParToken::~ParToken( void ) {}

ParToken & ParToken::operator=( ParToken const & rhs ) {
	this->std::string::operator=(rhs);
	return *this;
}

bool ParToken::isPar( void ) const { return true; }

std::string const & ParToken::toString( void ) const { return this; }
