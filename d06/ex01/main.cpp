/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 12:20:18 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/13 14:56:42 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include <sstream>
# include <cstdlib>
# include <ctime>
# include <ctype.h>

typedef struct MessyData {
    char s1[8];
    int n;
    char s2[8];
}              MessyData;

typedef struct Data {
	std::string s1;
	int n;
	std::string s2;
}              Data;



char random_alphanum( void ) {
	static const char list[] = "1234567890abcdefghijklmnopqrstuvwxyz";
	return list[rand() % 35];
}

void * serialize( void ) {
	MessyData * messy = new MessyData();
	int i;
	for (i=0;i<8;i++) { messy->s1[i] = random_alphanum(); }
	messy->n = rand();
	for (i=0;i<8;i++) { messy->s2[i] = random_alphanum(); }
	return reinterpret_cast<void*>(messy);
}

Data * deserialize( void * raw ) {
	MessyData * messy = reinterpret_cast<MessyData*>(raw);
	Data * clean      = new Data();
	clean->s1 = std::string(messy->s1, 0, 8);
	clean->n  = messy->n;
	clean->s2 = std::string(messy->s2, 0, 8);
	return clean;
}

int	main( void ) {
	srand(time(NULL));

	void * messy_data = serialize();
	char * char_messy_data = reinterpret_cast<char*>(messy_data);
	try {
		std::cout << ":::Serialized Data:::" << std::endl;
		std::cout << "Size:     " << sizeof(MessyData) << std::endl;
		std::cout << "All Bits: " << std::string(char_messy_data, 0, sizeof(MessyData)) << std::endl;
		std::cout << "S1 Bits:  " << std::string(char_messy_data, 0, 8) << std::endl;
		std::cout << "N Bits:   " << *(reinterpret_cast<int*>(char_messy_data+8)) << std::endl;
		std::cout << "S2 Bits:  " << std::string(char_messy_data, 8+sizeof(int), 8) << std::endl;
	} catch( std::exception & e ) { std::cerr << "Some BS exception was thrown. (" << e.what() << ")" << std::endl; }
	Data * clean_data = deserialize(messy_data);
	char * char_clean_data = reinterpret_cast<char*>(clean_data);
	std::string scrubbed_clean_data = "";
	try {
		for (int i=0;i<static_cast<int>(sizeof(Data));i++) {
			if (char_clean_data[i] == '\0')
				scrubbed_clean_data.append(1, '0');
			else
				scrubbed_clean_data.append(1, char_clean_data[i]);
		}
		std::cout << std::endl << "::Unserialized Data::" << std::endl;
		std::cout << "Size:     " << sizeof(Data) << std::endl;
		std::cout << "All Bits: " << scrubbed_clean_data << std::endl;
		std::cout << "S1:       " << clean_data->s1 << std::endl;
		std::cout << "N:        " << clean_data->n  << std::endl;
		std::cout << "S2:       " << clean_data->s2 << std::endl;
	} catch( std::exception & e ) { std::cerr << "Some BS exception was thrown. (" << e.what() << ")" << std::endl; }

	delete reinterpret_cast<MessyData*>(messy_data);
	delete clean_data;
	return 0;
}
