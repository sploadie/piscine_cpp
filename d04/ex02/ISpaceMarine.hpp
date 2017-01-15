/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISpaceMarine.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 17:10:56 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/08 19:00:34 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISPACEMARINE_H
# define ISPACEMARINE_H

class ISpaceMarine {
public:
	virtual ~ISpaceMarine() {}
	virtual ISpaceMarine* clone() const = 0;
	virtual void battleCry() const = 0;
	virtual void rangedAttack() const = 0;
	virtual void meleeAttack() const = 0;
};

#endif
