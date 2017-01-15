/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 10:47:54 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/07 14:24:31 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include <iostream>
# include <cstdlib>

class ScavTrap {

public:

	ScavTrap( std::string const & name );
	ScavTrap( ScavTrap const & obj );

	~ScavTrap( void );

	ScavTrap & operator=( ScavTrap const & rhs );


	void rangedAttack(std::string const & target) const;
	void meleeAttack(std::string const & target) const;
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	void challengeNewcomer(std::string const & target);

protected:

	static std::string const	_prefix;
	std::string					_name;

	static unsigned int const	_Level = 1;
	static unsigned int const	_Max_Hit_Points	= 100;
	unsigned int				_hit_points;
	static unsigned int const	_Max_Energy		= 50;
	unsigned int				_energy;

	static unsigned int const	_Melee_Dmg	= 20;
	static unsigned int const	_Ranged_Dmg	= 15;
	static unsigned int const	_Armor		= 3;
};

#endif
