/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:09:00 by zpalotas          #+#    #+#             */
/*   Updated: 2026/04/07 14:23:38 by zpalotas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <climits>
# include <iostream>
# include <sstream>		//stringstream
# include <string>
# include <list>
# include <cmath>
# include <utility>		//pair type
//# include <stack>
# include <algorithm>
# include "colors.hpp"

# ifndef DEBUG
#  define DEBUG false
# endif

class Jacobstahl
{
	private:
		Jacobstahl();
		Jacobstahl(const Jacobstahl &other)
		{
			(void) other;
		}
		Jacobstahl &operator= (const Jacobstahl &other)
		{	(void) other;
			return *this;};
		
	public:
		static size_t element_n(int n)
		{
			return ((std::pow(2, n) - std::pow(-1, n)) / 3);
		};
		static size_t insertion_n(int n)
		{
			return (Jacobstahl::element_n(n) - Jacobstahl::element_n(n - 1));
		};
		~Jacobstahl(){};
};

class PmergeMe
{
	private:
		PmergeMe();

		typedef std::pair< std::list<int>, std::list<int> > my_pair;
		typedef std::list< my_pair > my_pair_list;
		std::list<int> input_sequence;
		my_pair_list start_sequence;
		std::list< std::list<int> > main;
		std::list< std::list<int> > pend;
		my_pair_list result_sequence;
		my_pair_list reserve;

		unsigned int	current_pair_size_;	//needed bc until cpp11 size() can perform unexpectedly(not updated) when using splice()
		int	recursion_lvl_; //pair size = 2^recusion_lvl, how many elements belong to a pair at start 1-1 then 2-2
	
		void FormPairs();
		void compare();
		void resultList();
		void part2();
		void insertPend();
		void divide();

/* 
		struct compare
		{
			void	operator()(std::list< std::list<int> > main, std::list<int> toCompare);
		} functor; */

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
void	myPrintPair(std::pair< std::list<int>, std::list<int> > value);
bool myLess(std::list<int> sequenceElement, std::list<int> toCompare)
;

#endif

