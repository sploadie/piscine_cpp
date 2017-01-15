/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 10:04:58 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/04 18:37:05 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact() {
	return;
}

Contact::~Contact() {
	return;
}

void	Contact::display_index(int index) const {
	char*	strings[] = {
		(char *)this->first_name,
		(char *)this->last_name,
		(char *)this->nickname
	};

	std::cout << "|" << std::setw(10) << index << std::setw(1) << "|";

	std::string index_str;
	for (int i = 0; i < 3; i++) {
		index_str = strings[i];
		if (index_str.size() > 10) { index_str.resize(9); index_str.append("."); }
		std::cout << std::setw(10) << index_str << std::setw(1) << "|";
	}
	std::cout << std::endl;
	return;
}

void	Contact::input_info() {
	std::cout << "First Name: ";
	Input::get_line(this->first_name, IN_SIZE);
	std::cout << "Last Name: ";
	Input::get_line(this->last_name, IN_SIZE);
	std::cout << "Nickname: ";
	Input::get_line(this->nickname, IN_SIZE);
	std::cout << "Login: ";
	Input::get_line(this->login, IN_SIZE);
	std::cout << "Postal Address: ";
	Input::get_line(this->postal_address, IN_SIZE);
	std::cout << "Email Address: ";
	Input::get_line(this->email_address, IN_SIZE);
	std::cout << "Phone Number: ";
	Input::get_line(this->phone_number, IN_SIZE);
	std::cout << "Birthday Date: ";
	Input::get_line(this->birthday_date, IN_SIZE);
	std::cout << "Favorite Meal: ";
	Input::get_line(this->favorite_meal, IN_SIZE);
	std::cout << "Underwear Color: ";
	Input::get_line(this->underwear_color, IN_SIZE);
	std::cout << "Darkest Secret: ";
	Input::get_line(this->darkest_secret, IN_SIZE);
	return;
}

void	Contact::display_info() const {
	std::cout << "First Name: " << this->first_name << std::endl;
	std::cout << "Last Name: " << this->last_name << std::endl;
	std::cout << "Nickname: " << this->nickname << std::endl;
	std::cout << "Login: " << this->login << std::endl;
	std::cout << "Postal Address: " << this->postal_address << std::endl;
	std::cout << "Email Address: " << this->email_address << std::endl;
	std::cout << "Phone Number: " << this->phone_number << std::endl;
	std::cout << "Birthday Date: " << this->birthday_date << std::endl;
	std::cout << "Favorite Meal: " << this->favorite_meal << std::endl;
	std::cout << "Underwear Color: " << this->underwear_color << std::endl;
	std::cout << "Darkest Secret: " << this->darkest_secret << std::endl;
	return;
}
