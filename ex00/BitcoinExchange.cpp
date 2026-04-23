/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalotas <zpalotas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:11:30 by zpalotas          #+#    #+#             */
/*   Updated: 2026/04/23 20:51:29 by zpalotas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"

static int counter = 0;

BtcExchng::BtcExchng()
{
	std::time(&todayDate_);
}

BtcExchng::BtcExchng(const std::string prices, const std::string transactions)
{
	std::time(&todayDate_);
	try
	{
		readPrices(prices);
		readTransactions(transactions);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Error: " << e.what() << ENDCLR << '\n';
		return;
	}
	if (DEBUG)
	{
		for (std::map<time_t, float>::iterator it = price_.begin(); it != price_.end(); it++)
		{	std::cout << "key: "; my_date_print(it->first); std::cout  <<  " -> value: " << it->second << std::endl;}
		for (std::multimap<time_t, float>::iterator it = transaction_.begin(); it != transaction_.end(); it++)
		{	std::cout << "key: "; my_date_print(it->first); std::cout  <<  " | value: " << it->second << std::endl;}
	}
}
	
BtcExchng::~BtcExchng()
{}

BtcExchng::BtcExchng(const BtcExchng &other)
{
	std::time(&todayDate_);
	*this = other;
}

BtcExchng &BtcExchng::operator=(const BtcExchng &other)
{
	if (this == &other)
		return *this;
	 price_ = other.price_;
	 transaction_ = other.transaction_;
	return (*this);
}

/** Reads the string(stream) parts into the date parameter's members 
 * @throws if date is invalid/misformatted */
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

	if (date.tm_year > 3000 || date.tm_mon > 11 || date.tm_mday > 31)
		throw (std::runtime_error("Date is not in the calendar's range"));
}

/** @throws if date is invalid/misformatted */
time_t BtcExchng::processDate(std::stringstream &cell_date)
{
	std::tm date = {};
	my_get_time(cell_date, date);
	std::tm date_double_check = date;
	time_t date_converted = std::mktime(&date);
	if (date_converted == -1)
		throw (std::runtime_error("Date misformatted. Not a date"));
	// check to see if the converted date is still the same as the original (eg febr.31 fails)
	bool valid_date = 	(date.tm_year == date_double_check.tm_year)
						&& (date.tm_mon == date_double_check.tm_mon)
						&& (date.tm_mday == date_double_check.tm_mday);
	if (!valid_date)
		throw (std::runtime_error("Date is not in the calendar's range"));
	if (date_converted > todayDate_)
		throw (std::runtime_error("Date is in the future"));
	// check if there is garbage after the date
	std::string temp;
	cell_date >> std::skipws >> temp; 
	if (!cell_date.eof() || !temp.empty())
		throw (std::runtime_error("Date misformatted"));
	return date_converted;
}

/** @throws if value is invalid/misformatted */
float BtcExchng::processValue(std::stringstream &row_stream)
{
	int is_stream_empty = row_stream.peek();
	if (is_stream_empty == EOF)
		throw (std::runtime_error("Value is missing"));

 	int first_char = row_stream.peek();
	if (first_char == '.')
		throw (std::runtime_error("Value has a bad float format"));

	float cell_price = 0.0;
	row_stream >> cell_price;
	// chack if the value is  representable as a float
	if (row_stream.fail())
		throw (std::runtime_error("Value is invalid"));
	if (cell_price < 0)
		throw (std::runtime_error("Value is negative"));
	// check if there is garbage after the value
	std::string temp;
	row_stream >> std::skipws >> temp; 
	if (!row_stream.eof() || !temp.empty())
		throw (std::runtime_error("Unexpected characters near the value"));
	return cell_price;
}

/** @throws if file cannot be opened */
void BtcExchng::readPrices(const std::string prices)
{
	std::ifstream file_to_read;
	file_to_read.open(prices.c_str());
	if (file_to_read.fail())
		throw (std::runtime_error("Database (exchange rates) cannot be opened"));
	
	//Discarding first, header line
	std::string  temp;
	std::getline(file_to_read, temp, '\n');
	while (!file_to_read.eof() && !file_to_read.fail())
	{
		std::string			row;
		std::getline(file_to_read, row);
		std::stringstream	row_stream(row);

		std::string			cell;
		getline(row_stream, cell, ',');
		std::stringstream	cell_date(cell);
		try
		{
			time_t date_converted =	processDate(cell_date);
			float cell_price = processValue(row_stream);

			price_.insert(std::make_pair(date_converted, cell_price));
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	file_to_read.close();
}

/** @throws if file cannot be opened 
 * @throws if the transaction value is above 1000
*/
void BtcExchng::readTransactions(const std::string transactions)
{
	std::ifstream file_to_read;
	file_to_read.open(transactions.c_str());
	if (file_to_read.fail())
		throw (std::runtime_error("File (transactions) cannot be opened"));
	//Discarding first, header line
	std::string 	temp;
	std::getline(file_to_read, temp, '\n');
	while (!file_to_read.eof() && !file_to_read.fail())
	{
		counter++;
		std::string			row;
		std::getline(file_to_read, row);
		std::stringstream	row_stream(row);

		std::string			cell;
		getline(row_stream, cell, '|');
		std::stringstream	cell_date(cell);
		try
		{
			time_t date_converted =	processDate(cell_date);
			float cell_amount = processValue(row_stream);
			if (cell_amount > 1000)
				throw (std::runtime_error("Value is too high"));
			float cost = calculateTransaction(date_converted, cell_amount);

			transaction_.insert(std::make_pair(date_converted, cost)); //saving correct transactions
		}
		catch(const std::exception& e)
		{
			if (DEBUG) 	std::cerr << counter << " ";
			std::cerr << RED << "Invalid transaction: " << e.what() << WHITE << " (" << row << ")" << ENDCLR << '\n';
		}
	}
	file_to_read.close();
}

/** Looks for the most recent exchange rate in the database, 
 * then multiplies it with the transaction value 
 * @throws if the transaction date is before the database start*/
float BtcExchng::calculateTransaction(time_t date, float amount)
{
	std::cout << std::fixed;
	std::cout.precision(1);
			
	std::map<time_t, float>::iterator exchange_rate_data;
	exchange_rate_data = price_.upper_bound(date); //the first date  after it
	if (exchange_rate_data != price_.begin())
		exchange_rate_data--; //decrease it to be the date itself or a date before it
	if (exchange_rate_data->first <= date)
	{
		float cost = amount * exchange_rate_data->second;
		if (DEBUG)	std::cout << counter << " ";
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

/** Prints the date in the Y/m/d format */
void BtcExchng::my_date_print(time_t date)
{
	std::tm *reversed_date = std::localtime(&date);
	std::cout 	<< reversed_date->tm_year + 1900 << "/"
				<< reversed_date->tm_mon + 1 << "/"
				<< reversed_date->tm_mday;
}