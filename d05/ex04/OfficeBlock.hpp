/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 11:19:20 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/12 11:39:27 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OFFICEBLOCK_H
# define OFFICEBLOCK_H

# include "Form.hpp"
# include "Intern.hpp"
# include "Bureaucrat.hpp"

class OfficeBlock {

public:

	OfficeBlock( void );
	OfficeBlock( OfficeBlock const & obj );

	~OfficeBlock( void );

	OfficeBlock & operator=( OfficeBlock const & rhs );

	void doBureaucracy(std::string name, std::string target);
	void setIntern(Intern * intern);
	void setSigner(Bureaucrat * b);
	void setExecutor(Bureaucrat * b);


	class NoSuchForm : public std::exception {
	public:
		NoSuchForm( void );
		NoSuchForm( NoSuchForm const & obj );
		~NoSuchForm( void ) _NOEXCEPT;
		NoSuchForm & operator=( NoSuchForm const & rhs );
		char const * what( void ) const _NOEXCEPT;
	};
	class InternNotSet : public std::exception {
	public:
		InternNotSet( void );
		InternNotSet( InternNotSet const & obj );
		~InternNotSet( void ) _NOEXCEPT;
		InternNotSet & operator=( InternNotSet const & rhs );
		char const * what( void ) const _NOEXCEPT;
	};
	class SignerNotSet : public std::exception {
	public:
		SignerNotSet( void );
		SignerNotSet( SignerNotSet const & obj );
		~SignerNotSet( void ) _NOEXCEPT;
		SignerNotSet & operator=( SignerNotSet const & rhs );
		char const * what( void ) const _NOEXCEPT;
	};
	class ExecutorNotSet : public std::exception {
	public:
		ExecutorNotSet( void );
		ExecutorNotSet( ExecutorNotSet const & obj );
		~ExecutorNotSet( void ) _NOEXCEPT;
		ExecutorNotSet & operator=( ExecutorNotSet const & rhs );
		char const * what( void ) const _NOEXCEPT;
	};

private:
	Intern * _intern;
	Bureaucrat * _signer;
	Bureaucrat * _executor;
};

#endif
