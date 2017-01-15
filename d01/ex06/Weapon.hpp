/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 16:20:30 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/05 17:16:47 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

# include <iostream>
# include <string>

class Weapon {

public:

	Weapon( std::string type );
	~Weapon( void );

	void setType( std::string type );
	std::string const & getType( void ) const;

private:

	std::string _type;

};

#endif
