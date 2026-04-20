/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:11:30 by zpalotas          #+#    #+#             */
/*   Updated: 2026/04/20 13:47:21 by zpalotas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <climits>
# include <iostream>
# include <sstream>		//stringstream
# include <string>
# include <map>
# include <fstream>		// std::ifstream
//# include <stack>
//# include <algorithm>
# include "colors.hpp"

class BtcExchng
{
	private:
		std::map<std::string, double> price_; //TOOO placeholder until date processing is implemented
		std::map<std::string, double> transaction_;
		BtcExchng();
		void readPrices(const std::string prices);
		void readTransactions(const std::string transactions);

	public:
		BtcExchng(const std::string prices, const std::string transactions);
		~BtcExchng();
		BtcExchng(const BtcExchng &other);

		BtcExchng &operator= (const BtcExchng &other);
};

#endif