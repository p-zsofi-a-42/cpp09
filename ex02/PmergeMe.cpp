/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:08:57 by zpalotas          #+#    #+#             */
/*   Updated: 2026/04/07 14:58:59 by zpalotas         ###   ########.fr       */
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
	if (!DEBUG)	{std::cout << "🤡size: " << current_pair_size_ << "\n";}
	part2();
	if (DEBUG)	{std::cout << "🏁 Exited : " << __FUNCTION__ << std::endl;}
}

void PmergeMe::divide()
{
	if (DEBUG)	{std::cout << "START\n";	std::for_each(result_sequence.begin(), result_sequence.end(), myPrintPair); std::cout << std::endl;}
	if (DEBUG)	{std::cout << "⭐ Entered: " << __FUNCTION__ << "	on lvl: " << recursion_lvl_ << std::endl;}
	my_pair_list::iterator it;
	my_pair_list::iterator next;
	

	if (DEBUG)	{std::cout << "START MORE size: " << current_pair_size_ << "\n";	std::for_each(result_sequence.begin(), result_sequence.end(), myPrintPair);	std::cout << std::endl;}
	for (it = result_sequence.begin(); it != result_sequence.end(); it++)
	{
		next = it; 
		next++; 
		if (it->second.front() != -1)
		{
			result_sequence.insert(next, *it); //copying the same element I want to split it.first elements and have them in the begin().first and second. and have og_it.second in the copy.first and second
			it++;;
		}
	}
	if (DEBUG)	{std::cout << "after repeat copy"<< result_sequence.size() << "\n";	std::for_each(result_sequence.begin(), result_sequence.end(), myPrintPair);	std::cout << std::endl;}
	for (it = result_sequence.begin(); it != result_sequence.end(); it++)
	{
		std::list<int>::iterator middle_of_the_list_in_pair;

		middle_of_the_list_in_pair = it->first.begin();
		for (unsigned int i = 0; i != current_pair_size_ / 2; i++)	//my custom std::next or advance
			middle_of_the_list_in_pair++;
		
		it->second.clear();
		it->first.splice(it->second.begin(),	//insert before here
						it->first,				//insert from where
						middle_of_the_list_in_pair,	//element to move
						it->first.end());	//element to move until(exclusive)
		if (DEBUG)	{myPrintPair(*it);}
		
		next = it; 
		next++; 	//next is the copy
		
		if (next != result_sequence.end())
		{
			middle_of_the_list_in_pair = next->second.begin();
			for (unsigned int i = 0; i != current_pair_size_ / 2; i++)	//my custom std::next or advance
				middle_of_the_list_in_pair++;
			
			next->first.clear();
			next->second.splice(next->first.begin(),	//insert before here
							next->second,				//insert from where
							next->second.begin(),	//element to move
							middle_of_the_list_in_pair);	//element to move until(exclusive)
			if (DEBUG)	{myPrintPair(*next); std::cout << std::endl;}

			it++;; //to skip "next"
		}
	}
	current_pair_size_ /= 2;
	if (!reserve.empty() && reserve.begin()->first.size() == current_pair_size_)
	{
		result_sequence.push_back(*(reserve.begin()));
		reserve.pop_front();
			{std::cout << "popped:!!!!!!!!!!!!!1\n ";}
	}
	if (DEBUG)	{std::cout << "🏁 Exited : " << __FUNCTION__ << std::endl;}
}

void PmergeMe::insertPend()
{
	main.splice(main.begin(), pend, pend.begin());
	
	static size_t Jacob_n = 3;
	size_t Jacobsthal_insertion;

	for (std::list< std::list<int> >::iterator it = pend.begin(); it != pend.end(); it++)
	{
		std::cout << "📍pend[";
		std::for_each(it->begin(), it->end(), myPrintInt);
		std::cout << "]\n";
	}
	for (std::list< std::list<int> >::iterator it = main.begin(); it != main.end(); it++)
	{
		std::cout << "📍main[";
		std::for_each(it->begin(), it->end(), myPrintInt);
		std::cout << "]\n";
	}
	if (DEBUG)	{std::cout << "📍 Pend size " << pend.size()<< std::endl;}
	while (!pend.empty())
	{
		Jacobsthal_insertion = Jacobstahl::insertion_n(Jacob_n);
		if (DEBUG)	{std::cout << "📍 Jecob n: " << Jacob_n << " insert: " << Jacobsthal_insertion<< std::endl;}

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
			std::cout << "my value: " << (*it).back() << std::endl;
			std::cout << "place value: " << (std::lower_bound(main.begin(), main.end(),*it, myLess))->back() << std::endl;
			main.splice(std::lower_bound(main.begin(), main.end(),*it, myLess), //TODO add custom comparison to increment counter
						pend,
						it);
			Jacobsthal_insertion--;
		}
		Jacob_n++;
	}
}

void PmergeMe::part2()
{
	if (DEBUG)	{std::cout << "⭐ Entered: " << __FUNCTION__ << "	on lvl: " << recursion_lvl_ << std::endl;}

	if (current_pair_size_ > 1)
	{
		divide();
		std::for_each(result_sequence.begin(), result_sequence.end(), myPrintPair);
		std::for_each(reserve.begin(), reserve.end(), myPrintPair);
		std::cout << std::endl;
	}
	for (my_pair_list::iterator it = result_sequence.begin(); it != result_sequence.end(); it++)
	{
		pend.push_back(it->first);
		if (it->second.front() != -1)
			main.push_back(it->second);
	}
	insertPend();
	for (std::list< std::list<int> >::iterator it = main.begin(); it != main.end(); it++)
	{
		std::cout << "[";
		std::for_each(it->begin(), it->end(), myPrintInt);
		std::cout << ")";
	}

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
/* 
void PmergeMe::compare::operator()(std::list< std::list<int> > main, std::list<int> toCompare)
{
	PmergeMe::myLess(main, toCompare);
} */
bool myLess(std::list<int> sequenceElement, std::list<int> toCompare)
{
	//TODO comparison counter
	if (sequenceElement.back() < toCompare.back())
		return true;
	return false;
}