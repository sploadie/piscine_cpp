/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 10:04:58 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/04 17:51:18 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

namespace	Input {

	void	get_line(char* input, int input_size) {
		std::cin.getline(input, input_size);
		if (std::cin.fail()) {
			if (std::cin.gcount() == input_size-1) {						// failed because user entered a word longer than 10 chars
			    std::cout << "* INPUT TOO LONG, CROPPING... *" << std::endl;
			    std::cin.clear();											// clear the fail flags from cin
			    std::cin.ignore(MAX_STREAM, '\n');							// ignore the leftover input from cin
			} else {
				std::cout << "* INPUT ERROR; EXITING *" << std::endl;			// exit if unknown error
				exit(1);
			}
		}
		for (int i=0; input[i]!='\0'; i++) { if (input[i]=='\t') { input[i] = ' '; } }
		return;
	}

	void	get_char(char* input) {
		*input = std::cin.get();
		if (std::cin.fail()) {
			std::cout << "* CHAR INPUT ERROR; EXITING *" << std::endl;	// exit if unknown error
			exit(1);
		}
		if (*input != '\n') { std::cout << std::endl; }						// Output newline unless newline
		return;
	}

}
