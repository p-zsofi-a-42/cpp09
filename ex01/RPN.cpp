/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:37:00 by zpalotas          #+#    #+#             */
/*   Updated: 2026/03/13 19:51:55 by zpalotas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::~RPN()
{}

RPN::RPN()
{}

RPN::RPN(std::string input)
{
	std::stringstream	input_stream(input);
	int					num;
	char				c;

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
				addition();
			else if (input_stream.peek() == '-')
				substraction();
			else if (input_stream.peek() == '*')
				multiplication();
			else if (input_stream.peek() == '/')
				division();
			else if (!std::isspace(input_stream.peek()))
			{
				//clearing the stack
				while (!expr.empty())
					expr.pop();
				break;
			}
			input_stream.get(c);
		}
	}
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

void RPN::addition()
{
	//if empty? throw
	int sum;

	sum = expr.top();
	expr.pop();
	sum += expr.top();
	expr.pop();
	expr.push(sum);
}

void RPN::substraction()
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

void RPN::multiplication()
{
	//if empty? throw
	int product;

	product = expr.top();
	expr.pop();
	product *= expr.top();
	expr.pop();
	expr.push(product);
}

void RPN::division()
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

void RPN::printResult()
{
	if (!expr.empty())
		std::cout << GREEN_B << "result: " << expr.top() << ENDCLR << std::endl;
	else
		std::cout << RED << "Error" << ENDCLR << std::endl;
}
