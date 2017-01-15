/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 14:05:05 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/08 14:26:59 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_H
# define AWEAPON_H

# include <string>

class AWeapon {

public:

	AWeapon( std::string const & name, int apcost, int damage );
	AWeapon( AWeapon const & obj );

	virtual ~AWeapon( void );

	AWeapon & operator=( AWeapon const & rhs );

	std::string const & getName( void ) const;
	int getAPCost( void ) const;
	int getDamage( void ) const;
	virtual void attack( void ) const = 0;

protected:
	AWeapon( void );

	std::string _name;
	int _ap_cost;
	int _damage;
};

#endif
