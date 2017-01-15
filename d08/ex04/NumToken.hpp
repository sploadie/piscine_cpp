/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NumToken.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 20:07:17 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/14 20:48:19 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUMTOKEN_H
# define NUMTOKEN_H

# include "Token.hpp"
# include "Fixed.hpp"
# include <sstream>

class NumToken : public Token, public Fixed {

public:

	NumToken( int );
	NumToken( NumToken const & obj );

	~NumToken( void );

	NumToken & operator=( NumToken const & rhs );

	bool isNum( void ) const;
	std::string const & toString( void ) const;

private:
	NumToken( void );

};

#endif
