/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISquad.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 17:10:56 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/08 19:00:41 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISQUAD_H
# define ISQUAD_H

# include "ISpaceMarine.hpp"

class ISquad {
public:
	virtual ~ISquad() {}
	virtual int getCount() const = 0;
	virtual ISpaceMarine* getUnit(int) const = 0;
	virtual int push(ISpaceMarine*) = 0;
};

#endif
