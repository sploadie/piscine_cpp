/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 10:47:54 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/07 13:58:44 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include <iostream>
# include <cstdlib>

class FragTrap {

public:

	FragTrap( std::string const & name );
	FragTrap( FragTrap const & obj );

	~FragTrap( void );

	FragTrap & operator=( FragTrap const & rhs );


	void rangedAttack(std::string const & target) const;
	void meleeAttack(std::string const & target) const;
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	void vaulthunter_dot_exe(std::string const & target);

protected:

	static std::string const	_prefix;
	std::string					_name;

	static unsigned int const	_Level = 1;
	static unsigned int const	_Max_Hit_Points	= 100;
	unsigned int				_hit_points;
	static unsigned int const	_Max_Energy		= 100;
	unsigned int				_energy;

	static unsigned int const	_Melee_Dmg	= 30;
	static unsigned int const	_Ranged_Dmg	= 20;
	static unsigned int const	_Armor		= 5;
};

#endif
