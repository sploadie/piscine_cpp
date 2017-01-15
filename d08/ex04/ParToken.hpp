/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParToken.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 20:07:17 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/14 20:48:24 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARTOKEN_H
# define PARTOKEN_H

# include "Token.hpp"

class ParToken : public Token, public std::string {

public:

	ParToken( char );
	ParToken( ParToken const & obj );

	~ParToken( void );

	ParToken & operator=( ParToken const & rhs );

	bool isPar( void ) const;
	std::string const & toString( void ) const;

private:
	ParToken( void );

};

#endif
