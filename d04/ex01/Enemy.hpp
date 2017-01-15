/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 15:32:22 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/08 15:58:13 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_H
# define ENEMY_H

# include <iostream>
# include <string>

class Enemy {

public:

	Enemy( int hp, std::string const & type );
	Enemy( Enemy const & obj );

	virtual ~Enemy( void );

	Enemy & operator=( Enemy const & rhs );

	std::string const & getType( void ) const;
	int					getHP( void )   const;

	virtual void takeDamage( int damage );

private:
	Enemy( void );

	int			_hp;
	std::string	_type;
};

#endif
