/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 17:57:41 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/11 19:38:39 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

# include "Form.hpp"
# include <fstream>

class PresidentialPardonForm : public Form {
public:
	PresidentialPardonForm( std::string target );
	PresidentialPardonForm( PresidentialPardonForm const & obj );
	~PresidentialPardonForm( void );
	PresidentialPardonForm & operator=( PresidentialPardonForm const & rhs );

	void executeDo( void ) const;

	std::string const & getTarget( void ) const;

private:
	std::string		_target;

	PresidentialPardonForm( void );
};

#endif
