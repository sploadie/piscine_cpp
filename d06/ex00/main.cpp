/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 12:20:18 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/12 15:28:54 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include <sstream>
# include <cstdlib>
# include <ctype.h>

int	main(int argc, char** argv) {
	if (argc != 2) {         std::cerr << "Usage: ./convert VALUE" << std::endl; return 1; }
	std::string input = argv[1];
	if (input.size() == 0) { std::cerr << "Usage: ./convert VALUE" << std::endl; return 1; }
	size_t	count;
	char	character;
	bool	has_decimal_point = false;
	bool	is_float = false;
	std::stringstream ss;
	float	f;
	double	d;
	char	c;
	int		i;
	// (void)f;
	// (void)d;
	// (void)i;
	// (void)c;
	std::stringstream f_ss("");
	std::stringstream d_ss("");
	std::stringstream i_ss("");
	std::stringstream c_ss("");
	// Detective Work
	// if (input.size() == 1) { // d i c
	// 	;
	// } else { // f d i
	// 	if (input.at(input.size()-1) == 'f') { //
	// 		;
	// 	} else {
	// 		;
	// 	}
	// }
	// ss.str(input);
	// ss >> f;
	// ss.clear();
	// ss.str(input);
	// ss >> d;
	// ss.clear();
	// ss.str(input);
	// ss >> i;
	// ss.clear();
	// ss.str(input);
	// ss >> c;
	// ss.clear();
	if (input.size() == 1 && !isdigit(input[0])) {
		std::cout << "Char!" << std::endl;
		c = input[0];
		if  (c > 32 && c < 127)
			c_ss << c;
		else
			c_ss.str("Non displayable");
		i = static_cast<int>(c);
		i_ss << i;
		f_ss << static_cast<float>(c);
		d = static_cast<double>(c);
		d_ss << d;
	} else {
		character = input[0];
		if (isdigit(character) || character == '+' || character == '-') {} else { std::cerr << "Invalid Input" << std::endl; return 1; }
		character = input[input.size()-1];
		if (isdigit(character) || character == 'f') {} else { std::cerr << "Invalid Input" << std::endl; return 1; }
		if (character == 'f') is_float = true;
		for (count=1;count<input.size()-1;count++) {
			character = input[count];
			if (isdigit(character)) { continue; }
			if (character == '.' && has_decimal_point == false) { has_decimal_point = true; continue; }
			std::cerr << "Invalid Input" << std::endl;
			return 1;
		}
		ss.str(input);
		if (has_decimal_point == false) {
			std::cout << "Integer!" << std::endl;
			ss >> i;
			i_ss << i;
			if  (i > 32 && i < 127)
				c_ss << static_cast<char>(i);
			else
				c_ss.str("Non displayable");
			f_ss << static_cast<float>(i);
			d = static_cast<double>(i);
			d_ss << d;
		} else if (is_float == false) {
			std::cout << "Double!" << std::endl;
			ss >> d;
			d_ss << d;
			i = static_cast<int>(d);
			i_ss << i;
			if  (i > 32 && i < 127)
				c_ss << static_cast<char>(d);
			else
				c_ss.str("Non displayable");
			f_ss << static_cast<float>(d);
		} else {
			std::cout << "Float!" << std::endl;
			ss >> f;
			f_ss << f;
			i = static_cast<int>(f);
			i_ss << i;
			if  (i > 32 && i < 127)
				c_ss << static_cast<char>(f);
			else
				c_ss.str("Non displayable");
			d = static_cast<double>(f);
			d_ss << d;
		}
	}
	// Output
	std::cout << "char: " << c_ss.str() << std::endl;
	std::cout << "int: " << i_ss.str() << std::endl;
	if (static_cast<double>(i) == d) {
		std::cout << "float: " << f_ss.str() << ".0f" << std::endl;
		std::cout << "double: " << d_ss.str() << ".0" << std::endl;
	} else {
		std::cout << "float: " << f_ss.str() << 'f' << std::endl;
		std::cout << "double: " << d_ss.str() << std::endl;
	}
	return 0;
}
