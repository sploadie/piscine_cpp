/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 11:19:20 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/12 12:01:12 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock( void ) : _intern(NULL), _signer(NULL), _executor(NULL) {}
OfficeBlock::OfficeBlock( OfficeBlock const & obj ) { *this = obj; }
OfficeBlock::~OfficeBlock( void ) {}
OfficeBlock & OfficeBlock::operator=( OfficeBlock const & rhs ) {
	this->_intern   = rhs._intern;
	this->_signer   = rhs._signer;
	this->_executor = rhs._executor;
	return *this;
}

void OfficeBlock::doBureaucracy(std::string name, std::string target) {
	if (this->_intern   == NULL) { throw OfficeBlock::InternNotSet(); return; }
	if (this->_signer   == NULL) { throw OfficeBlock::SignerNotSet(); return; }
	if (this->_executor == NULL) { throw OfficeBlock::ExecutorNotSet(); return; }
	Form * form = this->_intern->makeForm(name, target);
	if (form == NULL) { throw OfficeBlock::NoSuchForm(); return; }
	try {
		this->_signer->signForm(*form);
		this->_executor->executeForm(*form);
	} catch(std::exception & e) { delete form; throw e; return; }
	delete form;
}

void OfficeBlock::setIntern(Intern * intern) { this->_intern = intern; }

void OfficeBlock::setSigner(Bureaucrat * b) { this->_signer = b; }

void OfficeBlock::setExecutor(Bureaucrat * b) { this->_executor = b; }

OfficeBlock::NoSuchForm::NoSuchForm() {}
OfficeBlock::NoSuchForm::NoSuchForm( OfficeBlock::NoSuchForm const & obj ) { *this = obj; }
OfficeBlock::NoSuchForm::~NoSuchForm( void ) _NOEXCEPT {}
OfficeBlock::NoSuchForm & OfficeBlock::NoSuchForm::operator=( OfficeBlock::NoSuchForm const & rhs ) { (void)rhs; return *this; }
char const * OfficeBlock::NoSuchForm::what( void ) const _NOEXCEPT { return "no such form exists"; }

OfficeBlock::InternNotSet::InternNotSet() {}
OfficeBlock::InternNotSet::InternNotSet( OfficeBlock::InternNotSet const & obj ) { *this = obj; }
OfficeBlock::InternNotSet::~InternNotSet( void ) _NOEXCEPT {}
OfficeBlock::InternNotSet & OfficeBlock::InternNotSet::operator=( OfficeBlock::InternNotSet const & rhs ) { (void)rhs; return *this; }
char const * OfficeBlock::InternNotSet::what( void ) const _NOEXCEPT { return "there is no intern on duty"; }

OfficeBlock::SignerNotSet::SignerNotSet() {}
OfficeBlock::SignerNotSet::SignerNotSet( OfficeBlock::SignerNotSet const & obj ) { *this = obj; }
OfficeBlock::SignerNotSet::~SignerNotSet( void ) _NOEXCEPT {}
OfficeBlock::SignerNotSet & OfficeBlock::SignerNotSet::operator=( OfficeBlock::SignerNotSet const & rhs ) { (void)rhs; return *this; }
char const * OfficeBlock::SignerNotSet::what( void ) const _NOEXCEPT { return "there is no signer on duty"; }

OfficeBlock::ExecutorNotSet::ExecutorNotSet() {}
OfficeBlock::ExecutorNotSet::ExecutorNotSet( OfficeBlock::ExecutorNotSet const & obj ) { *this = obj; }
OfficeBlock::ExecutorNotSet::~ExecutorNotSet( void ) _NOEXCEPT {}
OfficeBlock::ExecutorNotSet & OfficeBlock::ExecutorNotSet::operator=( OfficeBlock::ExecutorNotSet const & rhs ) { (void)rhs; return *this; }
char const * OfficeBlock::ExecutorNotSet::what( void ) const _NOEXCEPT { return "there is no executor on duty"; }
