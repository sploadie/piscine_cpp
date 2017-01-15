/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 16:01:17 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/05 16:05:40 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int		main( void ) {
	std::string str("HI THIS IS BRAIN");
	std::string* ptr = &str;
	std::string& ref = str;

	std::cout << *ptr << std::endl;
	std::cout << ref << std::endl;

	return 0;
}
