/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:11:30 by zpalotas          #+#    #+#             */
/*   Updated: 2026/04/17 19:45:03 by zpalotas         ###   ########.fr       */
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
	for (std::map<std::string, std::string>::iterator it = price_.begin(); it != price_.end(); it++)
		std::cout << "key: " << it->first << " -> value: " << it->second << std::endl;
	for (std::map<std::string, std::string>::iterator it = transaction_.begin(); it != transaction_.end(); it++)
		std::cout << "key: " << it->first << " | value: " << it->second << std::endl;
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

void BtcExchng::readPrices(const std::string prices)
{
	std::ifstream file_to_read;
	file_to_read.open(prices.c_str());
	std::string		row;
	std::string		cell_date;
	std::string 	cell_price;
	while (!file_to_read.eof() && !file_to_read.fail())
	{
		std::getline(file_to_read, row);
		std::stringstream	row_stream(row);
		getline(row_stream, cell_date, ',');
		getline(row_stream, cell_price, ',');
		//double date  = std::stod(cell_date); //TODO handle fail
		//double price = std::stod(cell_price);//TODO handle fail
		price_.insert(std::make_pair(cell_date, cell_price));
		if (!row_stream.eof())
			throw (std::runtime_error("Unexpected cells in the row in prices file"));
	}
}

void BtcExchng::readTransactions(const std::string transactions)
{
	std::ifstream file_to_read;
	file_to_read.open(transactions.c_str());
	std::string		row;
	std::string		cell_date;
	std::string 	cell_amount;
	while (!file_to_read.eof() && !file_to_read.fail())
	{
		std::getline(file_to_read, row);
		std::stringstream	row_stream(row);
		getline(row_stream, cell_date, '|');
		getline(row_stream, cell_amount, '|');
		//double date  = std::stod(cell_date); //TODO handle fail
		//double price = std::stod(cell_amount);//TODO handle fail
		transaction_.insert(std::make_pair(cell_date, cell_amount));
		if (!row_stream.eof())
			throw (std::runtime_error("Unexpected cells in the row in transactions file "));
	}
}
