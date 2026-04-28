/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 18:03:24 by zpalotas          #+#    #+#             */
/*   Updated: 2026/04/28 15:47:44 by zpalotas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printer.hpp"

void	myPrint(int value)
{
	std::cout << "[" << value << "]";
}

void	myPrintInt(int value)
{
	std::cout <<value << " ➝ ";
}

template <typename containerT>
	void	myPrintPair::operator()(const pendMain<containerT> &value) const
{
	std::cout << "["; 
	std::for_each(value.pend_.begin(), value.pend_.end(), myPrintInt);
	std::cout << " , ";
	std::for_each(value.main_.begin(), value.main_.end(), myPrintInt);
	std::cout << "]";
}
