/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:39:34 by zpalotas          #+#    #+#             */
/*   Updated: 2026/03/13 17:51:11 by zpalotas         ###   ########.fr       */
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
		std::cout << LILA_B << "Give 1 argument for which test you want to see"
					//"\n 1: "
					//"\n 2: "
					//"\n 3: "
					//"\n 4: "
					// "\n 5: " 
					// "\n 6: "
					// "\n 7: " 
					<< ENDCLR << std::endl;
		return 1;
	}

	std::stringstream	input(argv[1]);
	int					testnum;

	input >> testnum;
	if (input.fail() || !input.eof())
	{
		std::cout << "That's not a test case" << std::endl;
		return 1;
	}

	switch (testnum)
	{
		// case 1:	
		// 	test_1();
		// 	break;
 		// case 2:	
		// 	test_2();
		// 	break;
		// case 3:	
		// 	test_3();
		// 	break;
		// case 4:	
		// 	test_4();
		// 	break;
		// case 5:	
		// 	test_5();
		// 	break;
		// case 6:	
		// 	test_6();
		// 	break;
		// case 7:	
		// 	test_7();
		// 	break;
		default:
			std::cout << "That's not a test case" << std::endl;
			return 1;
	}
	return 0;
}
