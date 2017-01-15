/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 10:38:07 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/05 15:35:03 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_H
# define ZOMBIEHORDE_H

# include <iostream>
# include "Zombie.hpp"

class ZombieHorde {

public:

	ZombieHorde( int n );
	~ZombieHorde( void );

	void announce();

private:

	Zombie* _zombies;
	int _size;

};

#endif
