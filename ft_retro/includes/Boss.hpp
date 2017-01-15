/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Boss.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 17:21:56 by sraccah           #+#    #+#             */
/*   Updated: 2016/04/10 19:49:46 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		BOSS_HPP
# define	BOSS_HPP

# include "Enemy.hpp"
# include "Character.hpp"

class Boss :  public Enemy{

public:

	Boss( int row, int col, char symbol, int hp, int dmg, int points, int speed );
	Boss( Boss const & obj );

	virtual ~Boss( void );

	Boss & operator=( Boss const & rhs );

	Boss * clone(void) const;

	// void	draw(void) const;
	void	move( int frame, Character * rhs );

	static int  const HP = 1;
	static int  const Dmg = 2;
	static bool const FF = false;
	static int  const Points = 2;

private:
	Boss( void );
	// std::string _symbol;
	int _speed;

};
 #endif
