/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:51:02 by zpalotas          #+#    #+#             */
/*   Updated: 2026/03/13 17:55:14 by zpalotas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include <iostream>
#include <sstream>		//stringstream
#include "RPN.hpp"

int	main( int argc, char *argv[] )
{
	if (argc != 2)
	{
		std::cout << LILA_B << "Please provide an expression" << ENDCLR << std::endl;
		return 1;
	}

	std::stringstream	input(argv[1]);

	//RPN expression(input);
//	std::cout << expression.calculation() << std::endl;
	return 0;
}
