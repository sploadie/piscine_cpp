/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 10:38:07 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/05 11:29:12 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Pony {

public:

	Pony( void );
	~Pony( void );

	int legs();
	int legsConst() const;
	int* legsPointer();
	int const * legsPointerConst() const;
	int& legsRef();
	int const & legsRefConst() const;

private:

	int _legs;

};
