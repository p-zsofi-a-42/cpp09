/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:09:00 by zpalotas          #+#    #+#             */
/*   Updated: 2026/03/26 15:14:31 by zpalotas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <climits>
# include <iostream>
# include <sstream>		//stringstream
# include <string>
//# include <stack>
//# include <algorithm>
# include "colors.hpp"

class PmergeMe
{
	private:
	
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &other);

		PmergeMe &operator= (const PmergeMe &other);
};

#endif

