/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:37:00 by zpalotas          #+#    #+#             */
/*   Updated: 2026/04/17 17:42:17 by zpalotas         ###   ########.fr       */
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

	try
	{
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
					throw(std::runtime_error("Invalid expression"));
				input_stream.get(c);
			}
		}
		if (expr.size() != 1)
			throw(std::runtime_error("Invalid expression"));
	}
	catch(const std::exception& e)
	{
		//Clearing the whole stack
		while (!expr.empty())
			expr.pop();
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
	if (expr.size() < 2)
		throw(std::runtime_error("Not enough numbers to do the operation"));

	double sum;

	sum = expr.top();
	expr.pop();
	if (__DBL_MAX__ - expr.top() < sum)
		throw(std::runtime_error("Expression is overflowing"));
	sum += expr.top();
	expr.pop();
	expr.push(sum);
}

void RPN::substraction()
{
	if (expr.size() < 2)
		throw(std::runtime_error("Not enough numbers to do the operation"));

	double minuend;		//first number
	double subtrahend;	//second number

	subtrahend = expr.top();
	expr.pop();
	minuend = expr.top();
	expr.pop();
	if (-__DBL_MAX__ + subtrahend > minuend)
		throw(std::runtime_error("Expression is underflowing"));
	expr.push(minuend - subtrahend);
}

void RPN::multiplication()
{
	if (expr.size() < 2)
		throw(std::runtime_error("Not enough numbers to do the operation"));

	double product;

	product = expr.top();
	expr.pop();
	if (__DBL_MAX__ / expr.top() < product)
		throw(std::runtime_error("Expression is overflowing"));
	product *= expr.top();
	expr.pop();
	expr.push(product);
}

void RPN::division()
{
	if (expr.size() < 2)
		throw(std::runtime_error("Not enough numbers to do the operation"));

	double divident;	//first number
	double divisor;		//second number

	divisor = expr.top();
	expr.pop();
	divident = expr.top();
	expr.pop();
	expr.push(divident/divisor);
}

void RPN::printResult()
{
	if (!expr.empty())
		std::cout << "result: " << expr.top() << std::endl;
	else
		std::cout << "Error" << std::endl;
}
