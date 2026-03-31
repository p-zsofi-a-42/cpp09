/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:09:00 by zpalotas          #+#    #+#             */
/*   Updated: 2026/03/31 18:29:38 by zpalotas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <climits>
# include <iostream>
# include <sstream>		//stringstream
# include <string>
# include <list>
# include <utility>		//pair type
//# include <stack>
# include <algorithm>
# include "colors.hpp"

# ifndef DEBUG
#  define DEBUG false
# endif

class PmergeMe
{
	private:
		PmergeMe();

		typedef std::list< std::pair< std::list<int>, std::list<int> > > my_pair_list;
		std::list<int> input_sequence;
		my_pair_list start_sequence;
		std::list<int> main;
		std::list<int> pend;
		my_pair_list result_sequence;
		my_pair_list reserve;

		int	recursion_lvl_; //pair size = 2^recusion_lvl, how many elements belong to a pair at start 1-1 then 2-2
	
		void FormPairs(); //TODO priv
		void compare(); //TODO priv
		void resultList(); //TODO priv

	public:
		PmergeMe(std::stringstream &input);
		~PmergeMe();
		PmergeMe(const PmergeMe &other);

		PmergeMe &operator= (const PmergeMe &other);

		void sort();
		int	comparison_counter_; //counts comparisons //TODO make getter
};
	
void	myPrint(int value);
void	myPrintPair(std::pair< std::list<int>, std::list<int> > value);

#endif

