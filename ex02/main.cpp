/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:41:57 by zpalotas          #+#    #+#             */
/*   Updated: 2026/04/24 18:16:32 by zpalotas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
		return 1;
	
	std::stringstream input;

	argv++;
	while (*argv)
	{
		input << *argv << " ";
		argv++;
	}
	std::stringstream input2(input.str());
	try
	{
		PmergeMe<std::list> test(input);

		std::cout << "Before: ";
		std::for_each(test.getSortSequence().begin(), test.getSortSequence().end(), myPrintInt);
		std::cout << std::endl;

		test.sort();

		std::cout << "After:  ";
		std::for_each(test.getSortSequence().begin(), test.getSortSequence().end(), myPrintInt);
		std::cout << std::endl;

		struct timeval exec_time = test.getExecuionTime();

		std::cout << "\ntime with std::list " 
					<< exec_time.tv_sec << " seconds "
					<< exec_time.tv_usec << " microseconds "
					<< std::endl;

		// Sortin wit other container
		PmergeMe<std::deque> dequeTest(input2);
		dequeTest.sort();
		struct timeval deque_exec_time = dequeTest.getExecuionTime();

		std::cout << "time with std::deque "
					<< deque_exec_time.tv_sec << " seconds "
					<< deque_exec_time.tv_usec << " microseconds "
					<< std::endl;

		std::cout << "Comparisons made:\n"
				<< test.getComparisonCounter() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "\nERROR"	<< std::endl;
		std::cerr << e.what()	<< std::endl;
	}
}