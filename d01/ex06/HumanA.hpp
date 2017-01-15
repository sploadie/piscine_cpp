/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 16:20:30 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/05 17:23:15 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

# include "Weapon.hpp"
# include <iostream>
# include <string>

class HumanA {

public:

	HumanA( std::string name, Weapon & club );
	~HumanA( void );

	void attack( void ) const;

private:

	Weapon & _weapon;
	std::string _name;

};

#endif
