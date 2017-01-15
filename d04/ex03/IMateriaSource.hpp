/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 19:54:26 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/08 20:02:28 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_H
# define IMATERIASOURCE_H

# include <string>
# include "AMateria.hpp"

class IMateriaSource {
public:
	virtual ~IMateriaSource( void ) {}
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif
