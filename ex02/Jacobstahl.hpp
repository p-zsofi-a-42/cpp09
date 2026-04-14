/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Jacobstahl.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 19:19:20 by zpalotas          #+#    #+#             */
/*   Updated: 2026/04/14 19:26:51 by zpalotas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JACOBSTAHL_HPP
# define JACOBSTAHL_HPP

# include <cmath>

class Jacobstahl
{
	private:
		Jacobstahl();
		Jacobstahl(const Jacobstahl &other);
		Jacobstahl &operator= (const Jacobstahl &other);
		
	public:
		static size_t element_n(int n);
		static size_t insertion_n(int n);
		~Jacobstahl();
};

#endif