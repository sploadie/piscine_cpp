/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 12:36:28 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/11 19:29:55 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Anon"), _grade(1) {}
Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name), _grade(grade) {
	if (_grade<1) throw Bureaucrat::GradeTooHighException(); else if (_grade>150) throw Bureaucrat::GradeTooLowException();
	std::cout << "Bureaucrat " << this->getName() << " (grade " << this->getGrade() << ") hired." << std::endl;
}
Bureaucrat::Bureaucrat( Bureaucrat const & obj ) : _name(obj._name) {
	*this = obj;
	std::cout << "Bureaucrat " << this->getName() << " (grade " << this->getGrade() << ") hired." << std::endl;
}
Bureaucrat::~Bureaucrat( void ) {
	std::cout << "Bureaucrat " << this->getName() << " (grade " << this->getGrade() << ") fired." << std::endl;
}

Bureaucrat & Bureaucrat::operator=( Bureaucrat const & rhs ) {
	this->_grade = rhs._grade;
	return *this;
}

void				Bureaucrat::signForm( Form & form ) const {
	try { form.beSigned(*this); }
	catch (std::exception & e) {
		std::cout << this->_name << " cannot sign the " << form.getName() << " Form because their " << e.what() << "." << std::endl;
		return;
	}
	std::cout << this->_name << " signs the " << form.getName() << " Form." << std::endl;
}

void				Bureaucrat::executeForm( Form const & form ) const {
	try { form.execute(*this); }
	catch (std::exception & e) {
		std::string error_msg = e.what();
		if (strcmp("Undefined error: 0", strerror(errno))) {
			std::cout << this->_name << " cannot execute the " << form.getName() << " Form because: " << strerror(errno) << "." << std::endl;
		} else {
			std::cout << this->_name << " cannot execute the " << form.getName() << " Form because their " << e.what() << "." << std::endl;
		}
		return;
	}
	std::cout << this->_name << " executed the " << form.getName() << " Form." << std::endl;
}

std::string const & Bureaucrat::getName( void ) const { return this->_name; }
int                 Bureaucrat::getGrade( void ) const { return this->_grade; }
void                Bureaucrat::incrementGrade( void ) { if (_grade == 1)   throw Bureaucrat::GradeTooHighException(); this->_grade--; }
void                Bureaucrat::decrementGrade( void ) { if (_grade == 150) throw Bureaucrat::GradeTooLowException();  this->_grade++; }

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs) {
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return o;
}

Bureaucrat::GradeTooHighException::GradeTooHighException() {}
Bureaucrat::GradeTooHighException::GradeTooHighException( Bureaucrat::GradeTooHighException const & obj ) { *this = obj; }
Bureaucrat::GradeTooHighException::~GradeTooHighException( void ) _NOEXCEPT {}
Bureaucrat::GradeTooHighException & Bureaucrat::GradeTooHighException::operator=( Bureaucrat::GradeTooHighException const & rhs ) { (void)rhs; return *this; }
char const * Bureaucrat::GradeTooHighException::what( void ) const _NOEXCEPT { return "grade is too high"; }

Bureaucrat::GradeTooLowException::GradeTooLowException() {}
Bureaucrat::GradeTooLowException::GradeTooLowException( Bureaucrat::GradeTooLowException const & obj ) { *this = obj; }
Bureaucrat::GradeTooLowException::~GradeTooLowException( void ) _NOEXCEPT {}
Bureaucrat::GradeTooLowException & Bureaucrat::GradeTooLowException::operator=( Bureaucrat::GradeTooLowException const & rhs ) { (void)rhs; return *this; }
char const * Bureaucrat::GradeTooLowException::what( void ) const _NOEXCEPT { return "grade is too low"; }
