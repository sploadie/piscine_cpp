/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 17:07:25 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/08 19:02:15 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ISquad.hpp"
#include "ISpaceMarine.hpp"
#include "Squad.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"

int main( void ) {
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;
	ISquad* vlc = new Squad;
	vlc->push(bob);
	vlc->push(jim);
	for (int i = 0; i < vlc->getCount(); ++i) {
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	delete vlc;
	return 0;
}