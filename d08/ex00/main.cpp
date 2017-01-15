/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 12:28:10 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/14 15:12:52 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>

int	main( void ) {
	int lucky_number = 25;
	int good_array[] = {1,2,lucky_number,3,4};
	int bad_array[]  = {1,2,3,4,5};
	std::list<int>   good_list  ( good_array, good_array+5 );
	std::vector<int> good_vector( good_array, good_array+5 );
	std::list<int>   bad_list   ( bad_array,  bad_array+5  );
	std::vector<int> bad_vector ( bad_array,  bad_array+5  );

	std::cout << easyfind(good_list,   lucky_number) << std::endl;
	std::cout << easyfind(good_vector, lucky_number) << std::endl;
	std::cout << easyfind(bad_list,    lucky_number) << std::endl;
	std::cout << easyfind(bad_vector,  lucky_number) << std::endl;

	return 0;
}
