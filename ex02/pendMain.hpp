/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pendMain.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 13:57:10 by zpalotas          #+#    #+#             */
/*   Updated: 2026/04/16 17:45:12 by zpalotas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PENDMAIN_HPP
# define PENDMAIN_HPP

# include <iostream>
# include <list>
# include "colors.hpp"

# ifndef DEBUG
#  define DEBUG false
# endif

class pendMain
{
	private:

	public:
		pendMain();
		pendMain(std::list<int> pend, std::list<int> main);
		~pendMain();
		pendMain(const pendMain &other);
		pendMain &operator= (const pendMain &other);

		std::list<int> pend_;
		std::list<int> main_;

		static pendMain pair(std::list<int> pend, std::list<int> main);
		static pendMain pairEmptyPend(std::list<int> main);
		static pendMain pairEmptyMain(std::list<int> pend);
		
		void flip();
		void divide(int current_pair_size_);
		void merge();
		void copyToMain(pendMain &other);
};

#endif