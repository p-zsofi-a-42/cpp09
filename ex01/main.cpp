/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:51:02 by zpalotas          #+#    #+#             */
/*   Updated: 2026/03/13 19:50:12 by zpalotas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include <iostream>
#include "RPN.hpp"

int	main( int argc, char *argv[] )
{
	if (argc != 2)
	{
		std::cout << LILA_B << "Please provide an expression" << ENDCLR << std::endl;
		return 1;
	}

	std::string	input(argv[1]);

	RPN expression(input);
	expression.printResult();
	return 0;
}
