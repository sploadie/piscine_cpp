/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 11:14:56 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/08 12:40:59 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_H
# define PEON_H

# include "Victim.hpp"
# include <iostream>
# include <string>

class Peon : public Victim {

public:

	Peon( std::string const & name );
	Peon( Peon const & obj );

	~Peon( void );

	Peon & operator=( Peon const & rhs );

	void proclaim_birth( void ) const;
	void getPolymorphed( void ) const;

protected:
	Peon( void );

};

#endif
