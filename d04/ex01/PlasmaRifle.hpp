/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 12:50:58 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/08 15:18:07 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLASMARIFLE_H
# define PLASMARIFLE_H

# include <iostream>
# include "AWeapon.hpp"

class PlasmaRifle : public AWeapon {

public:

	PlasmaRifle( void );
	PlasmaRifle( PlasmaRifle const & obj );

	~PlasmaRifle( void );

	PlasmaRifle & operator=( PlasmaRifle const & rhs );

	virtual void attack( void ) const;

private:
	static std::string const	_Name;
	static int const			_ApCost = 5;
	static int const			_Damage = 21;

};

#endif
