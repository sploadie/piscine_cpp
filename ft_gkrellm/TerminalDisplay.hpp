/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TerminalDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 14:31:06 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/17 12:27:04 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINALDISPLAY_H
# define TERMINALDISPLAY_H

# include "IMonitorDisplay.hpp"
# include <curses.h>

class TerminalDisplay : public IMonitorDisplay {

public:
	TerminalDisplay( void );
	~TerminalDisplay( void );

	int run( void );
	void refresh( void );
	void addModules( std::string );

private:
	TerminalDisplay( TerminalDisplay const & obj );
	TerminalDisplay & operator=( TerminalDisplay const & rhs );
	std::string						_types;
	std::map<char, IMonitorModule*>	_modules;

};

#endif
