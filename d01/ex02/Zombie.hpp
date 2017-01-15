/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 10:38:07 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/05 14:43:39 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>
# include <string>
# include <cstdlib>

class Zombie {

public:

	Zombie( std::string name, std::string type );
	~Zombie( void );

	void announce( void );

	static Zombie* randomChump( std::string type );

private:

	std::string _name;
	std::string _type;

};

#endif
