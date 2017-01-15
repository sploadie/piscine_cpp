/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 12:36:43 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/11 17:45:00 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

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
	Bureaucrat boss("Boss", 1);
	try {
		boss.incrementGrade();
	} catch(std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	Bureaucrat pleb("Plebian", 150);
	try {
		pleb.decrementGrade();
	} catch(std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << boss << pleb;

	std::cout << std::endl << "### EX01 ###" << std::endl << std::endl;

	try {
		Form heavenly_call("Heavenly Call", 50, 0);
	} catch(std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Form grunt("Blank", 999, 50);
	} catch(std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	Form ticket("IOU", 50, 50);
	std::cout << ticket;
	pleb.signForm(ticket);
	std::cout << ticket;
	boss.signForm(ticket);
	std::cout << ticket;
	return 0;
}
