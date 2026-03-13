/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:37:00 by zpalotas          #+#    #+#             */
/*   Updated: 2026/03/13 19:27:16 by zpalotas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::~RPN()
{}

RPN::RPN()
{}

RPN::RPN(std::string input)
{
	std::stringstream input_stream(input);
	//parse if it has spaces
	int	num;
	char c;
	while (input_stream.peek() != -1)
	{
		if (std::isdigit(input_stream.peek()))
		{
			input_stream >> num;
			expr.push(num);
		}
		else
		{
			if (input_stream.peek() == '+')
			{
				//if empty? throw
				int test;
				test = expr.top();
				expr.pop();
				test += expr.top();
				expr.pop();
				expr.push(test);
			}
			else if (input_stream.peek() == '-')
			{
				//if empty? throw
				int minuend;
				int subtrahend;
				subtrahend = expr.top();
				expr.pop();
				minuend = expr.top();
				expr.pop();
				expr.push(minuend - subtrahend);
			}
			else if (input_stream.peek() == '*')
			{
				//if empty? throw
				int test;
				test = expr.top();
				expr.pop();
				test *= expr.top();
				expr.pop();
				expr.push(test);
			}
			else if (input_stream.peek() == '/')
			{
				//if empty? throw
				int divident;
				int divisor;
				divisor = expr.top();
				expr.pop();
				divident = expr.top();
				expr.pop();
				expr.push(divident/divisor);
			}
			else if (!std::isspace(input_stream.peek()))
			{
				std::cout << RED << "Error" <<ENDCLR<< std::endl;
				return;
			}
			input_stream.get(c);
		}
	}
	std::cout << GREEN_B << "result: " << expr.top() <<ENDCLR<< std::endl;
}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN & RPN::operator= (const RPN &other)
{
	if (this == &other)
		return *this;
	this->expr = other.expr;
	return (*this);
}
