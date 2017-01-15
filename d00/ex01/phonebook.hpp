/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 12:35:53 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/04 18:38:34 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include <string>
# include <sstream>
# include <iomanip>
# include <limits>
# include "Contact.class.hpp"

# define MAX_STREAM std::numeric_limits<std::streamsize>::max()
# define CONTACT_MAX 8

namespace	Input {
	void	get_line(char* input, int input_size);
	void	get_char(char* input);
};

#endif
