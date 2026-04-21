/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 19:24:46 by zpalotas          #+#    #+#             */
/*   Updated: 2026/04/21 14:48:47 by zpalotas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "colors.hpp"

int main(int argc, char* argv[])
{
	//if (argc != 3) //TODO 3 if inout file is implemented
	if (argc != 1) // placeholder for easier running
	{
		std::cerr << LILA_B << "Please provide a file containing the prices and a file containing the transactions!" << ENDCLR << std::endl;
		return 1;
	}

	//BtcExchng test(argv[1], argv[2]);
	(void) argv;
	BtcExchng test("cpp_09/data.csv", "input.txt");
	test.evaluate();
	return 0;
}