/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:09:00 by zpalotas          #+#    #+#             */
/*   Updated: 2026/03/31 15:02:57 by zpalotas         ###   ########.fr       */
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

class PmergeMe
{
	private:
		PmergeMe();

		std::list<int> input_sequence;
		std::list<std::pair<std::list<int>, std::list<int>>  > start_sequence;
		std::list<int> main;
		std::list<int> pend;
		std::list<std::pair<std::list<int>, std::list<int>>  > result_sequence;
		std::list<int> reserve;

		int	comparison_counter_; //counts comparisons
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
};
	
void	myPrint(int value);
void	myPrintPair(std::pair<int, int>value);

#endif

