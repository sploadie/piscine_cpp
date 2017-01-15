/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 10:35:54 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/05 13:06:52 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Pony.hpp"

void	ponyOnTheStack( void ) {
	Pony pony;

	std::cout << pony.legs()					<< std::endl; // Cannot ++ "expression is not assignable"
	std::cout << pony.legsConst()				<< std::endl; // Cannot ++ "expression is not assignable"
	std::cout << ++*(pony.legsPointer())		<< std::endl;
	std::cout << *(pony.legsPointerConst())		<< std::endl; // Cannot ++ "read-only variable is not assignable"
	std::cout << ++pony.legsRef()				<< std::endl;
	std::cout << pony.legsRefConst()			<< std::endl; // Cannot ++ "cannot assign to return value because function 'legsRefConst' returns a const value"

	int const & i = pony.legsRefConst();
	std::cout << ++pony.legsRef() << std::endl;
	// i++; // Can't do!
	std::cout << i << std::endl;

	return;
}

void	ponyOnTheHeap( void ) {
	Pony* pony_ptr = new Pony();
	Pony& pony = *pony_ptr;

	std::cout << pony.legs()					<< std::endl; // Cannot ++ "expression is not assignable"
	std::cout << pony.legsConst()				<< std::endl; // Cannot ++ "expression is not assignable"
	std::cout << ++*(pony.legsPointer())		<< std::endl;
	std::cout << *(pony.legsPointerConst())		<< std::endl; // Cannot ++ "read-only variable is not assignable"
	std::cout << ++pony.legsRef()				<< std::endl;
	std::cout << pony.legsRefConst()			<< std::endl; // Cannot ++ "cannot assign to return value because function 'legsRefConst' returns a const value"

	int const & i = pony.legsRefConst();
	std::cout << ++pony.legsRef() << std::endl;
	// i++; // Can't do!
	std::cout << i << std::endl;

	delete pony_ptr;
	return;
}

int		main( void ) {
	std::cout << "Calling ponyOnTheStack()" << std::endl;
	ponyOnTheStack();
	std::cout << "Control just returned to main()" << std::endl << std::endl;
	std::cout << "Calling ponyOnTheHeap()" << std::endl;
	ponyOnTheHeap();
	std::cout << "Control just returned to main()" << std::endl;
	return 0;
}
