/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 10:15:19 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/12 10:54:59 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H

# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {

public:

	Intern( void );
	Intern( Intern const & obj );

	~Intern( void );

	Intern & operator=( Intern const & rhs );

	Form * makeForm( std::string type, std::string target ) const;

private:
	typedef struct s_formaction {
        std::string name;
        Form* (Intern::*f)(std::string) const;
    }              t_formaction;

	Form* _newPresidentialPardonForm(std::string) const;
	Form* _newRobotomyRequestForm(std::string) const;
	Form* _newShrubberyCreationForm(std::string) const;
};

#endif
