/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:09:00 by zpalotas          #+#    #+#             */
/*   Updated: 2026/04/16 18:08:28 by zpalotas         ###   ########.fr       */
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
# include "printer.hpp"

# ifndef DEBUG
#  define DEBUG false
# endif

class PmergeMe
{
	private:
		PmergeMe();

		typedef std::list< pendMain >	my_pair_list;
		std::list<int>	sort_sequence_;
		my_pair_list	result_sequence_;
		my_pair_list	reserve_;

		unsigned int	current_pair_size_;	//needed bc until cpp11 size() can perform unexpectedly(not updated) when using splice()
		int				recursion_lvl_;
		int				comparison_counter_;
	
		//part1
		void checkAndMerge();
		void mergePairs();
		void compareAndFlip();
		void formFirstPairs();
		//part2
		void divide();
		void insertPend();
		void insertUnpaired();
		void part2();

		struct compare
		{
			PmergeMe	*obj;
			bool		operator()(pendMain sequenceElement, std::list<int> toCompare);
		} functor;

		bool 	myLess(pendMain sequenceElement, std::list<int> toCompare);
		void	safeAdvance(my_pair_list::iterator &it, size_t Jacobsthal_insertion);
		void	decremetUntilPendFound(my_pair_list::iterator &it);
		void	incremetUntilPendFound(my_pair_list::iterator &it);

	public:
		PmergeMe(std::stringstream &input);
		~PmergeMe();
		PmergeMe(const PmergeMe &other);

		PmergeMe &operator= (const PmergeMe &other);

		void	sort();
		int						getComparisonCounter() const;
		const std::list<int> &	getSortSequence() const;
};

#endif

