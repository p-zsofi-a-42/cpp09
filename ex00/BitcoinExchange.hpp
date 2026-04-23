/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:11:30 by zpalotas          #+#    #+#             */
/*   Updated: 2026/04/23 16:16:34 by zpalotas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <sstream>		//stringstream
# include <string>
# include <map>
# include <fstream>		// std::ifstream
# include <locale>		//get_time

# include "colors.hpp"

# ifndef DEBUG
#  define DEBUG false
# endif

class BtcExchng
{
	private:
		time_t todayDate_;
		std::map<time_t, float> price_;
		std::multimap<time_t, float> transaction_;
		BtcExchng();

		time_t processDate(std::stringstream &cell_date);
		float processValue(std::stringstream &row_stream);
		void readPrices(const std::string prices);
		void readTransactions(const std::string transactions);
		float calculateTransaction(time_t date, float amount);

		void static my_date_print(time_t date);

	public:
		BtcExchng(const std::string prices, const std::string transactions);
		~BtcExchng();
		BtcExchng(const BtcExchng &other);

		BtcExchng &operator= (const BtcExchng &other);
};

#endif