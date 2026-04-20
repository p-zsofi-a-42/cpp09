/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:11:30 by zpalotas          #+#    #+#             */
/*   Updated: 2026/04/20 14:41:26 by zpalotas         ###   ########.fr       */
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
	for (std::map<std::string, double>::iterator it = price_.begin(); it != price_.end(); it++)
		std::cout << "key: " << it->first << " -> value: " << it->second << std::endl;
	for (std::map<std::string, double>::iterator it = transaction_.begin(); it != transaction_.end(); it++)
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
	std::string 	temp;

	//Discarding first, header line
	std::getline(file_to_read, temp, '\n');
	while (!file_to_read.eof() && !file_to_read.fail())
	{
		std::string		cell_date;
		double			cell_price = 0.0;
		std::getline(file_to_read, row);
		std::stringstream	row_stream(row);
		getline(row_stream, cell_date, ',');
		if (cell_date.empty())
			return;
		row_stream >> cell_price;
		if (!row_stream.eof())
			throw (std::runtime_error("Unexpected characters in prices line "));
		if (row_stream.fail())
			throw (std::runtime_error("Prices value is invalid"));
		price_.insert(std::make_pair(cell_date, cell_price));
	}
}

void BtcExchng::readTransactions(const std::string transactions)
{
	std::ifstream file_to_read;
	file_to_read.open(transactions.c_str());
	std::string		row;
	std::string 	temp;

	//Discarding first, header line
	std::getline(file_to_read, temp, '\n');
	while (!file_to_read.eof() && !file_to_read.fail())
	{
		std::string		cell_date;
		double			cell_amount = 0.0;
		
		std::getline(file_to_read, row);
		std::stringstream	row_stream(row);
		getline(row_stream, cell_date, '|');
		if (cell_date.empty())
			return;
		row_stream >> cell_amount;
		//std::cout << "helo key: " << cell_date << " | value: " <<cell_amount << std::endl;
		if (!row_stream.eof())
			throw (std::runtime_error("Unexpected characters in transactions line "));
		if (row_stream.fail())
			throw (std::runtime_error("Transactions amount is invalid"));
		transaction_.insert(std::make_pair(cell_date, cell_amount));
	}
}
