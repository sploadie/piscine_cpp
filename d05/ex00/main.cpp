/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 12:36:43 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/11 16:31:41 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int	main( void ) {
	Bureaucrat john("John Hussle", 25);
	Bureaucrat eric("Eric Hussle", 123);
	std::cout << "Cloning happens." << std::endl;
	Bureaucrat eric2(eric);
	std::cout << john << eric << eric2;
	std::cout << "Nepotism happens." << std::endl;
	eric2 = john;
	std::cout << eric2;
	std::cout << "Work happens." << std::endl;
	john.incrementGrade();
	eric2.decrementGrade();
	std::cout << john << eric2;
	try {
		Bureaucrat god("God", 0);
	} catch(std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat lost_guy("Lost Guy", 999);
	} catch(std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat boss("Boss", 1);
		boss.incrementGrade();
	} catch(std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat pleb("Plebian", 150);
		pleb.decrementGrade();
	} catch(std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
