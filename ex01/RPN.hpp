/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:32:45 by zpalotas          #+#    #+#             */
/*   Updated: 2026/04/24 18:52:12 by zpalotas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <sstream>		//stringstream
# include <stack>
# include <vector>
# include <algorithm>
# include <climits>
# include "colors.hpp"

class RPN
{
	private:
		RPN();
		std::stack<double, std::vector<double> > expr;

		void addition();
		void substraction();
		void multiplication();
		void division();

	public:
		RPN(std::string input);
		~RPN();
		RPN(const RPN &other);

		RPN &operator= (const RPN &other);

		void	printResult();
};

#endif
