/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OpToken.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 20:07:17 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/14 20:48:29 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTOKEN_H
# define OPTOKEN_H

# include "Token.hpp"

class OpToken : public Token, public std::string {

public:

	OpToken( char );
	OpToken( OpToken const & obj );

	~OpToken( void );

	OpToken & operator=( OpToken const & rhs );

	bool isOp( void ) const;
	std::string const & toString( void ) const;

private:
	OpToken( void );

};

#endif
