/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 18:05:11 by zpalotas          #+#    #+#             */
/*   Updated: 2026/04/28 14:23:45 by zpalotas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTER_HPP
# define PRINTER_HPP

# include <iostream>
# include <list>
# include <algorithm>
# include "pendMain.hpp"

void	myPrint(int value);
void	myPrintInt(int value);
void	myPrintPair(pendMain<std::list<int> >value);
void	myPrintListList(std::list< std::list<int> > listList, std::string id);

#endif