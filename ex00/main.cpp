/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 19:24:46 by zpalotas          #+#    #+#             */
/*   Updated: 2026/04/23 14:53:56 by zpalotas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "colors.hpp"

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << LILA_B << "Please provide a file containing the prices and a file containing the transactions!" << ENDCLR << std::endl;
		return 1;
	}

	BtcExchng test("cpp_09/data.csv", argv[1]);
	return 0;
}