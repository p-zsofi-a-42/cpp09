/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:11:30 by zpalotas          #+#    #+#             */
/*   Updated: 2026/04/21 16:45:48 by zpalotas         ###   ########.fr       */
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

void static my_get_time(std::stringstream &cell_date, std::tm &date)
{
	char dash1, dash2;
	cell_date >> date.tm_year >> dash1 >> date.tm_mon >> dash2 >> date.tm_mday;
	if (cell_date.fail())
		throw (std::runtime_error("Date misformatted"));
	if (date.tm_year && (dash1 != '-' || dash2 != '-'))
		throw (std::runtime_error("Date misformatted. Separator is not a dash"));
	date.tm_year -= 1900;
	date.tm_mon -= 1;
	//TODO validate year, month day ranges
}

time_t BtcExchng::processDate(std::stringstream &cell_date)
{
	std::tm date = {};
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
		throw (std::runtime_error("Unexpected characters near the value"));
	if (row_stream.fail() && !row_stream.eof())
		throw (std::runtime_error("Value is invalid"));
	if (cell_price < 0)
		throw (std::runtime_error("Value is negative"));
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
			if (cell_amount > 1000)
				throw (std::runtime_error("Value is too high"));
			double cost = calculateTransaction(date_converted, cell_amount);

			transaction_.insert(std::make_pair(date_converted, cost)); //saving correct transactions
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << "Invalid transaction: " << e.what() << WHITE << " (" << row << ")" << ENDCLR << '\n';
		}
	}
}

void static my_date_print(time_t date)
{
	std::tm *reversed_date = std::localtime(&date);
	std::cout 	<< reversed_date->tm_year + 1900 << "/"
				<< reversed_date->tm_mon + 1 << "/"
				<< reversed_date->tm_mday;
}

double BtcExchng::calculateTransaction(time_t date, double amount)
{
	std::cout << std::fixed;
	std::cout.precision(1);
			
	std::map<time_t, double>::iterator exchange_rate_data;
	exchange_rate_data = price_.upper_bound(date); //the first date  after it
	if (exchange_rate_data != price_.begin())
		exchange_rate_data--; //decrease it to be the date itself or a date before it
	if (exchange_rate_data->first <= date)
	{
		double cost = amount * exchange_rate_data->second;
		std::cout << GREEN << "🗓️  Date: " << ENDCLR ; my_date_print(date);
		std::cout << GREEN << "\n\t🛒  Buying: " << ENDCLR << amount;
		std::cout << WHITE << "\n\t📊  Exchange date: " << ENDCLR ; my_date_print(exchange_rate_data->first);
		std::cout << GREEN << "\n\t📊  Exchange rate: " << ENDCLR << exchange_rate_data->second;
		std::cout << GREEN_B << "\n\t💸  Cost: " << ENDCLR << cost;
		std::cout << std::endl;
		return cost;
	}
	else
		throw (std::runtime_error("Transaction date is too early"));
}
