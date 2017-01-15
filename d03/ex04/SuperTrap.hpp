/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 14:54:02 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/07 17:19:13 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_H
# define SUPERTRAP_H

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap {

public:

	SuperTrap( std::string const & name );
	SuperTrap( SuperTrap const & obj );

	~SuperTrap( void );

	SuperTrap & operator=( SuperTrap const & rhs );

protected:

	static std::string const	_prefix;

	static unsigned int const	_Level = 1;
	static unsigned int const	_Max_Hit_Points	= FragTrap::_Max_Hit_Points;
	static unsigned int const	_Max_Energy		= NinjaTrap::_Max_Energy;

	static unsigned int const	_Melee_Dmg	= NinjaTrap::_Melee_Dmg;
	static unsigned int const	_Ranged_Dmg	= FragTrap::_Ranged_Dmg;
	static unsigned int const	_Armor		= FragTrap::_Armor;
};

#endif

