/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:32:45 by zpalotas          #+#    #+#             */
/*   Updated: 2026/03/13 18:29:36 by zpalotas         ###   ########.fr       */
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

	public:
		RPN(std::string input);
		~RPN();
		RPN(const RPN &other);

		RPN &operator= (const RPN &other);
};

#endif
