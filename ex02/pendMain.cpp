/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pendMain.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 14:05:14 by zpalotas          #+#    #+#             */
/*   Updated: 2026/04/24 18:46:27 by zpalotas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pendMain.hpp"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~orthodox canonical requirement
template <typename containerInt>
pendMain<containerInt>::pendMain()
{
	containerInt empty;
	pair(empty, empty);
}

template <typename containerInt>
pendMain<containerInt>::pendMain(containerInt pend, containerInt main)
{
	pend_ = pend;
	main_ = main;
}

template <typename containerInt>
pendMain<containerInt>::~pendMain()
{}

template <typename containerInt>
pendMain<containerInt>::pendMain(const pendMain<containerInt> &other)
{
	*this = other;
}

template <typename containerInt>
pendMain<containerInt> & pendMain<containerInt>::operator= (const pendMain &other)
{
	pend_ = other.pend_;
	main_ = other.main_;

	return *this;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~pairing
template <typename containerInt>
pendMain<containerInt> pendMain<containerInt>::pair(containerInt pend, containerInt main)
{
	return (pendMain(pend, main));
}

template <typename containerInt>
pendMain<containerInt> pendMain<containerInt>::pairEmptyPend(containerInt main)
{
	containerInt empty;
	return (pendMain(empty, main));

}

template <typename containerInt>
pendMain<containerInt> pendMain<containerInt>::pairEmptyMain(containerInt pend)
{
	containerInt empty;
	return (pendMain(pend, empty));

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~manipulation
template <typename containerInt>
void pendMain<containerInt>::flip()
{
	containerInt temp = pend_;
	pend_ = main_;
	main_ = temp;
	
	/*🪲*/ if (DEBUG)	{std::cout << "flipped\n";}
}

template <typename containerInt>
void pendMain<containerInt>::divide(int current_pair_size_)
{
	typename containerInt::iterator middle_of_the_list_in_pair = main_.begin();
	std::advance(middle_of_the_list_in_pair, current_pair_size_ / 2);

	pend_.clear();
	while (main_.begin() != middle_of_the_list_in_pair)
	{
		pend_.push_back(*main_.begin());
		main_.pop_front();
	}
}

/** Fuses/inserts the "main" slot of the pair after the "pend" */
template <typename containerInt>
void pendMain<containerInt>::merge()
{
	pend_.insert(pend_.end(), main_.begin(), main_.end());
}

template <typename containerInt>
void pendMain<containerInt>::copyToMain(pendMain &other)
{
	main_ = other.pend_;
}