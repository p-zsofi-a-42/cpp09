/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:09:00 by zpalotas          #+#    #+#             */
/*   Updated: 2026/04/16 15:40:48 by zpalotas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <climits>
# include <iostream>
# include <sstream>		//stringstream
# include <string>
# include <list>
# include <algorithm>
# include "colors.hpp"
# include "Jacobstahl.hpp"
# include "pendMain.hpp"

# ifndef DEBUG
#  define DEBUG false
# endif

class PmergeMe
{
	private:
		PmergeMe();

		typedef std::list< pendMain > my_pair_list;
		std::list<int> input_sequence;
		my_pair_list result_sequence;
		my_pair_list reserve;

		unsigned int	current_pair_size_;	//needed bc until cpp11 size() can perform unexpectedly(not updated) when using splice()
		int	recursion_lvl_; //pair size = 2^recusion_lvl, how many elements belong to a pair at start 1-1 then 2-2
	
		void checkAndMerge();
		void mergePairs();
		void formFirstPairs();
		void compareAndFlip();
		void part2();
		void insertPend();
		void divide();

		struct compare
		{
			PmergeMe	*obj;
			bool		operator()(pendMain sequenceElement, std::list<int> toCompare);
		} functor;

		bool 	myLess(pendMain sequenceElement, std::list<int> toCompare);

	public:
		PmergeMe(std::stringstream &input);
		~PmergeMe();
		PmergeMe(const PmergeMe &other);

		PmergeMe &operator= (const PmergeMe &other);

		void sort();
		int	comparison_counter_; //counts comparisons //TODO make getter
};
	
void	myPrint(int value);
void	myPrintInt(int value);
void	myPrintPair(pendMain value);
void	myPrintListList(std::list< std::list<int> > listList, std::string id);

#endif

