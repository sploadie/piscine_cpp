/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 13:51:12 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/07 17:39:26 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

void		code_print(std::string s) {
	std::cout << std::setw(20) << s << std::setw(1) << " : ";
}

std::string	truthy(bool val) {
	if (val)
		return "true";
	return "false";
}

// float		stof( std::string const & s ) {
// 	float f;
// 	std::stringstream ss;
// 	ss << s;
// 	ss >> f;
// 	return f;
// }

// int 		main( int argc, char *argv[] ) {
// 	(void)argc;
// 	(void)argv;

// 	std::cout << truthy(std::string("abc") == std::string("abc")) << std::endl;
// 	std::cout << truthy(std::string("abc") == std::string("a")) << std::endl;
// 	try {
// 		std::cout << stof(std::string("d-1.03a")) << std::endl;
// 	} catch (...) {
// 		std::cerr << "Error, not a float..." << std::endl;
// 		return 1;
// 	}
// 	return 0;
// }

size_t	pop_token(std::string & input, std::string & token) {
	size_t		pos;
	if ((pos = input.find_first_not_of(' ')) != 0) {
		input.erase(0, pos);
		if (input.size() == 0) { token = input; return 0; }
	}
	pos = input.find_first_of(' ');
	token = input.substr(0, pos);
	input.erase(0, pos);
	return token.size();
}

void	append_token(std::string & output, std::string const & token) {
	if (output.size() == 0) {
		output = token;
	} else {
		output.append(1, ' ');
		output.append(token);
	}
}

void	push_token(std::string & output, std::string const & token) {
	if (output.size() == 0) {
		output = token;
	} else {
		std::string tmp = output;
		output = token;
		if (output[output.size()-1] != ' ') { output.append(1, ' '); }
		output.append(tmp);
	}
}

int		precedence_not_more(std::string const & lhs, std::string const & rhs) {
	if (rhs[0] == '*' || rhs[0] == '/') { return true; }
	if (lhs[0] == '+' || lhs[0] == '-') { return true; }
	return false;
}

int 		main( int argc, char *argv[] ) {
	if (argc != 2) { std::cerr << "Equation required" << std::endl; return 1; }

	std::string input = argv[1];

	if (input.size() == 0) { std::cerr << "Equation empty" << std::endl; return 1; }

	size_t const input_width = input.size();
	(void)input_width;

	bool		token_is_a_number;
	std::string	token;
	std::string	stack;
	std::string	stack_token;
	std::string	output;

	std::string const operators = "+-*/";

	while (pop_token(input, token) != 0) { // While (input not empty)

		token_is_a_number = true;
		try { stof(token); } catch (std::invalid_argument) { token_is_a_number = false; } // std::cerr << '\'' << token << "' is not a valid float" << std::endl;
		if (token_is_a_number) {
			append_token(output, token);
		} else {
			if (token.size() != 1) { std::cerr << '\'' << token << "' is not a valid token" << std::endl; return 1; }
			// Tokens past this point always size 1

			if (operators.find(token) != std::string::npos) { // If (token is an operator eg +,-,*...)
				while (pop_token(stack, stack_token) != 0 && operators.find(stack_token) != std::string::npos) { // While (stack not empty AND stack top element is an operator)
					// If ((token = left associative AND precedence <= stack top element) OR (token = right associative AND precedence < stack top element))
					// Always left associative for this evaluator
					if (precedence_not_more(token, stack_token)) { // If (precedence <= stack top element)
						append_token(output, stack_token); // Pop stack onto the output queue.
						continue;
					}
					break;
				}
				push_token(stack, stack_token);
				push_token(stack, token);
			}
			else if (token[0] == '(') { // If (token is left bracket '(')
				push_token(stack, token);
			}
			else if (token[0] == ')') { // If (token is right bracket ')')
				while (pop_token(stack, stack_token) != 0 && stack_token[0] != '(') { // While (stack not empty AND stack top element not a left bracket)
					append_token(output, stack_token); // Pop stack onto the output queue.
				}
				// Pop the stack // Already done; stack_token not pushed back into stack
			}
			else { std::cerr << '\'' << token << "' is not a valid token" << std::endl; return 1; }
		}
		std::cout << "Step: \033[32m|\033[0m " << std::setw(10) << token << std::setw(1) << " \033[32m|\033[0m" << std::setw(input_width) << input << std::setw(1) << " \033[32m|||\033[0m " << std::setw(input_width) << stack << std::setw(1) << " \033[32m|||\033[0m " << std::setw(input_width) << output << std::setw(1) << " \033[32m|\033[0m" << std::endl;
	}
	while (pop_token(stack, stack_token) != 0) { // While (stack not empty)
		append_token(output, stack_token); // Pop stack onto the output queue.
	}

	std::cout << "\033[32mReverse Polish Notation:\033[0m " << output << std::endl;

	if (output.size() == 0) { std::cerr << "Equation empty" << std::endl; return 1; }

	size_t const polish_width = output.size();
	input = output;
	token = "";
	int		count = -1;
	int 	i;
	std::stringstream ss;
	float	f;
	Fixed	*fp_stack = new Fixed[input.size()];

	while (pop_token(input, token) != 0) {
		token_is_a_number = true;
		try { f = stof(token); } catch (std::invalid_argument) { token_is_a_number = false; }
		if (token_is_a_number) { fp_stack[++count] = f; continue; }
		if (count < 1) { std::cerr << "Equation invalid, not enough values for operations" << std::endl; return 1; }
		ss.str("");
		ss << fp_stack[count-1] << ' ' << fp_stack[count] << ' ' << token;
		std::cout << "Step: \033[32m|\033[0m " << std::setw(polish_width) << ss.str() << std::setw(1) << " \033[32m|||\033[0m ";
		switch (token[0]) {
			case '+':
				fp_stack[count-1] = fp_stack[count-1] + fp_stack[count];
				break;
			case '-':
				fp_stack[count-1] = fp_stack[count-1] - fp_stack[count];
				break;
			case '*':
				fp_stack[count-1] = fp_stack[count-1] * fp_stack[count];
				break;
			case '/':
				fp_stack[count-1] = fp_stack[count-1] / fp_stack[count];
				break;
			default:
				std::cerr << "Equation invalid, invalid operator '" << token << "' somehow made it into the RPN" << std::endl; return 1;
		}
		count--;
		ss.str("");
		for (i=count;i>=0;i--) { ss << ' ' << fp_stack[i]; }
		ss << input;
		std::cout << std::setw(polish_width/2) << fp_stack[count] << std::setw(1) << " \033[32m|||\033[0m " << std::setw(polish_width) << ss.str() << std::setw(1) << " \033[32m|\033[0m" << std::endl;
	}

	std::cout << "\033[32mCount:\033[0m "    << count       << std::endl;
	std::cout << "\033[32mSolution:\033[0m " << fp_stack[0] << std::endl;

	delete[] fp_stack;
	return 0;
}
