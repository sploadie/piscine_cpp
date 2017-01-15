/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 16:10:58 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/08 16:48:17 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
# define CHARACTER_H

# include <iostream>
# include <string>
# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character {

public:

	Character( std::string const & name );
	Character( Character const & obj );

	~Character( void );

	Character & operator=( Character const & rhs );

	void recoverAP( void );
	void equip(AWeapon*);
	void attack(Enemy*);
	std::string	const &	getName( void )		const;
	int					getAP( void )		const;
	AWeapon			  *	getWeapon( void )	const;

private:
	Character( void );

	std::string	_name;
	int			_ap;
	AWeapon *	_weapon;

	static int const	_MaxAP = 40;
};

std::ostream & operator<<(std::ostream & o, Character const & rhs);

#endif
