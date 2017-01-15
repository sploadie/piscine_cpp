/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 17:07:25 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/08 19:06:48 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_H
# define SQUAD_H

# include <cstddef>
# include "ISquad.hpp"

class Squad : public ISquad {

public:

	Squad( void );
	Squad( Squad const & obj );

	~Squad( void );

	Squad & operator=( Squad const & rhs );

	int getCount( void ) const;
	ISpaceMarine* getUnit( int ) const;
	int push( ISpaceMarine * );

private:
	int					_count;
	int					_array_size;
	ISpaceMarine **		_marines;

	static int const	_AllocSize = 32;

};

#endif
