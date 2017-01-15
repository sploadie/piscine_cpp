/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 12:36:28 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/11 16:24:52 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>
# include <string>

class Bureaucrat {
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

	Bureaucrat( std::string name, int grade );
	Bureaucrat( Bureaucrat const & obj );
	~Bureaucrat( void );
	Bureaucrat & operator=( Bureaucrat const & rhs );

	std::string const & getName( void ) const;
	int                 getGrade( void ) const;
	void				incrementGrade( void );
	void				decrementGrade( void );

private:
	std::string	const	_name;
	int					_grade;

	Bureaucrat( void );
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif
