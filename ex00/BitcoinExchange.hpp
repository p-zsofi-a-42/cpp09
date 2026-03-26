/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:11:30 by zpalotas          #+#    #+#             */
/*   Updated: 2026/03/26 15:14:04 by zpalotas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <climits>
# include <iostream>
# include <sstream>		//stringstream
# include <string>
//# include <stack>
//# include <algorithm>
# include "colors.hpp"

class BtcExchng
{
	private:
	
	public:
		BtcExchng();
		~BtcExchng();
		BtcExchng(const BtcExchng &other);

		BtcExchng &operator= (const BtcExchng &other);
};

#endif