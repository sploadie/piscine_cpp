/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 14:54:02 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/07 17:23:03 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_H
# define NINJATRAP_H

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap : public virtual ClapTrap {

public:

	NinjaTrap( std::string const & name );
	NinjaTrap( NinjaTrap const & obj );

	~NinjaTrap( void );

	NinjaTrap & operator=( NinjaTrap const & rhs );

	void ninjaShoebox(ClapTrap  const & trap) const;
	void ninjaShoebox(FragTrap  const & trap) const;
	void ninjaShoebox(ScavTrap  const & trap) const;
	void ninjaShoebox(NinjaTrap const & trap) const;

protected:

	static std::string const	_prefix;

	static unsigned int const	_Level = 1;
	static unsigned int const	_Max_Hit_Points	= 60;
	static unsigned int const	_Max_Energy		= 120;

	static unsigned int const	_Melee_Dmg	= 60;
	static unsigned int const	_Ranged_Dmg	= 5;
	static unsigned int const	_Armor		= 0;
};

#endif

