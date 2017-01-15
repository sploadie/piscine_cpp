/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 12:36:28 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/12/19 11:41:51 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Form_H
# define Form_H

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
public:

	class GradeTooHighException : public std::exception {
	public:
		GradeTooHighException( void );
		GradeTooHighException( GradeTooHighException const & obj );
		~GradeTooHighException( void ) _NOEXCEPT;
		GradeTooHighException & operator=( GradeTooHighException const & rhs );
		char const * what( void ) const _NOEXCEPT;
	};

	class GradeTooLowException : public std::exception {
	public:
		GradeTooLowException( void );
		GradeTooLowException( GradeTooLowException const & obj );
		~GradeTooLowException( void ) _NOEXCEPT;
		GradeTooLowException & operator=( GradeTooLowException const & rhs );
		char const * what( void ) const _NOEXCEPT;
	};

	class FormNotSigned : public std::exception {
	public:
		FormNotSigned( void );
		FormNotSigned( FormNotSigned const & obj );
		~FormNotSigned( void ) _NOEXCEPT;
		FormNotSigned & operator=( FormNotSigned const & rhs );
		char const * what( void ) const _NOEXCEPT;
	};

	Form( std::string name, int sign_grade, int exec_grade );
	Form( Form const & obj );
	virtual ~Form( void );
	Form & operator=( Form const & rhs );

	void				beSigned( Bureaucrat const & b );
	void				execute(  Bureaucrat const & executor ) const;
	virtual void		executeDo( void ) const = 0;

	std::string const & getName( void ) const;
	bool                getIsSigned( void ) const;
	int                 getSignGrade( void ) const;
	int                 getExecGrade( void ) const;

private:
	std::string	const	_name;
	bool				_is_signed;
	int					_sign_grade;
	int					_exec_grade;

	Form( void );
};

std::ostream & operator<<(std::ostream & o, Form const & rhs);

#endif
