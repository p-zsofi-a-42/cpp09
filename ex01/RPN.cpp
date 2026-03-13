/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:37:00 by zpalotas          #+#    #+#             */
/*   Updated: 2026/03/13 19:15:53 by zpalotas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::~RPN()
{}

RPN::RPN()
{}

RPN::RPN(std::string input)
{
	//std::reverse(input.begin(), input.end());
	std::stringstream input_stream(input);
	//parse if it has spaces
	int	num;
	char c;
	while (input_stream.peek() != -1)
	{
		std::cout << "looking at: " << input_stream.peek();

		if (std::isdigit(input_stream.peek()))
		{
			std::cout << RED << "num " <<ENDCLR<< std::endl;
			input_stream >> num;
			expr.push(num);
			std::cout << "element: "<<expr.top() << std::endl;
		}
		else if (input_stream.peek() == '+')
		{
			std::cout << RED << "plus" <<ENDCLR<< std::endl;
			//if empty? throw
			int test;
			test = expr.top();
			expr.pop();
			test += expr.top();
			expr.pop();
			expr.push(test);
			input_stream.get(c);
		}
		else if (input_stream.peek() == '-')
		{
			std::cout << RED << "plus" <<ENDCLR<< std::endl;
			//if empty? throw
			int minuend;
			int subtrahend;
			subtrahend = expr.top();
			expr.pop();
			minuend = expr.top();
			expr.pop();
			expr.push(minuend - subtrahend);
			input_stream.get(c);
		}
		else if (input_stream.peek() == '*')
		{
			std::cout << RED << "multi" <<ENDCLR<< std::endl;
			//if empty? throw
			int test;
			test = expr.top();
			expr.pop();
			test *= expr.top();
			expr.pop();
			expr.push(test);
			input_stream.get(c);
		}
		else if (input_stream.peek() == '/')
		{
			std::cout << RED << "div" <<ENDCLR<< std::endl;
			//if empty? throw
			int divident;
			int divisor;
			divisor = expr.top();
			expr.pop();
			divident = expr.top();
			expr.pop();
			expr.push(divident/divisor);
			input_stream.get(c);
		}
		else if (std::isspace(input_stream.peek()))
		{
			std::cout << RED << "space" <<ENDCLR<< std::endl;
			input_stream.get(c);
			//input_stream >> std::noskipws >> c;
		}
		else
		{
			std::cout << RED << "error" <<ENDCLR<< std::endl;
			break;
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
