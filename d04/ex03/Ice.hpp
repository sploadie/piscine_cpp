/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 19:54:06 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/08 22:07:51 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H
# define ICE_H

# include "AMateria.hpp"

class Ice : public AMateria {

public:

	Ice( void );
	Ice( Ice const & obj );

	~Ice( void );

	Ice & operator=( Ice const & rhs );

	AMateria* clone( void ) const;
	void use( ICharacter& target );

private:

};

#endif
