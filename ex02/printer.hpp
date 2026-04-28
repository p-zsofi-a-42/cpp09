/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 18:05:11 by zpalotas          #+#    #+#             */
/*   Updated: 2026/04/28 15:55:15 by zpalotas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTER_HPP
# define PRINTER_HPP

# include <iostream>
# include <list>
# include <deque>
# include <algorithm>
# include "pendMain.hpp"

void	myPrint(int value);
void	myPrintInt(int value);

struct myPrintPair
{
	template <typename containerT>
		void operator()(const pendMain<containerT>& value) const;
};

#include "printer.tpp"

#endif