/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 10:35:54 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/05 15:05:15 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"
#include "ZombieEvent.hpp"

void	fred_speaks(std::string text) {
	std::cout << "<Fred (Human)> " << text << std::endl;
}

int		main( void ) {
	int i;

	Zombie jim("Jim", "Old Friend");
	fred_speaks("Oh god- Jim is that you?!");
	jim.announce();
	fred_speaks("Shit shit shit- what happened?!");

	ZombieEvent explosion;
	explosion.setZombieType("Lawyer");

	fred_speaks("Whoa! * STUMBLES *");

	Zombie* lawyers[] = {
		explosion.newZombie("Chris"),
		explosion.newZombie("Robert"),
		explosion.newZombie("Justine"),
	};

	fred_speaks("Are those..?");

	for (i=0;i<3;i++) { lawyers[i]->announce(); }

	fred_speaks("I need to hurry and-!");

	Zombie* ass = Zombie::randomChump("Hungry Zombie");
	ass->announce();

	fred_speaks("* DYING NOISES *");

	delete ass;
	for (i=0;i<3;i++) { delete lawyers[i]; }

	// while (1) {}
	return 0;
}
