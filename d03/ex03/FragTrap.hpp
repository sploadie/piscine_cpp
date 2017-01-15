/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 14:54:02 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/07 15:09:47 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

public:

	FragTrap( std::string const & name );
	FragTrap( FragTrap const & obj );

	~FragTrap( void );

	FragTrap & operator=( FragTrap const & rhs );

	void vaulthunter_dot_exe(std::string const & target);

protected:

	static std::string const	_prefix;

	static unsigned int const	_Level = 1;
	static unsigned int const	_Max_Hit_Points	= 100;
	static unsigned int const	_Max_Energy		= 100;

	static unsigned int const	_Melee_Dmg	= 30;
	static unsigned int const	_Ranged_Dmg	= 20;
	static unsigned int const	_Armor		= 5;
};

#endif

