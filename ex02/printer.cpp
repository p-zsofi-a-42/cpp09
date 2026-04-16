/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 18:03:24 by zpalotas          #+#    #+#             */
/*   Updated: 2026/04/16 18:09:15 by zpalotas         ###   ########.fr       */
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

void	myPrintListList(std::list< std::list<int> > listList, std::string id)
{
	for (std::list< std::list<int> >::iterator it = listList.begin(); it != listList.end(); it++)
	{
		std::cout << id << "[";
		std::for_each(it->begin(), it->end(), myPrintInt);
		std::cout << "]\n";
	}
}

void	myPrintPair(pendMain value)
{
	std::cout << "["; 
	std::for_each(value.pend_.begin(), value.pend_.end(), myPrintInt);
	std::cout << " , ";
	std::for_each(value.main_.begin(), value.main_.end(), myPrintInt);
	std::cout << "]";
}
