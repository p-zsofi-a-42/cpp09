/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pendMain.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 13:57:10 by zpalotas          #+#    #+#             */
/*   Updated: 2026/04/24 18:48:12 by zpalotas         ###   ########.fr       */
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

template <typename containerInt>
class pendMain
{
	private:

	public:
		pendMain();
		pendMain(containerInt pend, containerInt main);
		~pendMain();
		pendMain(const pendMain &other);
		pendMain &operator= (const pendMain &other);

		containerInt pend_;
		containerInt main_;

		static pendMain pair(containerInt pend, containerInt main);
		static pendMain pairEmptyPend(containerInt main);
		static pendMain pairEmptyMain(containerInt pend);
		
		void flip();
		void divide(int current_pair_size_);
		void merge();
		void copyToMain(pendMain &other);
};

//# include "pendMain.tpp"
#endif