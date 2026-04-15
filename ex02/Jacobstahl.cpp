/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Jacobstahl.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 19:19:20 by zpalotas          #+#    #+#             */
/*   Updated: 2026/04/15 18:29:49 by zpalotas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Jacobstahl.hpp"

Jacobstahl::Jacobstahl(){}
Jacobstahl::~Jacobstahl(){}
Jacobstahl::Jacobstahl(const Jacobstahl &other)
{
	(void) other;
}
Jacobstahl &Jacobstahl::operator= (const Jacobstahl &other)
{	
	(void) other;
	return *this;
}

size_t Jacobstahl::element_n(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (0);
	if (n == 2)
		return (1);
	return ((std::pow(2, n) - std::pow(-1, n)) / 3);
};

size_t Jacobstahl::insertion_n(int n)
{
	return (Jacobstahl::element_n(n) - Jacobstahl::element_n(n - 1));
};
