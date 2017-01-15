/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 10:35:54 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/05 15:58:23 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Human.hpp"
#include "Brain.hpp"

int		main( void ) {
	Brain b;
	std::cout << "Brain b's address in memory:" << std::endl;
	std::cout << "Using Identify: " << b.identify() << std::endl;
	std::cout << "Using Pointer:  " << std::hex << &b << std::dec << std::endl;

	Human bob;
	std::cout << "Human bob's brain's address in memory:" << std::endl;
	std::cout << bob.identify() << std::endl;
	std::cout << bob.getBrain().identify() << std::endl;

	// while (1) {}
	return 0;
}
