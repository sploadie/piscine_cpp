/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 10:24:51 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/13 12:02:44 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>

template <class T> void swap ( T& a, T& b ) { T c(a); a=b; b=c; }
template <class T> T& min (T& a, T& b) { return a<b?a:b; }
template <class T> T& max (T& a, T& b) { return a>b?a:b; }

int main( void ) {
	std::string	str1	= "str1";
	std::string	str2	= "str2";
	int			i1		= 1;
	int			i2		= 2;
	char		c1		= '1';
	char		c2		= '2';

	std::cout << std::endl << "PreSwap:" << std::endl;
	std::cout << str1 << " - " << str2 << " - " << i1 << " - " << i2 << " - " << c1 << " - " << c2 << std::endl;
	::swap(str1, str2);
	::swap(i1, i2);
	::swap(c1, c2);
	std::cout << "PostSwap:" << std::endl;
	std::cout << str1 << " - " << str2 << " - " << i1 << " - " << i2 << " - " << c1 << " - " << c2 << std::endl;
	// Min Max Different
	std::cout << "Min:" << std::endl;
	std::cout << ::min(str1, str2) << " - " << ::min(i1, i2) << " - " << ::min(c1, c2) << std::endl;
	std::cout << "Max:" << std::endl;
	std::cout << ::max(str1, str2) << " - " << ::max(i1, i2) << " - " << ::max(c1, c2) << std::endl;
	::swap(str1, str2);
	::swap(i1, i2);
	::swap(c1, c2);
	std::cout << "PostReSwap:" << std::endl;
	std::cout << str1 << " - " << str2 << " - " << i1 << " - " << i2 << " - " << c1 << " - " << c2 << std::endl;
	std::cout << "Min:" << std::endl;
	std::cout << ::min(str1, str2) << " - " << ::min(i1, i2) << " - " << ::min(c1, c2) << std::endl;
	std::cout << "Max:" << std::endl;
	std::cout << ::max(str1, str2) << " - " << ::max(i1, i2) << " - " << ::max(c1, c2) << std::endl;
	// Min Max Same
	str1 = "same";
	str2 = "same";
	i1 = 1;
	i2 = 1;
	c1 = 'a';
	c2 = 'a';
	std::cout << "NewValues:" << std::endl;
	std::cout << str1 << " - " << str2 << " - " << i1 << " - " << i2 << " - " << c1 << " - " << c2 << std::endl;
	std::string	&	str_min =	::min(str1, str2);
	int &			i_min =		::min(i1, i2);
	char &			c_min =		::min(c1, c2);
	std::string	&	str_max =	::max(str1, str2);
	int &			i_max =		::max(i1, i2);
	char &			c_max =		::max(c1, c2);
	std::cout << "Min:" << std::endl;
	std::cout << str_min << " - " << i_min << " - " << c_min << std::endl;
	std::cout << "Max:" << std::endl;
	std::cout << str_max << " - " << i_max << " - " << c_max << std::endl;
	str1 = "str1";
	str2 = "str2";
	i1 = 1;
	i2 = 2;
	c1 = '1';
	c2 = '2';
	std::cout << "OldValuesMin:" << std::endl;
	std::cout << str_min << " - " << i_min << " - " << c_min << std::endl;
	std::cout << "OldValuesMax:" << std::endl;
	std::cout << str_max << " - " << i_max << " - " << c_max << std::endl;
	return 0;
}
