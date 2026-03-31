/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:08:57 by zpalotas          #+#    #+#             */
/*   Updated: 2026/03/31 15:02:32 by zpalotas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(std::stringstream &input)
{
	recursion_lvl_ = 0;
	comparison_counter_ = 0;
	int element;
	while (!input.eof() && !input.fail())
	{
		input >> element;
		if (!input.fail())
			input_sequence.push_back(element);
	}
	std::for_each(input_sequence.begin(), input_sequence.end(), myPrint);
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

void PmergeMe::FormPairs() // only on first lvl
{
	while (input_sequence.size() >= 2)
	{
		make pair(list.begin, list next)
	}

//	std::for_each(result_sequence.begin(), result_sequence.end(), myPrintPair);
//	std::cout << "\n" << comparison_counter_ << std::endl;
}

void PmergeMe::compare()
{
	while (start seq)
	{
		if (first.back() > second.back())
			flip
		comparison_counter_++;
	}	
}

void PmergeMe::resultList()
{
	while(full list.size >= 2)
		pair,first.merge(second)
	while(full list)
		(if (! next || next.size != 2^recursionlvl))
			reserve.push(next);
		else
			pair.second = next
		pop(next)
	//now we have a list of  pairs with doube the size
}

void PmergeMe::sort()
{
	FormPairs();
	compare()
	resultList();
	if (result_sequence.size > 2)
		sort();
	//part2

}

/* void PmergeMe::FormPairs()
{
	std::list<std::pair<std::list<int>, std::list<int>> >::iterator it;
	std::list<std::pair<std::list<int>, std::list<int>> >::iterator next;
	while (start_sequence.size() >= 2)
	{
		if (recursion_lvl_ = 0)
		{
			//
		}
		else
		{
			std::pair<std::list<int>, std::list<int> > myPair = std::make_pair(*it, *next);

			it = start_sequence.begin();
			next = it;
			next++;
			if (next == start_sequence.end())
				break;;
		}
		
		
		else
		{
			std::list<int> = 
			std::pair< std::list<int>> myPair = std::make_pair(*it, *next);
		}
		if (myPair.first > myPair.second)
		{
			int temp = myPair.first;
			myPair.first = myPair.second;
			myPair.second = temp;
		}
		result_sequence.push_back(myPair);
		start_sequence.pop_front();
		start_sequence.pop_front();
		comparison_counter_++;
		recursion_lvl_++;
	}
	if (start_sequence.size())

	std::for_each(result_sequence.begin(), result_sequence.end(), myPrintPair);

	std::cout << "\n" << comparison_counter_ << std::endl;
} */

void	myPrint(int value)
{
	std::cout << "[" << value << "]";
}
void	myPrintPair(std::pair<int, int> value)
{
	std::cout << "[" << value.first << "," << value.second << "]";
}