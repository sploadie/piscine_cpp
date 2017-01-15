/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 16:20:30 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/05 16:54:47 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_H
# define HUMAN_H

# include "Brain.hpp"
# include <iostream>
# include <string>

class Human {

public:

	Human( void );
	~Human( void );

	Brain const & getBrain( void ) const;
	std::string identify( void ) const;

private:

	Brain const _brain;

};

#endif
