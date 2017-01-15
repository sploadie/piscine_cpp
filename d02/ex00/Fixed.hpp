/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 13:39:05 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/06 13:55:46 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed {

public:

	Fixed( void );
	Fixed( Fixed const & obj );

	~Fixed( void );

	Fixed &	operator=( Fixed const & rhs );

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

private:

	int _value;
	static int const _b_point = 8;

};

#endif

