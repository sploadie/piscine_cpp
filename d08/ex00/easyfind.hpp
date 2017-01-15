/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 12:28:59 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/14 14:56:27 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
# define EASYFIND_H

# include <iostream>
# include <algorithm>

template <class T> int easyfind(T container, int n) {
	try {
		if (find(container.begin(), container.end(), n) != container.end()) {
			std::cerr << "Found it!" << std::endl;
			return 1;
		}
	} catch(std::exception & e) { std::cerr << e.what() << std::endl; return -1; }
	return 0;
}

#endif
