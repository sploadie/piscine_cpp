/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 20:47:49 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/08 22:17:10 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
# define AMATERIA_H

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class AMateria {

public:

	AMateria( std::string const & type );
	AMateria( AMateria const & obj );

	virtual ~AMateria( void );

	AMateria & operator=( AMateria const & rhs );

	std::string const & getType( void ) const;
	unsigned int getXP( void ) const;
	virtual AMateria* clone( void ) const = 0;
	virtual void use( ICharacter& target );

protected:
	std::string const _type;
	unsigned int      _xp;

private:
	AMateria( void );

};

#endif
