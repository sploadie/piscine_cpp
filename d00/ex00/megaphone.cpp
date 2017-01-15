/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 10:04:58 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/04 11:59:37 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv) {
	int i;
	int count;

	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else {
		for (count=1; count < argc; count++) {
			for (i=0; argv[count][i]!='\0'; i++) { argv[count][i] = toupper(argv[count][i]); }
			std::cout << argv[count];
		}
		std::cout << std::endl;
	}
	return (0);
}
