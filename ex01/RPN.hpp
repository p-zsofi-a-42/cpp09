/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:32:45 by zpalotas          #+#    #+#             */
/*   Updated: 2026/03/13 19:52:23 by zpalotas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <sstream>		//stringstream
# include <stack>
# include <algorithm>
# include "colors.hpp"

class RPN
{
	private:
		RPN();
		std::stack<int> expr;

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
