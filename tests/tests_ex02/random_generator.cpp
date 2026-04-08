/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testerGenerator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 21:18:46 by zpalotas          #+#    #+#             */
/*   Updated: 2026/04/07 21:28:16 by zpalotas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <fstream>		// std::ofstream

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Please provide only one argument (n)." << std::endl;
		return (0);
	}
	std::ofstream	file_to_write("test");//	file_to_read.open(filename);
	if(!file_to_write.is_open())
		{	std::cerr 	<< "Error: [ output file ] could not be opened" << std::endl; return 1; }
	
	int n = atoi(argv[1]);
	//printing the limit
	unsigned int sum = 0;
	for (int k = 1; k <= n; k++)
	{
		sum += ceil(log2((3.0/4.0)*k));
	}
	std::cout << "For [" << n << "] number of elements the maximum acceptable comparisons are: "
			<< "\033[1;32m" << sum << std::endl;

	//generating the numbers
	srand(time(NULL));
	int num;
	while (n--)
	{
		num = std::rand(); //NOTE won't go to int max, so limits should be checked manually
	//	while (num > 100) num /= 10;
		file_to_write << num;
		file_to_write << " ";
	}
	file_to_write.close();
	return 0;
}