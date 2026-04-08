/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:41:57 by zpalotas          #+#    #+#             */
/*   Updated: 2026/04/08 16:09:44 by zpalotas         ###   ########.fr       */
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
	PmergeMe test(input);
	test.sort();
	//std::cout << "\n" << "compared: " << test.comparison_counter_ << " times" << std::endl;
}