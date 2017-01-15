/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 13:35:56 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/04 18:35:22 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

# include "phonebook.hpp"
# define IN_SIZE 256

class Contact {

public:

	Contact(void);

	~Contact(void);

	void	display_index(int index) const;

	void	input_info(void);

	void	display_info(void) const;

private:

	char	first_name[IN_SIZE];
	char	last_name[IN_SIZE];
	char	nickname[IN_SIZE];
	char	login[IN_SIZE];
	char	postal_address[IN_SIZE];
	char	email_address[IN_SIZE];
	char	phone_number[IN_SIZE];
	char	birthday_date[IN_SIZE];
	char	favorite_meal[IN_SIZE];
	char	underwear_color[IN_SIZE];
	char	darkest_secret[IN_SIZE];

};

#endif
