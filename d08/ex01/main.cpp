/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 15:18:33 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/14 18:52:02 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

int main( void ) {
	srand(time(NULL));
	std::vector<int> random_numbers(100000, 0);
	std::vector<int>::iterator end = random_numbers.end();
	std::vector<int>::iterator start;
	for (start = random_numbers.begin(); start != end; start++) { *start = rand(); }
	std::cout << random_numbers[0] << ' ' << random_numbers[1] << ' ' << random_numbers[2] << std::endl;
	start = random_numbers.begin();
	Span sp = Span(100001);
	std::cout << "Count: " << sp.getCount() << std::endl;
	try {
		std::cout << sp.shortestSpan() << std::endl;
	} catch( std::exception & e ) { std::cerr << e.what() << std::endl; }
	sp.addNumber(*start);
	std::cout << "Count: " << sp.getCount() << std::endl;
	try {
		std::cout << sp.shortestSpan() << std::endl;
	} catch( std::exception & e ) { std::cerr << e.what() << std::endl; }
	sp.addRange(start+1, start+50000);
	std::cout << "Count: " << sp.getCount() << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	sp.addRange(start+50000, start+100000);
	std::cout << "Count: " << sp.getCount() << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	sp.addNumber(*start);
	std::cout << "Count: " << sp.getCount() << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	try {
		sp.addNumber(42);
	} catch( std::exception & e ) { std::cerr << e.what() << std::endl; }
	std::cout << "Count: " << sp.getCount() << std::endl;
	return 0;
}
