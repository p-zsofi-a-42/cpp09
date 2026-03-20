/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:32:45 by zpalotas          #+#    #+#             */
/*   Updated: 2026/03/20 14:30:32 by zpalotas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <sstream>		//stringstream
# include <stack>
# include <algorithm>
# include <climits>
# include "colors.hpp"

class RPN
{
	private:
		RPN();
		std::stack<double> expr;

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
