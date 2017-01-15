/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 20:07:17 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/14 20:34:02 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include <iostream>
# include <string>

class Token {

public:
	virtual std::string const & toString( void ) const = 0;

	virtual bool isNum( void ) const;
	virtual bool isOp( void ) const;
	virtual bool isPar( void ) const;
};

std::ostream & operator<<(std::ostream & o, Token const & rhs);

#endif
