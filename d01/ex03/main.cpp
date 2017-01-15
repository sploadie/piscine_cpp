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
#include "Zombie.hpp"
#include "ZombieHorde.hpp"

void	fred_speaks(std::string text) {
	std::cout << "<Fred (Human)> " << text << std::endl;
}

int		main( void ) {
	srand(time(NULL));
	fred_speaks("Week 23; I don't know why I'm still alive, so much has happened since-");
	ZombieHorde horde(7);
	fred_speaks("Alright, I'm ready this time... * COCKS SHOTGUN *");
	horde.announce();
	fred_speaks("Come at me you mindless fools!");

	// while (1) {}
	return 0;
}
