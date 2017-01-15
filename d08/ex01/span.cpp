/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 15:19:19 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/14 18:56:09 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span( void ) { this->_vector = new std::vector<int>; }

Span::Span( unsigned int max_count ) {
	this->_vector = new std::vector<int>(max_count, 0);
	this->_count = 0;
	this->_do_sort = true;
}

Span::Span( Span const & obj ) {
	this->_vector = new std::vector<int>;
	this->_do_sort = true;
	*this = obj;
}

Span::~Span( void ) { delete this->_vector; }

Span & Span::operator=( Span const & rhs ) {
	this->_count = rhs._count;
	this->_vector = rhs._vector;
	return *this;
}

void Span::_sort( void ) {
	if (this->_do_sort == false) return;
	std::cout << "Sorted!" << std::endl;
	std::sort(this->_vector->begin(), this->_vector->begin()+this->_count);
	this->_do_sort = false;
}

int Span::shortestSpan( void ) {
	if (this->_count < 2) throw Span::SpanTooShort();
	this->_sort();
	int diff;
	int shortest = *(this->_vector->begin()+this->_count-1) - this->_vector->front();
	std::vector<int>::iterator end = this->_vector->begin() + this->_count - 2;
	for (std::vector<int>::iterator start = this->_vector->begin(); start != end; start++) {
		diff = *(start+1) - *start;
		if (diff < shortest) shortest = diff;
	}
	return shortest;
}

int Span::longestSpan( void ) {
	if (this->_count < 2) throw Span::SpanTooShort();
	this->_sort();
	return(*(this->_vector->begin()+this->_count-1) - this->_vector->front());
}

void Span::addNumber( int i ) {
	if (this->_count == this->_vector->size()) throw Span::SpanFull();
	(*this->_vector)[this->_count++] = i;
	this->_do_sort = true;
}

void Span::addRange(std::vector<int>::iterator start, std::vector<int>::iterator end) {
	for (static_cast<void>(start); start != end; start++) {
		this->addNumber(*start);
	}
}

unsigned int Span::getCount( void ) { return this->_count; }

const char* Span::SpanTooShort::what( void ) const _NOEXCEPT { return "span is too short"; }
const char* Span::SpanFull::what( void )     const _NOEXCEPT { return "span is full"; }
