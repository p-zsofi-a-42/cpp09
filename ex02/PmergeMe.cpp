/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:08:57 by zpalotas          #+#    #+#             */
/*   Updated: 2026/04/15 18:29:30 by zpalotas         ###   ########.fr       */
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
	current_pair_size_ = 1;
	
	std::cout << "Before: ";
	std::for_each(input_sequence.begin(), input_sequence.end(), myPrintInt);
	std::cout << std::endl;
	if (DEBUG)	{std::for_each(input_sequence.begin(), input_sequence.end(), myPrint);	std::cout << std::endl;}
	if (DEBUG)	{std::cerr << "🏁 Exited : " << __FUNCTION__ << std::endl;}
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

void PmergeMe::formFirstPairs() // only on first lvl
{
	if (DEBUG)	{std::cerr << "⭐ Entered: " << __FUNCTION__ << "	on lvl: " << recursion_lvl_ << std::endl;}
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
			std::list<int> temp_empty_list;
			myPair = std::make_pair(temp_it_list, temp_empty_list);
			reserve.push_front(myPair); //after this loop condition will end the loop
		}
	}
	if (DEBUG)	{std::cerr << "🏁 Exited : " << __FUNCTION__ << std::endl;}
}

void PmergeMe::compareAndFlip()
{
	if (DEBUG)	{std::cerr << "⭐ Entered: " << __FUNCTION__ << "	on lvl: " << recursion_lvl_ << std::endl;}
	my_pair_list::iterator it;
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
	if (DEBUG)	{std::cout << "result: ";
				std::for_each(result_sequence.begin(), result_sequence.end(), myPrintPair);
				std::for_each(reserve.begin(), reserve.end(), myPrintPair);
				std::cout << std::endl;
				}
	if (DEBUG)	{std::cerr << "🏁 Exited : " << __FUNCTION__ << std::endl;}
}

void PmergeMe::mergePairs()
{
	if (DEBUG)	{std::cerr << "⭐ Entered: " << __FUNCTION__ << "	on lvl: " << recursion_lvl_ << std::endl;}
	my_pair_list::iterator it;
	my_pair_list::iterator next;
	
	// Merging the current pairs into the "first" slot of the pair
	for (it = result_sequence.begin(); it != result_sequence.end(); it++)
		it->first.insert(it->first.end(), it->second.begin(), it->second.end());

	// Copying every second (now merged) element to the "second" slot of the element before it. Then deleting its node
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
			std::list<int> temp_empty_list;
			it->second = temp_empty_list; //unpaired
			reserve.push_front(*it);
			result_sequence.pop_back();
			break;
		}
	}
	if (DEBUG)	{std::cerr << "🏁 Exited : " << __FUNCTION__ << std::endl;}
}

void PmergeMe::checkAndMerge()
{
	// If there are still more than 2 groups then further recursion is needed to reduce it
	if (result_sequence.size() >= 2)
	{
		// Merge two groups -next to eachother- together into one bigger group
		mergePairs();
		current_pair_size_ *= 2;
		recursion_lvl_++;
		sort();
	}
	// End of part1, groups cannot be merged together more than this
	else
		if (DEBUG)	{std::cout << "👾 END OF PART 1 at lvl: " << recursion_lvl_ << " with group sizes of: " << result_sequence.size()  << std::endl;}
}
void PmergeMe::sort()
{
	if (DEBUG)	{std::cerr << "⭐ Entered: " << __FUNCTION__ << "	on lvl: " << recursion_lvl_ << std::endl;}
	if (recursion_lvl_ == 0)
	{
		formFirstPairs();
		recursion_lvl_++;
		sort(); //recursion
	}
	else
	{
		// Compare the group representatives and flip if needed
		compareAndFlip();
		// Merges the groups then calls recursion if further merging is needed
		checkAndMerge(); 
	}
	// Case: only one element as input arg
	if (result_sequence.empty() && !reserve.empty())
	{
		result_sequence = reserve;
		part2();
	}
	else if (current_pair_size_ != 0)
		part2();

	if (DEBUG)	{std::cerr << "🏁 Exited : " << __FUNCTION__ << std::endl;}
}

void PmergeMe::divide()
{
	if (DEBUG)	{std::cerr << "⭐ Entered: " << __FUNCTION__ << "	on lvl: " << recursion_lvl_ << std::endl;}
	my_pair_list::iterator it;
	
	for (it = result_sequence.begin(); it != result_sequence.end(); it++)
	{
		std::list<int>::iterator middle_of_the_list_in_pair;

		middle_of_the_list_in_pair = it->second.begin();
		std::advance(middle_of_the_list_in_pair, current_pair_size_ / 2);
		
		it->first.clear();
		it->first.splice(it->first.begin(),
							it->second,
							it->second.begin(),
							middle_of_the_list_in_pair);
	}
	current_pair_size_ /= 2;
	if (DEBUG)	{std::cerr << "🏁 Exited : " << __FUNCTION__ << std::endl;}
}

