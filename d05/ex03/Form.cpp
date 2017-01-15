/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 12:36:28 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/11 19:05:18 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Some Forgotten Papers"), _is_signed(false), _sign_grade(150), _exec_grade(150) {}
Form::Form( std::string name, int sign_grade, int exec_grade ) : _name(name), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade) {
	if (_sign_grade<1 || _exec_grade<1) throw Form::GradeTooHighException(); else if (_sign_grade>150 || _exec_grade>150) throw Form::GradeTooLowException();
	std::cout << this->getName() << " Form printed." << std::endl;
}
Form::Form( Form const & obj ) : _name(obj._name) {
	*this = obj;
	std::cout << this->getName() << " Form printed." << std::endl;
}
Form::~Form( void ) {
	std::cout << this->getName() << " Form discarded." << std::endl;
}

Form & Form::operator=( Form const & rhs ) {
	this->_is_signed  = rhs._is_signed;
	this->_sign_grade = rhs._sign_grade;
	this->_exec_grade = rhs._exec_grade;
	return *this;
}

void				Form::beSigned( Bureaucrat const & b ) {
	if (b.getGrade() > this->_sign_grade) throw Form::GradeTooLowException();
	else this->_is_signed = true;
}

void				Form::execute( Bureaucrat const & executor ) const {
	if (this->_is_signed == false)               { throw Form::FormNotSigned();        return; }
	if (executor.getGrade() > this->_exec_grade) { throw Form::GradeTooLowException(); return; }
	this->executeDo();
}

std::string const & Form::getName( void ) const { return this->_name; }
bool                Form::getIsSigned( void )  const { return this->_is_signed; }
int                 Form::getSignGrade( void ) const { return this->_sign_grade; }
int                 Form::getExecGrade( void ) const { return this->_exec_grade; }

std::ostream & operator<<(std::ostream & o, Form const & rhs) {
	if (rhs.getIsSigned()) o << "Signed "; else o << "Unsigned ";
	o << rhs.getName() << " Form; Signature Grade " << rhs.getSignGrade() << "; Execution Grade " << rhs.getExecGrade() << std::endl;
	return o;
}

Form::GradeTooHighException::GradeTooHighException() {}
Form::GradeTooHighException::GradeTooHighException( Form::GradeTooHighException const & obj ) { *this = obj; }
Form::GradeTooHighException::~GradeTooHighException( void ) _NOEXCEPT {}
Form::GradeTooHighException & Form::GradeTooHighException::operator=( Form::GradeTooHighException const & rhs ) { (void)rhs; return *this; }
char const * Form::GradeTooHighException::what( void ) const _NOEXCEPT { return "grade is too high"; }

Form::GradeTooLowException::GradeTooLowException() {}
Form::GradeTooLowException::GradeTooLowException( Form::GradeTooLowException const & obj ) { *this = obj; }
Form::GradeTooLowException::~GradeTooLowException( void ) _NOEXCEPT {}
Form::GradeTooLowException & Form::GradeTooLowException::operator=( Form::GradeTooLowException const & rhs ) { (void)rhs; return *this; }
char const * Form::GradeTooLowException::what( void ) const _NOEXCEPT { return "grade is too low"; }

Form::FormNotSigned::FormNotSigned() {}
Form::FormNotSigned::FormNotSigned( Form::FormNotSigned const & obj ) { *this = obj; }
Form::FormNotSigned::~FormNotSigned( void ) _NOEXCEPT {}
Form::FormNotSigned & Form::FormNotSigned::operator=( Form::FormNotSigned const & rhs ) { (void)rhs; return *this; }
char const * Form::FormNotSigned::what( void ) const _NOEXCEPT { return "form is not signed"; }
