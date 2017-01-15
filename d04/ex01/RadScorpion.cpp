/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 15:58:34 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/08 16:46:24 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RadScorpion.hpp"

RadScorpion::RadScorpion( void ) : Enemy(80, std::string("RadScorpion")) {
	std::cout << "* click click click *" << std::endl;
	return;
}

RadScorpion::RadScorpion( RadScorpion const & obj ) : Enemy(obj) {
	std::cout << "* click click click *" << std::endl;
	return;
}

RadScorpion::~RadScorpion( void ) {
	std::cout << "* SPROTCH *" << std::endl;
	return;
}

RadScorpion & RadScorpion::operator=( RadScorpion const & rhs ) {
	this->Enemy::operator=(rhs);
	return *this;
}
