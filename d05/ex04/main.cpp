/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 12:36:43 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/12 11:55:05 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"

int	main( void ) {
	srand(time(NULL));

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

	std::cout << std::endl << "### EX01 NO LONGER OPERATIONAL: FORM IS NOW AN ABSTRACT CLASS ###" << std::endl;

	// try {
	// 	Form heavenly_call("Heavenly Call", 50, 0);
	// } catch(std::exception & e) {
	// 	std::cout << e.what() << std::endl;
	// }
	// try {
	// 	Form grunt("Blank", 999, 50);
	// } catch(std::exception & e) {
	// 	std::cout << e.what() << std::endl;
	// }
	// Form ticket("IOU", 50, 50);
	// std::cout << ticket;
	// pleb.signForm(ticket);
	// std::cout << ticket;
	// boss.signForm(ticket);
	// std::cout << ticket;

	std::cout << std::endl << "### EX02 ###" << std::endl << std::endl;

	ShrubberyCreationForm heavenly_fauna_form("heaven");
	std::cout << heavenly_fauna_form;
	pleb.signForm(heavenly_fauna_form);
	std::cout << heavenly_fauna_form;
	boss.executeForm(heavenly_fauna_form);
	boss.signForm(heavenly_fauna_form);
	std::cout << heavenly_fauna_form;
	pleb.executeForm(heavenly_fauna_form);
	boss.executeForm(heavenly_fauna_form);

	RobotomyRequestForm robo_form("Sonic the Hedgehog");
	std::cout << robo_form;
	pleb.signForm(robo_form);
	std::cout << robo_form;
	boss.executeForm(robo_form);
	boss.signForm(robo_form);
	std::cout << robo_form;
	pleb.executeForm(robo_form);
	boss.executeForm(robo_form);

	PresidentialPardonForm pardon_form("John Egbert");
	std::cout << pardon_form;
	pleb.signForm(pardon_form);
	std::cout << pardon_form;
	boss.executeForm(pardon_form);
	boss.signForm(pardon_form);
	std::cout << pardon_form;
	pleb.executeForm(pardon_form);
	boss.executeForm(pardon_form);

	std::cout << std::endl << "### EX03 ###" << std::endl << std::endl;

	Intern intern;
	Form * newPresidentialPardon = intern.makeForm("Presidential Pardon", "Needy Fred");
	Form * newRobotomyRequest = intern.makeForm("Robotomy Request", "Needy Fred");
	Form * newShrubberyCreation = intern.makeForm("Shrubbery Creation", "Needy Fred");
	Form * newObscur = intern.makeForm("\"Permission to Summon Cthulu\"", "Needy Fred");
	(void)newObscur;
	std::cout << *newPresidentialPardon << *newRobotomyRequest << *newShrubberyCreation;

	delete newPresidentialPardon;
	delete newRobotomyRequest;
	delete newShrubberyCreation;

	std::cout << std::endl << "### EX04 ###" << std::endl << std::endl;

	OfficeBlock small_space;
	try {
		small_space.doBureaucracy("Presidential Pardon", "Unlucky Susie");
	} catch(std::exception & e) {
		std::cout << "Could not do bureaucracy because " << e.what() << std::endl;
	}
	std::cout << "1" << std::endl;
	
	small_space.setIntern(&intern);
	try {
		small_space.doBureaucracy("Presidential Pardon", "Unlucky Susie");
	} catch(std::exception & e) {
		std::cout << "Could not do bureaucracy because " << e.what() << std::endl;
	}
	std::cout << "2" << std::endl;
	
	small_space.setSigner(&boss);
	try {
		small_space.doBureaucracy("Presidential Pardon", "Unlucky Susie");
	} catch(std::exception & e) {
		std::cout << "Could not do bureaucracy because " << e.what() << std::endl;
	}
	std::cout << "3" << std::endl;
	
	small_space.setExecutor(&boss);
	try {
		small_space.doBureaucracy("Presidential Pardon", "Lucky Travis");
	} catch(std::exception & e) {
		std::cout << "Could not do bureaucracy because " << e.what() << std::endl;
	}
	std::cout << "4" << std::endl;
	
	small_space.setSigner(&pleb);
	try {
		small_space.doBureaucracy("Presidential Pardon", "Unlucky Susie");
	} catch(std::exception & e) {
		std::cout << "Could not do bureaucracy because " << e.what() << std::endl;
	}
	std::cout << "5" << std::endl;
	
	small_space.setSigner(&boss);
	small_space.setExecutor(&pleb);
	try {
		small_space.doBureaucracy("Presidential Pardon", "Unlucky Susie");
	} catch(std::exception & e) {
		std::cout << "Could not do bureaucracy because " << e.what() << std::endl;
	}
	std::cout << "6" << std::endl;
	
	return 0;
}
