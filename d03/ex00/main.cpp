/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 11:36:46 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/07 14:25:25 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>
#include <cstdlib>

void	fred_speaks(std::string text) {
	std::cout << "<Human Fred> " << text << std::endl;
}

int		main( void ) {
	srand(time(NULL)); // Set RNG

	fred_speaks("It's been 3, maybe 4 years now, I'm alive but I'm alone.");
	fred_speaks("I've been working quite hard, and I think I have a solution...");
	FragTrap silver("Silver");
	FragTrap shiny(silver);
	FragTrap gold("Gold");
	shiny = gold;
	FragTrap chromed(shiny);
	fred_speaks("Huzzah! Go kill that zombie!");
	silver.meleeAttack("Zombie");
	chromed.takeDamage(28);
	shiny.takeDamage(4);
	silver.takeDamage(5);
	shiny.rangedAttack("Zombie");
	chromed.takeDamage(88);
	fred_speaks("Oh no GoldII!");
	chromed.beRepaired(45);
	chromed.beRepaired(45);
	chromed.beRepaired(45);
	fred_speaks("Now, final attack!");
	silver.vaulthunter_dot_exe("Zombie");
	shiny.vaulthunter_dot_exe("Zombie");
	gold.vaulthunter_dot_exe("Zombie");
	chromed.vaulthunter_dot_exe("Zombie");
	chromed.vaulthunter_dot_exe("Zombie");
	chromed.vaulthunter_dot_exe("Zombie");
	chromed.vaulthunter_dot_exe("Zombie");
	chromed.vaulthunter_dot_exe("Zombie");
	fred_speaks("Awesome! Now for MarkII...");
	return 0;
}
