/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 20:07:17 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/14 20:15:56 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Token.hpp"

bool Token::isNum( void ) const { return false; }

bool Token::isOp( void )  const { return false; }

bool Token::isPar( void ) const { return false; }
