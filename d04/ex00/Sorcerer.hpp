/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 11:14:56 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/08 12:00:04 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_H
# define SORCERER_H

# include "Victim.hpp"
# include <iostream>
# include <string>

class Sorcerer {

public:

	Sorcerer( std::string const & name, std::string const & title );
	Sorcerer( Sorcerer const & obj );

	~Sorcerer( void );

	Sorcerer & operator=( Sorcerer const & rhs );

	void proclaim_birth( void ) const;
	void polymorph(Victim const & victim) const;

	std::string const & getName( void )  const;
	std::string const & getTitle( void ) const;

private:
	Sorcerer( void );

	std::string _name;
	std::string _title;

};

std::ostream & operator<<(std::ostream & o, Sorcerer const & rhs);

#endif
