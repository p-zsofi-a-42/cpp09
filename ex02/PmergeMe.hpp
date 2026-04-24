/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:09:00 by zpalotas          #+#    #+#             */
/*   Updated: 2026/04/24 18:48:03 by zpalotas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <climits>
# include <iostream>
# include <sstream>		//stringstream
# include <string>
# include <list>
# include <deque>
# include <algorithm>
# include <fstream>		//EOF
# include "colors.hpp"
# include "Jacobstahl.hpp"
# include "pendMain.hpp"
# include "printer.hpp"
# include <sys/time.h>		//gettimeofday

# ifndef DEBUG
#  define DEBUG false
# endif

template <template <typename, typename> class containerT>
class PmergeMe
{
	private:
		PmergeMe();

		typedef containerT<int, std::allocator<int> > containerInt;
		typedef containerT< pendMain<containerInt>, std::allocator<pendMain<containerInt> > > my_pair_list;
		
		containerInt	sort_sequence_;
		my_pair_list	result_sequence_;
		my_pair_list	reserve_;

		unsigned int	current_pair_size_;	//needed bc until cpp11 size() can perform unexpectedly(not updated) when using splice()
		int				recursion_lvl_;
		int				comparison_counter_;
		struct timeval	execution_start_;
	
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
			bool		operator()(pendMain<containerInt> sequenceElement, containerInt toCompare);
		} functor;

		bool 	myLess(pendMain<containerInt> sequenceElement, containerInt toCompare);
		void	safeAdvance(typename my_pair_list::iterator &it, size_t Jacobsthal_insertion);
		void	decremetUntilPendFound(typename my_pair_list::iterator &it);
		void	incremetUntilPendFound(typename my_pair_list::iterator &it);

	public:
		PmergeMe(std::stringstream &input);
		~PmergeMe();
		PmergeMe(const PmergeMe &other);

		PmergeMe &operator= (const PmergeMe &other);

		void	sort();
		int						getComparisonCounter() const;
		const containerInt &	getSortSequence() const;
		struct timeval			getExecuionTime() const;
};

//# include "PmergeMe.tpp"
#endif

