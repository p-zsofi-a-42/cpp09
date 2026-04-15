/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:41:57 by zpalotas          #+#    #+#             */
/*   Updated: 2026/04/15 20:46:38 by zpalotas         ###   ########.fr       */
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
	try
	{
		PmergeMe test(input);
		test.sort();
		std::cout << "\ntime with std::list " << std::endl;
		std::cout << "time with std:: " << std::endl;
		std::cout << "Comparisons made:\n"
				<< test.comparison_counter_ << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "\nERROR"	<< std::endl;
		std::cerr << e.what()	<< std::endl;
	}
}