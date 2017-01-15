/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 11:40:37 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/08 16:44:21 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "Enemy.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "Character.hpp"
#include <iostream>

void	weapon_info(AWeapon const & w) {
	std::cout << w.getName() << " | Ap Cost: " << w.getAPCost() << " | Damage: " << w.getDamage() << std::endl;
}

int		main( void ) {
	std::cout << "PlasmaRifle:" << std::endl; // PlasmaRifle
	PlasmaRifle prfl1;
	PlasmaRifle prfl2(prfl1);
	PlasmaRifle prfl3 = prfl2;
	weapon_info(prfl1);
	weapon_info(prfl2);
	weapon_info(prfl3);

	std::cout << std::endl << "PowerFist:" << std::endl; // PowerFist
	PowerFist pfst1;
	PowerFist pfst2(pfst1);
	PowerFist pfst3 = pfst2;
	weapon_info(pfst1);
	weapon_info(pfst2);
	weapon_info(pfst3);

	// Subject Main
	Character* zaz = new Character("zaz");
	std::cout << *zaz;
	Enemy* b = new RadScorpion();
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();
	zaz->equip(pr);
	std::cout << *zaz;
	zaz->equip(pf);
	zaz->attack(b);
	std::cout << *zaz;
	zaz->equip(pr);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;
	// Subject Main End

	std::cout << std::endl << "Main End:" << std::endl;
	return 0;
}
