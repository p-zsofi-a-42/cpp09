/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:39:34 by zpalotas          #+#    #+#             */
/*   Updated: 2026/03/13 19:49:45 by zpalotas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include <iostream>
#include <sstream>		//stringstream
#include "RPN.hpp"

void	test_1()
{
	std::cout << LILA_B << "Test 1: subject's main" << ENDCLR << std::endl;

	RPN("8 9 * 9 - 9 - 9 - 4 - 1 +").printResult();
	RPN("7 7 * 7 -").printResult();
	RPN("1 2 * 2 / 2 * 2 4 - +").printResult();
	RPN("(1 + 1)").printResult();
}

void	test_2()
{
	std::cout << LILA_B << "Test 2: valid expresssions" << ENDCLR << std::endl;
}

void	test_3()
{
	std::cout << LILA_B << "Test 3: invalid expresssions" << ENDCLR << std::endl;
}

int	main( int argc, char *argv[] )
{
	if (argc != 2)
	{
		std::cout << LILA_B << "Give 1 argument for which test you want to see"
					"\n 1: subject's main"
					//"\n 2: valid expresssions"
					//"\n 3: invalid expresssions"
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
		case 1:	
			test_1();
			break;
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
