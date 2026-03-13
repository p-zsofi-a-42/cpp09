/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:37:00 by zpalotas          #+#    #+#             */
/*   Updated: 2026/03/13 17:46:59 by zpalotas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::~RPN()
{}

RPN::RPN()
{}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN & RPN::operator= (const RPN &other)
{
	if (this == &other)
		return *this;
	this->expr = other.expr;
	return (*this);
}
