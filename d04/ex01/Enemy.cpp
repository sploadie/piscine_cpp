/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 15:32:22 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/08 16:05:57 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy( void ) : _hp(0), _type(std::string("Corpse")) {
	return;
}

Enemy::Enemy( int hp, std::string const & type ) : _hp(hp), _type(type) {
	return;
}

Enemy::Enemy( Enemy const & obj ) {
	*this = obj;
	return;
}

Enemy::~Enemy( void ) {
	return;
}

Enemy & Enemy::operator=( Enemy const & rhs ) {
	this->_hp   = rhs._hp;
	this->_type = rhs._type;
	return *this;
}

std::string const & Enemy::getType( void ) const { return this->_type; }
int					Enemy::getHP( void )   const { return this->_hp;   }

void Enemy::takeDamage( int damage ) {
	if (damage < 0) { return; }
	this->_hp -= damage;
	if (this->_hp < 0) { this->_hp = 0; }
	return;
}
