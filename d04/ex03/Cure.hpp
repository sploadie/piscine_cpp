/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 19:54:06 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/08 22:07:45 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H
# define CURE_H

# include "AMateria.hpp"

class Cure : public AMateria {

public:

	Cure( void );
	Cure( Cure const & obj );

	~Cure( void );

	Cure & operator=( Cure const & rhs );

	AMateria* clone( void ) const;
	void use( ICharacter& target );

private:

};

#endif
