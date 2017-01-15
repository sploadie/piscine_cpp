/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 15:58:34 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/08 16:04:56 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERMUTANT_H
# define SUPERMUTANT_H

# include "Enemy.hpp"

class SuperMutant : public Enemy {

public:

	SuperMutant( void );
	SuperMutant( SuperMutant const & obj );

	~SuperMutant( void );

	SuperMutant & operator=( SuperMutant const & rhs );

	void takeDamage( int damage );

private:

};

#endif
