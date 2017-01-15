/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 17:44:22 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/05 19:14:35 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <fstream>

#define BUF_SIZE 4000

int main(int argc, char **argv) {
	std::ifstream old_file;
	std::string contents;
	char buf[BUF_SIZE];
	std::size_t position;
	std::ofstream new_file;

	if (argc < 2) { std::cout << "No file given!" << std::endl; return 1; }
	std::string filename(argv[1]);
	if (argc != 4) { std::cout << "Two strings not given!" << std::endl; return 1; }
	std::string old_str(argv[2]);
	std::string new_str(argv[3]);
	if (old_str.size() == 0 || new_str.size() == 0) { std::cout << "Empty string given!" << std::endl; return 1; }

	old_file.open(filename, std::ifstream::in);
	if (old_file == false) { std::cout << "Could not open " << filename << std::endl; return 1; }

	while (old_file.get(buf, BUF_SIZE, 0)) {
		// std::cout << "Appending!" << std::endl;
		contents.append(buf);
	}
	// std::cout << old_file.fail() << " - " << old_file.eof() << " - " << old_file.bad() << std::endl;
	old_file.close();
	filename.append(".replace");
	new_file.open(filename, std::ofstream::out | std::ofstream::trunc);
	if (new_file == false) { std::cout << "Could not open " << filename << std::endl; return 1; }
	// std::cout << contents << std::endl;
	while ((position = contents.find(old_str)) != std::string::npos) {
		new_file << contents.substr(0, position) << new_str;
		contents.erase(0, position + old_str.size());
	}
	new_file << contents << std::endl;
	new_file.close();
	// while (1) {}
	return 0;
}