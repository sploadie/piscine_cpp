/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 10:15:19 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/12 10:53:26 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern( void ) {}

Intern::Intern( Intern const & obj ) { *this = obj; }

Intern::~Intern( void ) {}

Intern & Intern::operator=( Intern const & rhs ) { (void)rhs; return *this; }

Form * Intern::makeForm( std::string type, std::string target ) const {
	static const t_formaction tab[] = {
		{"Presidential Pardon", &Intern::_newPresidentialPardonForm},
		{"Robotomy Request",    &Intern::_newRobotomyRequestForm},
		{"Shrubbery Creation",  &Intern::_newShrubberyCreationForm}
	};
	for (int i=0;i<3;i++) {
		if (type == tab[i].name) {
			std::cout << "Intern creates a " << tab[i].name << " Form." << std::endl;
			return (this->*(tab[i].f))(target);
		}
	}
	std::cout << "There is no such thing as a " << type << " Form, says the intern." << std::endl;
	return (NULL);
}

Form* Intern::_newPresidentialPardonForm(std::string target) const {
	return new PresidentialPardonForm(target);
}

Form* Intern::_newRobotomyRequestForm(std::string target) const {
	return new RobotomyRequestForm(target);
}

Form* Intern::_newShrubberyCreationForm(std::string target) const {
	return new ShrubberyCreationForm(target);
}
