/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 10:38:07 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/05 14:54:17 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_H
# define ZOMBIEEVENT_H

# include <iostream>
# include "Zombie.hpp"

class ZombieEvent {

public:

	ZombieEvent( void );
	~ZombieEvent( void );

	void setZombieType(std::string type);
	Zombie* newZombie(std::string name);

private:

	std::string _type;

};

#endif
