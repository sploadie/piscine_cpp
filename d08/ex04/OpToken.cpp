/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OpToken.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 20:49:57 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/14 20:51:39 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OpToken.hpp"

OpToken::OpToken( void ) {}
OpToken::OpToken( char c ) : std::string(1,c) {}
OpToken::OpToken( OpToken const & obj ) { *this = obj; }
OpToken::~OpToken( void ) {}

OpToken & OpToken::operator=( OpToken const & rhs ) {
	this->std::string::operator=(rhs);
	return *this;
}

bool OpToken::isOp( void ) const { return true; }

std::string const & OpToken::toString( void ) const { return this; }
