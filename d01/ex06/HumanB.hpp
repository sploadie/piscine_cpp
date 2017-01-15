/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 16:20:30 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/05 17:36:58 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

# include "Weapon.hpp"
# include <iostream>
# include <string>

class HumanB {

public:

	HumanB( std::string name );
	~HumanB( void );

	void setWeapon( Weapon & club );
	void attack( void ) const;

private:

	Weapon* _weapon;
	std::string _name;

};

#endif
