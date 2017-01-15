/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 18:13:21 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/08 19:05:27 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"

Squad::Squad( void ) : _count(0), _array_size(Squad::_AllocSize) {
	this->_marines = new ISpaceMarine * [this->_array_size];
	return;
}

Squad::Squad( Squad const & obj ) {
	*this = obj;
	return;
}

Squad::~Squad( void ) {
	for (int i=0;i<this->_count;i++) { delete this->_marines[i]; }
	delete this->_marines;
	return;
}

Squad & Squad::operator=( Squad const & rhs ) {
	int i;
	// Delete
	for (i=0;i<this->_count;i++) { delete this->_marines[i]; }
	delete this->_marines;
	// Copy
	this->_count = rhs._count;
	this->_array_size = rhs._array_size;
	this->_marines = new ISpaceMarine * [this->_array_size];
	for (i=0;i<this->_count;i++) { this->_marines[i] = rhs._marines[i]->clone(); }
	return *this;
}

int Squad::getCount( void ) const {
	return this->_count;
}

ISpaceMarine * Squad::getUnit( int i ) const {
	if (i < 0 || i >= this->_count) { return NULL; }
	return this->_marines[i];
}

int Squad::push( ISpaceMarine * newbie ) {
	int i;
	if (newbie == NULL) { return this->_count; }
	for (i=0;i<this->_count;i++) { if (this->_marines[i] == newbie) { return this->_count; } }
	if (this->_count == this->_array_size) {
		this->_array_size += Squad::_AllocSize;
		ISpaceMarine ** tmp = new ISpaceMarine * [this->_array_size];
		for (i=0;i<this->_count;i++) { tmp[i] = this->_marines[i]; }
		delete this->_marines;
		this->_marines = tmp;
	}
	this->_marines[this->_count++] = newbie;
	return this->_count;
}
