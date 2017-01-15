/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 10:24:51 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/14 14:12:33 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>

template <class T> void iter( T* a, int size, void (*f)(T) ) {
	for (int i=0;i<size;i++) { f( a[i] ); }
}
template <class T> void iter( T* a, int size, void (*f)(T&) ) {
	for (int i=0;i<size;i++) { f( a[i] ); }
}
template <class T> void iter( T* a, int size, void (*f)(T const &) ) {
	for (int i=0;i<size;i++) { f( a[i] ); }
}

void output_str(std::string& v)	{ std::cout << v << std::endl; }
void output_i(int v)			{ std::cout << v << std::endl; }
void output_c(char v)			{ std::cout << v << std::endl; }

template <class T> void output_any(T const & v)	{ std::cout << v << std::endl; }

int main( void ) {
	std::string	str_a[]	= {"ONE", "TWO", "THREE"};
	int			i_a[]	= {1, 2, 3};
	char		c_a[]	= {'a', 'b', 'c'};

	std::cout << std::endl << "Specific:" << std::endl;
	::iter(str_a, 3, output_str);
	::iter(i_a, 3, output_i);
	::iter(c_a, 3, output_c);
	std::cout << std::endl << "Generic:" << std::endl;
	::iter(str_a, 3, output_any);
	::iter(i_a, 3, output_any);
	::iter(c_a, 3, output_any);
	return 0;
}
