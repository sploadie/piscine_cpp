/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 12:20:18 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/13 15:07:14 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>

class Base { public: virtual ~Base() {} }; 

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base * generate( void ) {
	int i = rand() % 3;
	if (i == 0) { std::cout << "Generated A!" << std::endl; return new A; }
	if (i == 1) { std::cout << "Generated B!" << std::endl; return new B; }
	std::cout << "Generated C!" << std::endl; return new C;
}

void identify_from_pointer( Base * p ) {
	std::string derived_class_name = "WaitWhat";
	if (dynamic_cast<A*>(p)) derived_class_name = "A";
	if (dynamic_cast<B*>(p)) derived_class_name = "B";
	if (dynamic_cast<C*>(p)) derived_class_name = "C";
	std::cout << "Actually an instance of class " << derived_class_name << std::endl;
}
void identify_from_reference( Base & p ) {
	identify_from_pointer(&p);
	// std::cout << "Actually a reference to instance of class " << << std::endl;
}

int	main( void ) {
	srand(time(NULL));

	Base * unknown;
	for (int i=0;i<10;i++) {
		unknown = generate();
		identify_from_pointer(unknown);
		identify_from_reference(*unknown);
		delete unknown;
	}
}