void PmergeMe::insertPend()
{
	if (DEBUG)	{std::cerr << "⭐ Entered: " << __FUNCTION__ << "	on lvl: " << recursion_lvl_ << std::endl;}
	my_pair_list::iterator it = result_sequence.begin();
	std::list<int> emptyList;
	
	// if the reserve has an element that was unpaired and thus didn't move on with the result sequence, but now has the same length element as the members of the current lvl of the result seq. then insert it now
	if (!reserve.empty() && reserve.begin()->first.size() == current_pair_size_)
	{
		result_sequence.splice(result_sequence.end(),
								reserve,
								reserve.begin());
	}
	if (DEBUG) {std::cout << "middle\n";	std::for_each(result_sequence.begin(), result_sequence.end(), myPrintPair); std::cout << std::endl;}

	size_t Jacob_n = 2;
	size_t Jacobsthal_insertion;
	
	my_pair inserted_pend;
	while (it != result_sequence.end())
	{
		Jacobsthal_insertion = Jacobstahl::insertion_n(Jacob_n);
		if (DEBUG)  std::cout << "🔶jacob: " << Jacob_n << " insert: " << Jacobsthal_insertion << "\n";

		// Advance as many elements as the Jacobstahl insertion requires (or ony until the end of the list)
		for (size_t i = 0; i < Jacobsthal_insertion; i++)
		{
			it++;
			if (it == result_sequence.end())
				break;
		}
		if (it != result_sequence.begin())
			it--;

		// Insert all pend elements (stored in it.first) into the result sequence. Inserted elements will have an empty list as .first() 
		while (Jacobsthal_insertion != 0 && !it->first.empty())
		{
			inserted_pend.first = emptyList;
			inserted_pend.second = it->first;
			if (DEBUG)  {std::cout << "🍎inserting: " ; myPrintPair(inserted_pend); std::cout << std::endl;}
			result_sequence.insert(std::lower_bound(result_sequence.begin(), it, it->first, functor),
									inserted_pend);
			// in case this node was originally an unpaired one, we don!t need the empty node
			if (it->second.empty())
			{
				it = result_sequence.end(); //to not invalidate iterator with the pop
				result_sequence.pop_back();
			}
			else
				it->first.clear();
			Jacobsthal_insertion--;
			if (Jacobsthal_insertion)
			{
				it--;
				while(it->first.empty() && it != result_sequence.begin())
					it--;
			}
			if (DEBUG)	{std::cout << "start\n";	std::for_each(result_sequence.begin(), result_sequence.end(), myPrintPair); std::cout << std::endl;}
		}
		while (it != result_sequence.end() && it->first.empty())
			it++;
		Jacob_n++;
	}
	if (DEBUG)	{std::cerr << "🏁 Exited : " << __FUNCTION__ << std::endl;}
}

void PmergeMe::part2()
{
	if (DEBUG)	{std::cerr << "⭐ Entered: " << __FUNCTION__ << "	on lvl: " << recursion_lvl_ << " pair size: "<< current_pair_size_<< std::endl;}
	if (DEBUG)	{std::cout << "start\n";	std::for_each(result_sequence.begin(), result_sequence.end(), myPrintPair); std::cout << std::endl;}

	if (!result_sequence.empty())
		insertPend();

	if (current_pair_size_ > 1)
		divide();
	else
	{
		input_sequence.clear();
		for (my_pair_list::iterator it = result_sequence.begin(); it != result_sequence.end(); it++)
			input_sequence.splice(input_sequence.end(), it->second);
		current_pair_size_ = 0;

		std::cout << "After:  ";
		std::for_each(input_sequence.begin(), input_sequence.end(), myPrintInt);
		std::cout << std::endl;
	}
	if (DEBUG)	{std::cout << "RESULT\n";	std::for_each(result_sequence.begin(), result_sequence.end(), myPrintPair); std::cout << std::endl;}

	if (DEBUG)	{std::cerr << "🏁 Exited : " << __FUNCTION__ << std::endl;}
}

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

void	myPrintPair(std::pair< std::list<int>, std::list<int> > value)
{
	std::cout << "["; 
	std::for_each(value.first.begin(), value.first.end(), myPrintInt);
	std::cout << " , ";
	std::for_each(value.second.begin(), value.second.end(), myPrintInt);
	std::cout << "]";
}

bool PmergeMe::compare::operator()(my_pair sequenceElement, std::list<int> toCompare)
{
	return (obj->myLess(sequenceElement, toCompare));
}

bool PmergeMe::myLess(my_pair sequenceElement, std::list<int> toCompare)
{
	comparison_counter_++;
	if (sequenceElement.second.back() < toCompare.back())
		return true;
	return false;
}