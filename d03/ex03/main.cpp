/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 11:36:46 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/07 15:58:56 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include <iostream>
#include <cstdlib>

void	fred_speaks(std::string text) {
	std::cout << "<Human Fred> " << text << std::endl;
}

void	frag_main( void ) {
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
}

void	scav_main( void ) {
	fred_speaks("It's been another week:");
	fred_speaks("I've been working quite hard to create MarkII...");
	ScavTrap silver("Hinges");
	ScavTrap shiny(silver);
	ScavTrap gold("Pane");
	shiny = gold;
	ScavTrap chromed(shiny);
	fred_speaks("Huzzah! Kill the oncoming zombies!");
	silver.meleeAttack("Zombie");
	chromed.takeDamage(28);
	shiny.takeDamage(3);
	silver.takeDamage(5);
	shiny.rangedAttack("Zombie");
	chromed.takeDamage(88);
	fred_speaks("Oh no GoldII!");
	chromed.beRepaired(45);
	chromed.beRepaired(45);
	chromed.beRepaired(45);
	fred_speaks("Now, challenge the stragglers!");
	silver.challengeNewcomer("Zombie");
	shiny.challengeNewcomer("Zombie");
	gold.challengeNewcomer("Zombie");
	chromed.challengeNewcomer("Zombie");
	chromed.challengeNewcomer("Zombie");
	chromed.challengeNewcomer("Zombie");
	chromed.challengeNewcomer("Zombie");
	chromed.challengeNewcomer("Zombie");
	fred_speaks("Awesome! Now for MarkIII...");
}

void	ninja_main( void ) {
	ClapTrap clap("BuddyBot");
	FragTrap frag("BoomBot");
	ScavTrap scav("Hinges");
	fred_speaks("Last week was a huge success, but this week I have ninjas...");
	NinjaTrap silver("Wind");
	NinjaTrap shiny(silver);
	NinjaTrap gold("Night");
	shiny = gold;
	NinjaTrap chromed(shiny);
	fred_speaks("Kill the remaining zombies on estate!");
	silver.meleeAttack("Zombie");
	chromed.takeDamage(28);
	shiny.takeDamage(1);
	shiny.rangedAttack("Zombie");
	chromed.takeDamage(88);
	fred_speaks("Oh no GoldII!");
	chromed.beRepaired(45);
	chromed.beRepaired(45);
	fred_speaks("Now, be ninjas!");
	silver.ninjaShoebox(chromed);
	shiny.ninjaShoebox(scav);
	gold.ninjaShoebox(frag);
	chromed.ninjaShoebox(clap);
	chromed.ninjaShoebox(gold);
	fred_speaks("Welp. Nothing is better than a ninja. Time to retire.");
}

int		main( void ) {
	srand(time(NULL)); // Set RNG

	frag_main();
	std::cout << std::endl << std::endl;
	scav_main();
	std::cout << std::endl << std::endl;
	ninja_main();
	return 0;
}
