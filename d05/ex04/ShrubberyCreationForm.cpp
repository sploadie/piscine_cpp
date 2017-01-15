/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 17:57:41 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/11 19:34:09 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) : Form("Shrubbery Creation", 145, 137), _target("unspecified") {}
ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : Form("Shrubbery Creation", 145, 137), _target(target) {}
ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & obj ) : Form("Shrubbery Creation", 145, 137) { *this = obj; }
ShrubberyCreationForm::~ShrubberyCreationForm( void ) {}

ShrubberyCreationForm & ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs ) {
	this->Form::operator=(rhs);
	this->_target = rhs._target;
	return *this;
}

void	ShrubberyCreationForm::executeDo( void ) const {
	std::string filename(this->_target);
	filename.append("_shrubbery");
	std::ofstream file;
	file.exceptions(file.exceptions() | std::ifstream::failbit); // | std::ios::badbit);
	file.open(filename, std::ifstream::out | std::ifstream::trunc);
	file << "            ,@@@@@@@,\n    ,,,.   ,@@@@@@/@@,  .oo8888o.\n ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n%&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n%&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n`&%\\ ` /%&'    |.|        \\ '|8'\n    |o|        | |         | |\n    |.|        | |         | |\n __/ ._\\______/  ,\\_______/.  \\__" << std::endl;
	file.close();
}
