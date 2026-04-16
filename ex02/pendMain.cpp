/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pendMain.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 14:05:14 by zpalotas          #+#    #+#             */
/*   Updated: 2026/04/16 16:53:31 by zpalotas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pendMain.hpp"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~orthodox canonical requirement
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
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~pairing
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

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~manipulation
void pendMain::flip()
{
	std::list<int> temp = pend_;
	pend_ = main_;
	main_ = temp;
	if (DEBUG)	{std::cout << "flipped\n";}
}

void pendMain::divide(int current_pair_size_)
{
	std::list<int>::iterator middle_of_the_list_in_pair = main_.begin();
	std::advance(middle_of_the_list_in_pair, current_pair_size_ / 2);

	pend_.clear();
	pend_.splice(pend_.begin(),
					main_,
					main_.begin(),
					middle_of_the_list_in_pair);
}