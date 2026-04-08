/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expected_generator.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 15:41:13 by zpalotas          #+#    #+#             */
/*   Updated: 2026/04/08 20:16:19 by zpalotas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>

int main(int argc, char **argv)
{
	if (argc != 2)
		return (0);

	//Processing input into stringstream	
	std::stringstream input;
	argv++;
	while (*argv)
	{
		input << *argv << " ";
		argv++;
	}

	//Building list form input
	std::vector<int> expected;
	int element_counter = 0;
	int element;
	while (!input.eof() && !input.fail())
	{
		input >> element;
		if (!input.fail())
		{
			expected.push_back(element);
			element_counter++;
		}
		else if(!input.eof())
		{
			std::cout << "ERROR" << std::endl;
			return 1;
		}
	}
	
	std::cout << "Before: ";
	for (std::vector<int>::iterator it = expected.begin(); it != expected.end(); it++)
		std::cout << *it << "➝";
	std::cout << std::endl;
	
	//Sorting with STL sort
	std::sort(expected.begin(), expected.end());
	
	std::cout << "After:  ";
	for (std::vector<int>::iterator it = expected.begin(); it != expected.end(); it++)
		//std::cout << "[" << *it << "]";
		std::cout << *it << "➝";
	std::cout << std::endl;

//Calculating max limit
	//printing the limit
	unsigned int sum = 0;
	for (int k = 1; k <= element_counter; k++)
	{
		sum += ceil(log2((3.0/4.0)*k));
	}
	std::cout << std::endl 
			<< "Number of elements" 	<< std::endl
			<< element_counter			<< std::endl
			<< "Max limit"				<< std::endl
			<< sum						<< std::endl;
}

/*
c++ -Wall -Wextra -Werror -std=c++98 expected_generator.cpp -o expected_generator
c++ -Wall -Wextra -Werror -std=c++98 tests/tests_ex02/expected_generator.cpp -o tests/tests_ex02/expected_generator
*/