/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 10:04:58 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/04 17:48:33 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int	main(void) {
	int		contact_count = 0;
	Contact	contacts[CONTACT_MAX];
	int		i;
	char	input[IN_SIZE];

	std::cout << "* STARTING UP PHONEBOOK; HELLO *" << std::endl;
	while (1) {
		std::cout << "PB-> ";
		Input::get_line(input, IN_SIZE);
		for(i=0; input[i]!='\0'; i++) { input[i] = toupper(input[i]); }
		// std::cout << "[" << input << "]" << std::endl;		// DEBUG
		if (*input == '\0') {
			continue;
		} else if (strcmp(input, "EXIT") == 0) {
			break;
		} else if (strcmp(input, "SEARCH") == 0) {
			if (contact_count == 0) {
				std::cout << "* NO CONTACTS; CANNOT SEARCH *" << std::endl;
				continue;
			}
			std::cout << "@==========@==========@==========@==========@" << std::endl;
			std::cout << "|INDEX     |FIRST N.  |LAST N.   |NICKNAME  |" << std::endl;
			for(i=0; i < contact_count; i++) { contacts[i].display_index(i+1); }
			std::cout << "@==========@==========@==========@==========@" << std::endl;
			std::cout << "* DISPLAY WHICH CONTACT? *" << std::endl;
			std::cout << "Index: ";
			Input::get_line(input, IN_SIZE); i = *input - 48;
			if (i < 1 || i > contact_count) { continue; }
			contacts[i-1].display_info();
		} else if (strcmp(input, "ADD") == 0) {
			if (contact_count < CONTACT_MAX) {
				contact_count++;
				i = contact_count;
			} else {
				std::cout << "@==========@==========@==========@==========@" << std::endl;
				std::cout << "|INDEX     |FIRST N.  |LAST N.   |NICKNAME  |" << std::endl;
				for(i=0; i < contact_count; i++) { contacts[i].display_index(i+1); }
				std::cout << "@==========@==========@==========@==========@" << std::endl;
				std::cout << "* PHONEBOOK FULL; DELETE A CONTACT? *" << std::endl;
				std::cout << "Index (#/N): ";
				Input::get_line(input, IN_SIZE); i = *input - 48;
				if (i < 1 || i > contact_count) { continue; }
			}
			std::cout << "* INPUT CONTACT INFO *" << std::endl;
			contacts[i-1].input_info();
		} else {
			std::cout << "* INVALID INPUT; IGNORING *" << std::endl;
		}
	}
	std::cout << "* EXITING PHONEBOOK; GOODBYE *" << std::endl;
	// if (argc < 2)
	// 	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	// else {
	// 	for(i=0; argv[1][i]!='\0'; i++) { argv[1][i] = toupper(argv[1][i]); }
	// 	std::cout << argv[1] << std::endl;
	// }
	return (0);
}
