/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 17:57:41 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/11 18:10:13 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

# include "Form.hpp"
# include <fstream>

class ShrubberyCreationForm : public Form {
public:
	ShrubberyCreationForm( std::string target );
	ShrubberyCreationForm( ShrubberyCreationForm const & obj );
	~ShrubberyCreationForm( void );
	ShrubberyCreationForm & operator=( ShrubberyCreationForm const & rhs );

	void executeDo( void ) const;

	std::string const & getTarget( void ) const;

private:
	std::string		_target;

	ShrubberyCreationForm( void );
};

#endif
