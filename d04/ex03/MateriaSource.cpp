/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 19:54:07 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/08 22:28:40 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void ) {
	this->_materias = new AMateria * [MateriaSource::_MaxMateria];
	for (int i=0;i<MateriaSource::_MaxMateria;i++) { this->_materias[i] = NULL; }
}

MateriaSource::MateriaSource( MateriaSource const & obj ) {
	this->_materias = new AMateria * [MateriaSource::_MaxMateria];
	for (int i=0;i<MateriaSource::_MaxMateria;i++) { this->_materias[i] = NULL; }
	*this = obj;
}

MateriaSource::~MateriaSource( void ) {
	for (int i=0;i<MateriaSource::_MaxMateria;i++) {
		if (this->_materias[i] != NULL) { delete this->_materias[i]; }
	}
	delete this->_materias;
	return;
}

MateriaSource & MateriaSource::operator=( MateriaSource const & rhs ) {
	for (int i=0;i<MateriaSource::_MaxMateria;i++) {
		if (this->_materias[i] != NULL) { delete this->_materias[i]; this->_materias[i] = NULL; }
		if (rhs._materias[i]   != NULL) { this->_materias[i] = rhs._materias[i]->clone(); }
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
	for (int i=0;i<MateriaSource::_MaxMateria;i++) {
		if (this->_materias[i] == NULL) {
			this->_materias[i] = m;
			return;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i=0;i<MateriaSource::_MaxMateria;i++) {
		if (this->_materias[i]->getType() == type) {
			return this->_materias[i]->clone();
		}
	}
	return NULL;
}
