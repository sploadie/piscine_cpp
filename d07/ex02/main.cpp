/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 10:24:51 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/13 14:39:08 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include "Array.hpp"

template <class T> void iter( Array<T>& a, unsigned int size, void (*f)(T&) ) {
	for (unsigned int i=0;i<size;i++) { f( a[i] ); }
}

void output_f(float& v)			{ std::cout << v << std::endl; }
void output_str(std::string& v)	{ std::cout << v << std::endl; }
void output_i(int& v)			{ std::cout << v << std::endl; }
void output_c(char& v)			{ std::cout << v << std::endl; }

template <class T> void output_any(T v)	{ std::cout << v << std::endl; }

int main( void ) {
	// std::string	str_a[]	= {"ONE", "TWO", "THREE"};
	// int			i_a[]	= {1, 2, 3};
	// char		c_a[]	= {'a', 'b', 'c'};
	Array<float>		empty_a;
	Array<std::string>	str_a(3);
	Array<int>			i_a(3);
	Array<char>			c_a(3);

	str_a[0] = "ONE";
	str_a[1] = "TWO";
	str_a[2] = "THREE";
	unsigned int i;
	for (i=0;i<3;i++) {
		i_a[i] = 1+i;
		c_a[i] = 'a'+i;
	}

	std::cout << std::endl << "Specific:" << std::endl;
	::iter(empty_a, empty_a.size(), &output_f);
	::iter(str_a, str_a.size(), &output_str);
	::iter(i_a, i_a.size(), &output_i);
	::iter(c_a, c_a.size(), &output_c);
	std::cout << std::endl << "Generic:" << std::endl;
	::iter(empty_a, empty_a.size(), &output_any);
	::iter(str_a, str_a.size(), &output_any);
	::iter(i_a, i_a.size(), &output_any);
	::iter(c_a, c_a.size(), &output_any);

	try {
		std::cout << empty_a[0] << std::endl;
	} catch( std::exception & e ) { std::cerr << "std::exception caught! (" << e.what() << ")" << std::endl; }
	try {
		std::cout << str_a[-1] << std::endl;
	} catch( std::exception & e ) { std::cerr << "std::exception caught! (" << e.what() << ")" << std::endl; }
	try {
		std::cout << i_a[3] << std::endl;
	} catch( std::exception & e ) { std::cerr << "std::exception caught! (" << e.what() << ")" << std::endl; }
	return 0;
}
