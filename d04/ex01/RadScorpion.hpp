/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 15:58:34 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/08 16:00:10 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADSCORPION_H
# define RADSCORPION_H

# include "Enemy.hpp"

class RadScorpion : public Enemy {

public:

	RadScorpion( void );
	RadScorpion( RadScorpion const & obj );

	~RadScorpion( void );

	RadScorpion & operator=( RadScorpion const & rhs );

private:

};

#endif
