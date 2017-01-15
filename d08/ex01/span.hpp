/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 16:43:25 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/14 18:46:52 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
# define SPAN_H

#include <algorithm>
#include <vector>
#include <iostream>

class Span {

public:
	Span( unsigned int );
	Span( Span const & obj );
	~Span( void );
	Span & operator=( Span const & rhs );

	int shortestSpan( void );
	int longestSpan( void );
	void addNumber( int );
	void addRange(std::vector<int>::iterator, std::vector<int>::iterator);
	unsigned int getCount( void );

	struct SpanTooShort : std::exception {
		const char* what( void ) const _NOEXCEPT;
	};
	struct SpanFull : std::exception {
		const char* what( void ) const _NOEXCEPT;
	};

private:
	unsigned int		_count;
	std::vector<int>*	_vector;
	bool				_do_sort;

	void _sort( void );

	Span( void );
};

#endif
