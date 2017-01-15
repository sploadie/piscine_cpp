/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 17:57:41 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/11 19:22:11 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

# include "Form.hpp"
# include <cstdlib>
# include <ctime>
# include <fstream>

class RobotomyRequestForm : public Form {
public:
	RobotomyRequestForm( std::string target );
	RobotomyRequestForm( RobotomyRequestForm const & obj );
	~RobotomyRequestForm( void );
	RobotomyRequestForm & operator=( RobotomyRequestForm const & rhs );

	void executeDo( void ) const;

	std::string const & getTarget( void ) const;

private:
	std::string		_target;

	RobotomyRequestForm( void );
};

#endif
