/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 17:07:25 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/08 18:50:42 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSAULTTERMINATOR_H
# define ASSAULTTERMINATOR_H

# include <iostream>
# include <string>
# include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine {

public:

	AssaultTerminator( void );
	AssaultTerminator( AssaultTerminator const & obj );

	~AssaultTerminator( void );

	AssaultTerminator & operator=( AssaultTerminator const & rhs );

	AssaultTerminator * clone( void ) const;
	void battleCry( void ) const;
	void rangedAttack( void ) const;
	void meleeAttack( void ) const;

private:
	static std::string const _FirstCall;
};

#endif
