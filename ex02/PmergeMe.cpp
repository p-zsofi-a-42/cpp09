/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:08:57 by zpalotas          #+#    #+#             */
/*   Updated: 2026/03/27 15:23:00 by zpalotas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(std::stringstream &input)
{
	int element;
	while (!input.eof() && !input.fail())
	{
		input >> element;
		if (!input.fail())
			start_sequence.push_back(element);
	}
	std::for_each(start_sequence.begin(), start_sequence.end(), myPrint);
	std::cout << std::endl;
}

PmergeMe::~PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this == &other)
		return *this;
	
	return (*this);
}

void PmergeMe::FormPairs()
{
	std::list<int>::iterator it;
	std::list<int>::iterator next;
	while (start_sequence.size() >= 2)
	{
		it = start_sequence.begin();
		next = it;
		next++;
		if (next == start_sequence.end())
			break;;
		std::pair<int, int> myPair = std::make_pair(*it, *next);
		if (myPair.first > myPair.second)
		{
			int temp = myPair.first;
			myPair.first = myPair.second;
			myPair.second = temp;
		}
		result_sequence.push_back(myPair);
		start_sequence.pop_front();
		start_sequence.pop_front();
		counter++;
		pair_size++;
	}
	if (start_sequence.size())

	std::for_each(result_sequence.begin(), result_sequence.end(), myPrintPair);

	std::cout << "\n" << counter << std::endl;
}

void	myPrint(int value)
{
	std::cout << "[" << value << "]";
}
void	myPrintPair(std::pair<int, int> value)
{
	std::cout << "[" << value.first << "," << value.second << "]";
}