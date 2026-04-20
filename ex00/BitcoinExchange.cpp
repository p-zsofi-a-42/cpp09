/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:11:30 by zpalotas          #+#    #+#             */
/*   Updated: 2026/04/20 17:19:35 by zpalotas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"

BtcExchng::BtcExchng()
{}

BtcExchng::BtcExchng(const std::string prices, const std::string transactions)
{
	try
	{
		readPrices(prices);
		readTransactions(transactions);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
		return;
	}
	if (DEBUG)
	{
		for (std::map<time_t, double>::iterator it = price_.begin(); it != price_.end(); it++)
			std::cout << "key: " << std::asctime(std::localtime(&it->first)) <<  " -> value: " << it->second << std::endl;
		for (std::multimap<time_t, double>::iterator it = transaction_.begin(); it != transaction_.end(); it++)
			std::cout << "key: " << std::asctime(std::localtime(&it->first)) <<  " | value: " << it->second << std::endl;
	}
}
	
BtcExchng::~BtcExchng()
{}

BtcExchng::BtcExchng(const BtcExchng &other)
{
	*this = other;
}

BtcExchng &BtcExchng::operator=(const BtcExchng &other)
{
	if (this == &other)
		return *this;
	
	return (*this);
}

void static my_get_time(std::stringstream &cell_date, tm &date)
{
	char dash1, dash2;
	cell_date >> date.tm_year ;
	//std::cout << "\ntest Y: " << date.tm_year;
	cell_date >> dash1;
	//std::cout << " test dash: " << dash1;
	cell_date  >> date.tm_mon ;
	//std::cout << " test m: " << date.tm_mon;
	cell_date>> dash2 ;
	//std::cout << " test dash: " << dash2;
	cell_date>> date.tm_mday;
	//std::cout << " test d: " << date.tm_mday;
	date.tm_year -= 1900;
	date.tm_mon -= 1;
}

time_t BtcExchng::processDate(std::stringstream &cell_date)
{
	tm date = {};
	my_get_time(cell_date, date);
	if (cell_date.fail() && !cell_date.eof())
		throw (std::runtime_error("Date misformatted"));
	time_t date_converted = mktime(&date);
	if (date_converted == -1)
		throw (std::runtime_error("Date misformatted. Not a date"));
	return date_converted;
}

void BtcExchng::readPrices(const std::string prices)
{
	std::ifstream file_to_read;
	file_to_read.open(prices.c_str());
	
	//Discarding first, header line
	std::string 	temp;
	std::getline(file_to_read, temp, '\n');
	while (!file_to_read.eof() && !file_to_read.fail())
	{
		std::string		row;
		std::getline(file_to_read, row);
		std::stringstream	row_stream(row);

		std::string			cell;
		getline(row_stream, cell, ',');
		std::stringstream	cell_date(row);
		try
		{
			time_t date_converted =	processDate(cell_date);

			double		cell_price = 0.0;
			row_stream >> cell_price;
			if (!row_stream.eof())
				throw (std::runtime_error("Unexpected characters after the exchange rate"));
			if (row_stream.fail() && !row_stream.eof())
				throw (std::runtime_error("Exchange rate value is invalid"));
			price_.insert(std::make_pair(date_converted, cell_price));
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}

void BtcExchng::readTransactions(const std::string transactions)
{
	std::ifstream file_to_read;
	file_to_read.open(transactions.c_str());
	
	//Discarding first, header line
	std::string 	temp;
	std::getline(file_to_read, temp, '\n');
	while (!file_to_read.eof() && !file_to_read.fail())
	{
		std::string		row;
		std::getline(file_to_read, row);
		std::stringstream	row_stream(row);

		std::string			cell;
		getline(row_stream, cell, '|');
		std::stringstream	cell_date(row);
		try
		{
			time_t date_converted =	processDate(cell_date);

			double			cell_amount = 0.0;
			row_stream >> cell_amount;
			if (!row_stream.eof())
				throw (std::runtime_error("Unexpected characters in transactions line "));
			if (row_stream.fail() && !row_stream.eof())
				throw (std::runtime_error("Transactions amount is invalid"));
			transaction_.insert(std::make_pair(date_converted, cell_amount));
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}
