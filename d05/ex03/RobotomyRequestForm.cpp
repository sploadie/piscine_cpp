/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 17:57:41 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/11 19:34:00 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) : Form("Robotomy Request", 72, 45), _target("unspecified") {}
RobotomyRequestForm::RobotomyRequestForm( std::string target ) : Form("Robotomy Request", 145, 137), _target(target) {}
RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & obj ) : Form("Robotomy Request", 145, 137) { *this = obj; }
RobotomyRequestForm::~RobotomyRequestForm( void ) {}

RobotomyRequestForm & RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs ) {
	this->Form::operator=(rhs);
	this->_target = rhs._target;
	return *this;
}

void	RobotomyRequestForm::executeDo( void ) const {
	std::cout << this->_target << "'s robotomy operation started..." << std::endl;
	system("afplay drilling.wav");
	if (rand() % 2) std::cout << this->_target << " has been robotomized successfully!" << std::endl;
	else std::cout << this->_target << "'s operation ended in failure..." << std::endl;
}
