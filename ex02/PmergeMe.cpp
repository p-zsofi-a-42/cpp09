/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:08:57 by zpalotas          #+#    #+#             */
/*   Updated: 2026/04/07 16:55:55 by zpalotas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	functor.obj = this;
}

PmergeMe::PmergeMe(std::stringstream &input)
{
	functor.obj = this;
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
	current_pair_size_ = 1;
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
			current_pair_size_ *= 2;
			recursion_lvl_++;
			sort();
		}
		else
			if (DEBUG)	{std::cout << "👾👾👾👾👾👾👾👾👾👾👾👾👾👾👾👾👾👾👾👾👾👾at lvl: " << recursion_lvl_ << "with group sizes of: " << result_sequence.size()  << std::endl;}
	}
	if (current_pair_size_ != 0)
		part2();
	if (DEBUG)	{std::cout << "🏁 Exited : " << __FUNCTION__ << std::endl;}
}

void PmergeMe::divide()
{
	if (DEBUG)	{std::cout << "⭐ Entered: " << __FUNCTION__ << "	on lvl: " << recursion_lvl_ << std::endl;}
	std::list< std::list<int> >::iterator it;
	std::list< std::list<int> >::iterator next;
	
	for (it = main.begin(); it != main.end(); it++)
	{
		std::list<int>::iterator middle_of_the_list_in_pair;

		middle_of_the_list_in_pair = it->begin();
		std::advance(middle_of_the_list_in_pair, current_pair_size_ / 2);
		
		my_pair smaller_pair;
		smaller_pair.second.splice(smaller_pair.second.begin(),	//insert before here
									*it,				//insert from where
									middle_of_the_list_in_pair,	//element to move
									it->end());	//element to move until(exclusive)
		smaller_pair.first = *it;
		result_sequence.push_back(smaller_pair);
	}
	main.clear();
	current_pair_size_ /= 2;
	if (DEBUG)	{std::cout << "🏁 Exited : " << __FUNCTION__ << std::endl;}
}

void PmergeMe::insertPend()
{	
	static size_t Jacob_n = 3;
	size_t Jacobsthal_insertion;

	while (!pend.empty())
	{
		Jacobsthal_insertion = Jacobstahl::insertion_n(Jacob_n);

		while (Jacobsthal_insertion != 0 && !pend.empty())
		{
			std::list< std::list<int> >::iterator it = pend.begin();
			if (pend.size() >= Jacobsthal_insertion)
				std::advance(it, Jacobsthal_insertion-1);
			else
			{
				it = pend.end();
				it--;
			}
			main.splice(std::lower_bound(main.begin(), main.end(),*it, functor),
						pend,
						it);
			Jacobsthal_insertion--;
		}
		Jacob_n++;
	}
}

void PmergeMe::form_pend_at_start()
{
	my_pair_list::iterator it = result_sequence.begin();
	main.push_back(it->first);
	main.push_back(it->second);
	it++;
	while(it != result_sequence.end())
	{
		pend.push_back(it->first);
		main.push_back(it->second);
		it++;
	}
	if (!reserve.empty() && reserve.begin()->first.size() == current_pair_size_)
	{
		pend.push_back(reserve.begin()->first);
		reserve.pop_front();
	}
	if (DEBUG) myPrintListList(main, "👉main");
	if (DEBUG) myPrintListList(main, "👇pend");
}

void PmergeMe::part2()
{
	if (DEBUG)	{std::cout << "⭐ Entered: " << __FUNCTION__ << "	on lvl: " << recursion_lvl_ << " pair size: "<< current_pair_size_<< std::endl;}

	form_pend_at_start();
	if (!pend.empty())
		insertPend();
	
	if (DEBUG) myPrintListList(main, "📍main");
	if (DEBUG) myPrintListList(main, "🔻pend");

	result_sequence.clear();
	if (current_pair_size_ > 1)
		divide();
	else
	{
		input_sequence.clear();
		for (std::list<std::list<int> >::iterator it = main.begin(); it != main.end(); it++)
			input_sequence.splice(input_sequence.end(), *it);
		current_pair_size_ = 0;

		std::cout << "🍀[";
		std::for_each(input_sequence.begin(), input_sequence.end(), myPrintInt);
		std::cout << "]\n";
	}
	std::cout << "RESULT\n";	std::for_each(result_sequence.begin(), result_sequence.end(), myPrintPair); std::cout << std::endl;

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
void	myPrintListList(std::list< std::list<int> > listList, std::string id)
{
	for (std::list< std::list<int> >::iterator it = listList.begin(); it != listList.end(); it++)
	{
		std::cout << id << "[";
		std::for_each(it->begin(), it->end(), myPrintInt);
		std::cout << "]\n";
	}
}

void	myPrintPair(std::pair< std::list<int>, std::list<int> > value)
{
	std::cout << "["; 
	std::for_each(value.first.begin(), value.first.end(), myPrintInt);
	std::cout << " , ";
	std::for_each(value.second.begin(), value.second.end(), myPrintInt);
	std::cout << "]";
}

bool PmergeMe::compare::operator()(std::list<int> sequenceElement, std::list<int> toCompare)
{
	return (obj->myLess(sequenceElement, toCompare));
}

bool PmergeMe::myLess(std::list<int> sequenceElement, std::list<int> toCompare)
{
	comparison_counter_++;
	if (sequenceElement.back() < toCompare.back())
		return true;
	return false;
}