/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 14:54:13 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/07 15:10:53 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

public:

	ScavTrap( std::string const & name );
	ScavTrap( ScavTrap const & obj );

	~ScavTrap( void );

	ScavTrap & operator=( ScavTrap const & rhs );

	void rangedAttack(std::string const & target) const;
	void meleeAttack(std::string const & target) const;

	void challengeNewcomer(std::string const & target);

protected:

	static std::string const	_prefix;

	static unsigned int const	_Level = 1;
	static unsigned int const	_Max_Hit_Points	= 100;
	static unsigned int const	_Max_Energy		= 50;

	static unsigned int const	_Melee_Dmg	= 20;
	static unsigned int const	_Ranged_Dmg	= 15;
	static unsigned int const	_Armor		= 3;

};

#endif

