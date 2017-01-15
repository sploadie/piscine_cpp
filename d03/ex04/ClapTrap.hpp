/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 10:47:54 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/07 15:52:38 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>
# include <cstdlib>

class ClapTrap {

public:

	ClapTrap( std::string const & name );
	ClapTrap( ClapTrap const & obj );

	~ClapTrap( void );

	ClapTrap & operator=( ClapTrap const & rhs );


	void rangedAttack(std::string const & target) const;
	void meleeAttack(std::string const & target) const;
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	std::string const & getName( void ) const;

protected:

	static std::string const	_prefix;
	std::string					_name;

	static unsigned int const	_Level = 42;
	static unsigned int const	_Max_Hit_Points	= 42;
	unsigned int				_hit_points;
	static unsigned int const	_Max_Energy		= 42;
	unsigned int				_energy;

	static unsigned int const	_Melee_Dmg	= 42;
	static unsigned int const	_Ranged_Dmg	= 42;
	static unsigned int const	_Armor		= 42;
};

#endif
