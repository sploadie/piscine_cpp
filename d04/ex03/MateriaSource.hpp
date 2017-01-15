/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 19:54:07 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/08 22:21:54 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {

public:

	MateriaSource( void );
	MateriaSource( MateriaSource const & obj );

	~MateriaSource( void );

	MateriaSource & operator=( MateriaSource const & rhs );

	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);

protected:
	AMateria * *	_materias;

private:
	static int const  _MaxMateria = 4;

};

#endif
