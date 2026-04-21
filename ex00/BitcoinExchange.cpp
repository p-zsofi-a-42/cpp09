/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:11:30 by zpalotas          #+#    #+#             */
/*   Updated: 2026/04/21 14:18:57 by zpalotas         ###   ########.fr       */
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
	cell_date >> date.tm_year >> dash1 >> date.tm_mon >> dash2 >> date.tm_mday;
	if (cell_date.fail() && !cell_date.eof())
		throw (std::runtime_error("Date misformatted"));
	if (date.tm_year && (dash1 != '-' || dash2 != '-'))
		throw (std::runtime_error("Date misformatted. Separator is not a dash"));
	date.tm_year -= 1900;
	date.tm_mon -= 1;
	//TODO validate year, month day ranges
}

time_t BtcExchng::processDate(std::stringstream &cell_date)
{
	tm date = {};
	my_get_time(cell_date, date);
	time_t date_converted = mktime(&date);
	if (date_converted == -1)
		throw (std::runtime_error("Date misformatted. Not a date"));
	return date_converted;
}

double BtcExchng::processValue(std::stringstream &row_stream)
{
	double		cell_price = 0.0;
	row_stream >> cell_price;
	if (!row_stream.eof())
		throw (std::runtime_error("Unexpected characters after the value"));
	if (row_stream.fail() && !row_stream.eof())
		throw (std::runtime_error("Value is invalid"));
	return cell_price;
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
			double		cell_price = processValue(row_stream);

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
			double			cell_amount = processValue(row_stream);

			transaction_.insert(std::make_pair(date_converted, cell_amount));
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}
