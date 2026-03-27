/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:09:00 by zpalotas          #+#    #+#             */
/*   Updated: 2026/03/27 15:14:05 by zpalotas         ###   ########.fr       */
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

		std::list<int> start_sequence;
		std::list<int> higher;
		std::list<int> lower;
		std::list<std::pair<int, int>  > result_sequence;
		std::list<int> reserve;

		int	counter; //counts comparisons
		int	pair_size; //or recursion lvl, how many elements belong to a pair at start 1-1 then 2-2
	
	public:
		PmergeMe(std::stringstream &input);
		~PmergeMe();
		PmergeMe(const PmergeMe &other);

		PmergeMe &operator= (const PmergeMe &other);
		void FormPairs();
};
	
void	myPrint(int value);
void	myPrintPair(std::pair<int, int>value);

#endif

