/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 16:20:30 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/05 16:56:28 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human( void ){
	return;
}

Human::~Human( void ){
	return;
}

Brain const & Human::getBrain( void ) const {
	return this->_brain;
}

std::string Human::identify( void ) const {
	return this->_brain.identify();
}
