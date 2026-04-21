/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:11:30 by zpalotas          #+#    #+#             */
/*   Updated: 2026/04/21 16:16:59 by zpalotas         ###   ########.fr       */
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
# include <iomanip>		//get_time
# include <locale>		//get_time

//# include <stack>
//# include <algorithm>
# include "colors.hpp"

# ifndef DEBUG
#  define DEBUG false
# endif

class BtcExchng
{
	private:
		std::map<time_t, double> price_;
		std::multimap<time_t, double> transaction_;
		BtcExchng();
		time_t processDate(std::stringstream &cell_date);
		double processValue(std::stringstream &row_stream);
		void readPrices(const std::string prices);
		void readTransactions(const std::string transactions);
		double calculateTransaction(time_t date, double amount);

	public:
		BtcExchng(const std::string prices, const std::string transactions);
		~BtcExchng();
		BtcExchng(const BtcExchng &other);

		BtcExchng &operator= (const BtcExchng &other);
};

#endif