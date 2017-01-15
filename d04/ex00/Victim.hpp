/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 11:14:56 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/08 12:40:37 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_H
# define VICTIM_H

# include <iostream>
# include <string>

class Victim {

public:

	Victim( std::string const & name );
	Victim( Victim const & obj );

	~Victim( void );

	Victim & operator=( Victim const & rhs );

	void proclaim_birth( void ) const;
	virtual void getPolymorphed( void ) const;

	std::string const & getName( void )  const;

protected:
	Victim( void );

	std::string	_name;
};

std::ostream & operator<<(std::ostream & o, Victim const & rhs);

#endif
