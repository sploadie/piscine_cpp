/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 17:57:41 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/12/19 11:45:18 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) : Form("Presidential Pardon", 25, 5), _target("unspecified") { std::cout << "WRAPPER Presidential Form created." << std::endl; }
PresidentialPardonForm::PresidentialPardonForm( std::string target ) : Form("Presidential Pardon", 25, 5), _target(target) { std::cout << "WRAPPER Presidential Form created." << std::endl; }
PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & obj ) : Form("Presidential Pardon", 25, 5) { *this = obj; }
PresidentialPardonForm::~PresidentialPardonForm( void ) { std::cout << "WRAPPER Presidential Form deleted." << std::endl; }

PresidentialPardonForm & PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs ) {
	this->Form::operator=(rhs);
	this->_target = rhs._target;
	return *this;
}

void	PresidentialPardonForm::executeDo( void ) const {
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
