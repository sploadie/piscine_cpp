/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 10:04:58 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/04 14:15:42 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	get_input(char* input, int input_size) {
	std::cin.getline(input, input_size);								// request new input
	std::cout << std::cin.gcount() << " characters read" << std::endl;	// DEBUG
	if (std::cin.fail()) {
		if (std::cin.gcount() == input_size-1) {						// failed because user entered a word longer than 10 chars
		    std::cout << "Input too long, cropping..." << std::endl;
		    if (input[input_size-1] != '\0')							// DEBUG
		    	std::cout << "\\0 was not added!" << std::endl;			// DEBUG
		    input[input_size-1] = '\0';									// make sure to null terminate
		    std::cin.clear();											// clear the failure flags from cin
		    std::cin.ignore(MAX_STREAM, '\n');							// ignore the leftover input from cin
		} else {
			std::cout << "Input error, exiting." << std::endl;			// exit if unknown error
			exit(1);
		}
	}
	return;
}
