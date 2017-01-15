/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 12:50:58 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/08 15:25:49 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWERFIST_H
# define POWERFIST_H

# include <iostream>
# include "AWeapon.hpp"

class PowerFist : public AWeapon {

public:

	PowerFist( void );
	PowerFist( PowerFist const & obj );

	~PowerFist( void );

	PowerFist & operator=( PowerFist const & rhs );

	virtual void attack( void ) const;

private:
	static std::string const	_Name;
	static int const			_ApCost = 8;
	static int const			_Damage = 50;

};

#endif
