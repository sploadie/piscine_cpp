/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   better_main.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 11:40:37 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/08 13:07:46 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
#include <iostream>

int		main( void ) {
	std::cout << "Sorcerers:" << std::endl; // Sorcerers
	Sorcerer jim("Jim", "Wandmaker");
	std::cout << jim;
	Sorcerer joe("Joe", "Bootlegger");
	std::cout << joe;
	Sorcerer cpy(jim);
	std::cout << cpy;
	cpy = Sorcerer("Ripto", "Destroyer of Spyro");
	std::cout << cpy << std::endl;
	std::cout << std::endl << "Victims:" << std::endl; // Victims
	Victim victim1("Robert");
	std::cout << victim1;
	Victim victim2("Bobby");
	std::cout << victim2;
	Victim victim3(victim1);
	std::cout << victim3;
	victim3 = Victim("Spyro");
	std::cout << victim3;
	victim1.getPolymorphed();
	victim2.getPolymorphed();
	jim.polymorph(victim3);
	std::cout << std::endl << "Peons:" << std::endl; // Peons
	Peon peon1("Hector");
	std::cout << peon1;
	Peon peon2("Elliot");
	std::cout << peon2;
	Peon peon3(peon1);
	std::cout << peon3;
	peon3 = Peon("Scillia");
	std::cout << peon3;
	peon1.getPolymorphed();
	peon2.getPolymorphed();
	jim.polymorph(peon3);

	std::cout << std::endl << "Main End:" << std::endl;
	return 0;
}
