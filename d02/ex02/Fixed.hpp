/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 13:39:05 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/06 17:50:31 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <cmath>

class Fixed {

public:

	Fixed( void );
	Fixed( Fixed const & obj );
	Fixed( int i );
	Fixed( int i, bool );
	Fixed( float f );

	~Fixed( void );

	Fixed &	operator=( int const i );
	Fixed &	operator=( float const f );
	Fixed &	operator=( Fixed const & rhs );
	Fixed	operator+( Fixed const & rhs ) const;
	Fixed	operator-( Fixed const & rhs ) const;
	Fixed	operator*( Fixed const & rhs ) const;
	Fixed	operator/( Fixed const & rhs ) const;

	Fixed &	operator++( void );
	Fixed &	operator--( void );
	Fixed	operator++( int );
	Fixed	operator--( int );

	bool	operator==( Fixed const & rhs ) const;
	bool	operator!=( Fixed const & rhs ) const;
	bool	operator< ( Fixed const & rhs ) const;
	bool	operator> ( Fixed const & rhs ) const;
	bool	operator<=( Fixed const & rhs ) const;
	bool	operator>=( Fixed const & rhs ) const;

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

	float	toFloat( void ) const;
	int		toInt( void ) const;

	static Fixed &			max(Fixed & lhs, Fixed & rhs);
	static Fixed const &	max(Fixed const & lhs, Fixed const & rhs);
	static Fixed &			min(Fixed & lhs, Fixed & rhs);
	static Fixed const &	min(Fixed const & lhs, Fixed const & rhs);

private:

	int _value;
	static int const _b_point = 8;

};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif

