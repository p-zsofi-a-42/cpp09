/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pendMain.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 14:05:14 by zpalotas          #+#    #+#             */
/*   Updated: 2026/04/16 15:31:39 by zpalotas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pendMain.hpp"

pendMain::pendMain()
{
	std::list<int> empty;
	pair(empty, empty);
}

pendMain::pendMain(std::list<int> pend, std::list<int> main)
{
	pend_ = pend;
	main_ = main;
}

pendMain::~pendMain()
{}

pendMain::pendMain(const pendMain &other)
{
	*this = other;
}

pendMain & pendMain::operator= (const pendMain &other)
{
	pend_ = other.pend_;
	main_ = other.main_;

	return *this;
}

pendMain pendMain::pair(std::list<int> pend, std::list<int> main)
{
	return (pendMain(pend, main));
}

pendMain pendMain::pairEmptyPend(std::list<int> main)
{
	std::list<int> empty;
	return (pendMain(empty, main));

}

pendMain pendMain::pairEmptyMain(std::list<int> pend)
{
	std::list<int> empty;
	return (pendMain(pend, empty));

}