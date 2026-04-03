/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:08:57 by zpalotas          #+#    #+#             */
/*   Updated: 2026/04/03 14:25:29 by zpalotas         ###   ########.fr       */
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
	if (DEBUG)	{std::cout << "🏁 Exited : " << __FUNCTION__ << std::endl;}
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
	if (DEBUG)	{std::cout << "⭐ Entered: " << __FUNCTION__ << "	on lvl: " << recursion_lvl_ << std::endl;}
	std::list<int>::iterator it;
	std::list<int>::iterator next;
	std::pair<std::list<int>, std::list<int> > myPair;
	for (it = input_sequence.begin(); it != input_sequence.end(); it++)
	{
		next = it;
		next++;
		if (next != input_sequence.end())
		{
			std::list<int> temp_it_list;
			temp_it_list.push_back(*it);
			std::list<int> temp_next_list;
			temp_next_list.push_back(*next);
			myPair = std::make_pair(temp_it_list, temp_next_list);
			result_sequence.push_back(myPair);
			if (DEBUG)	{std::cout <<"forming pairs: "<< std::endl;	myPrintPair(myPair); std::cout << std::endl;}
			it++; //needs to iterate here too not just in the loop to skip the "next"
		}
		else
		{
			std::list<int> temp_it_list;
			temp_it_list.push_back(*it);
			std::list<int> temp_unpaired_list;
			temp_unpaired_list.push_back(-1);
			myPair = std::make_pair(temp_it_list, temp_unpaired_list);
			reserve.push_front(myPair); //after this loop condition will end the loop
		}
	}
	if (DEBUG)	{std::cout << "🏁 Exited : " << __FUNCTION__ << std::endl;}
}

void PmergeMe::compare()
{
	if (DEBUG)	{std::cout << "⭐ Entered: " << __FUNCTION__ << "	on lvl: " << recursion_lvl_ << std::endl;}
	my_pair_list::iterator it;
	my_pair_list::iterator next;
	for (it = result_sequence.begin(); it != result_sequence.end(); it++)
	{
		if (it->first.back() > it->second.back())
		{
			std::list<int> temp = it->first;
			it->first = it->second;
			it->second = temp;
			if (DEBUG)	{std::cout << "flipped\n";}
		}
		if (DEBUG)	{std::cout << "first: " << it->first.back() << " second: " << it->second.back() << std::endl;}
		comparison_counter_++;
	}
	if (DEBUG)	{std::cout << "🏁 Exited : " << __FUNCTION__ << std::endl;}
}

void PmergeMe::resultList()
{
	if (DEBUG)	{std::cout << "⭐ Entered: " << __FUNCTION__ << "	on lvl: " << recursion_lvl_ << std::endl;}
	my_pair_list::iterator it;
	my_pair_list::iterator next;
	
	for (it = result_sequence.begin(); it != result_sequence.end(); it++)
		it->first.insert(it->first.end(), it->second.begin(), it->second.end());

	for (it = result_sequence.begin(); it != result_sequence.end(); it++)
	{
		next = it;
		next++; 
		if (next != result_sequence.end())
		{
			it->second = next->first;
			result_sequence.erase(next);
			//now we have a list of  pairs with doube the size
		}
		else
		{
			std::list<int> temp_unpaired_list;
			temp_unpaired_list.push_back(-1);
			it->second = temp_unpaired_list; //unpaired
			reserve.push_front(*it);
			result_sequence.pop_back();
			break;
		}
	}
	if (DEBUG)	{std::cout << "🏁 Exited : " << __FUNCTION__ << std::endl;}
}

void PmergeMe::sort()
{
	if (DEBUG)	{std::cout << "⭐ Entered: " << __FUNCTION__ << "	on lvl: " << recursion_lvl_ << std::endl;}
	if (recursion_lvl_ == 0)
	{
		FormPairs();
		recursion_lvl_++;
		sort();
	}
	else
	{
		compare();
		std::cout << "result: ";
		std::for_each(result_sequence.begin(), result_sequence.end(), myPrintPair);
		std::for_each(reserve.begin(), reserve.end(), myPrintPair);
		std::cout << std::endl;
		if (result_sequence.size() >= 2)
		{
			resultList();
			recursion_lvl_++;
			sort();
		}
	}

	//part2
	if (DEBUG)	{std::cout << "🏁 Exited : " << __FUNCTION__ << std::endl;}
}


void	myPrint(int value)
{
	std::cout << "[" << value << "]";
}
void	myPrintInt(int value)
{
	std::cout <<value << "➝";
}

void	myPrintPair(std::pair< std::list<int>, std::list<int> > value)
{
	std::cout << "["; 
	std::for_each(value.first.begin(), value.first.end(), myPrintInt);
	std::cout << " , ";
	std::for_each(value.second.begin(), value.second.end(), myPrintInt);
	std::cout << "]";
}