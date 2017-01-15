/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 17:07:25 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/08 18:50:09 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TACTICALMARINE_H
# define TACTICALMARINE_H

# include <iostream>
# include <string>
# include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine {

public:

	TacticalMarine( void );
	TacticalMarine( TacticalMarine const & obj );

	~TacticalMarine( void );

	TacticalMarine & operator=( TacticalMarine const & rhs );

	TacticalMarine * clone( void ) const;
	void battleCry( void ) const;
	void rangedAttack( void ) const;
	void meleeAttack( void ) const;

private:
	static std::string const _FirstCall;
};

#endif
