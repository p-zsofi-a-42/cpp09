/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expected_generator.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 15:41:13 by zpalotas          #+#    #+#             */
/*   Updated: 2026/04/08 16:48:41 by zpalotas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

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
	int element;
	while (!input.eof() && !input.fail())
	{
		input >> element;
		if (!input.fail())
			expected.push_back(element);
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
}

/*
c++ -Wall -Wextra -Werror -std=c++98 expected_generator.cpp -o expected_generator
c++ -Wall -Wextra -Werror -std=c++98 tests/tests_ex02/expected_generator.cpp -o tests/tests_ex02/expected_generator
*/