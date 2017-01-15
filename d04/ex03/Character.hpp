/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 22:08:04 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/08 22:23:08 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
# define CHARACTER_H

# include <iostream>
# include <string>
# include <cstddef>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter {

public:
	Character( std::string const & name );
	Character( Character const & obj );

	~Character( void );

	Character & operator=( Character const & rhs );

	std::string const & getName( void ) const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

protected:
	std::string		_name;
	AMateria * *	_materias;

private:
	Character( void );

	static int const  _MaxMateria = 4;

};

#endif
