# include <iostream>
# include <exception>
# include "BitcoinExchange.hpp"
# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
#include <iomanip>

const std::string BitcoinExchange::databaseFilename = "data.csv";

BitcoinExchange::BitcoinExchange( void )
{

}

BitcoinExchange::~BitcoinExchange( void )
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
{
    *this = obj;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &toCopyFrom)
{
    if (this != &toCopyFrom)
        return (*this);
    return (*this);
}

void BitcoinExchange::validateFile( std::string filename )
{
	std::ifstream testFile;

	testFile.open(filename.c_str() , std::ifstream::in);
	if (!testFile)
	{
		testFile.close();
		throw (BitcoinExchange::CouldNotOpenFileException());
	}
	testFile.close();
}

std::map<std::string, double> BitcoinExchange::databaseToMapContainer( void )
{
	std::ifstream					databaseFile;
	std::map<std::string, double> 	map;
	std::string						currentLine;
	std::string 					key;
    double 							value;

	validateFile( BitcoinExchange::databaseFilename );
	databaseFile.open(BitcoinExchange::databaseFilename.c_str() , std::ifstream::in);
	while (std::getline(databaseFile, currentLine))
	{
		std::istringstream lineStream(currentLine);

		if (std::getline(lineStream, key, ',') && lineStream >> value)
			map[key] = value;
	}
	databaseFile.close();
	return (map);
}

void BitcoinExchange::exchange( std::string inputFilename )
{
    std::map<std::string, double>	database = databaseToMapContainer();
	std::ifstream					inFile;
	std::string						currentLine;
	std::string 					date;
    double 							value;

	validateFile( inputFilename );
	inFile.open(inputFilename.c_str(), std::ifstream::in);
	std::getline(inFile, currentLine);
	if (currentLine.compare("date | value"))
		std::cout << "Error: bad header" << std::endl;
	while (std::getline(inFile, currentLine))
	{
		try
		{
			date = getDate(currentLine);
			value = getValue(currentLine);

			std::cout << date << " => " << value << " = " << value * getLastBitcoinValue(database, date) << std::endl;
		}
		catch (BadInputException& e)
		{
			std::cout << e.what() << " => " <<  currentLine.substr(0, currentLine.find('|')) << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}

std::string BitcoinExchange::getDate( std::string str )
{
	std::istringstream	strStream(str);
	std::string			date;

	std::getline(strStream, date, '|');

	if (!isDateValid(date))
		throw (BitcoinExchange::BadInputException());
	return (date);
}

double BitcoinExchange::getValue( std::string str )
{
	double				value;

	value = static_cast<double>(std::strtod(str.substr(str.find('|') + 1, str.size() ).c_str(), 0));

	if (value < 0)
		throw (BitcoinExchange::NotAPositiveNumberException());
	if (value > 10000)
		throw (BitcoinExchange::TooLargeNumberException());
	return (value);
}

double BitcoinExchange::getLastBitcoinValue( std::map<std::string, double>	database, std::string date )
{
    std::map<std::string, double>::const_iterator it = database.lower_bound(date);
	const std::string& returnedDate = it->first;

	if (it == database.begin() || returnedDate == date)
		return it->second;
	--it;
	return it->second;
}


bool	BitcoinExchange::isDateValid( std::string date )
{
	if (date.size() != DATE_MAX_SIZE)
		return (false);
	if (date[YearMonthSeparator] != '-' || date[MonthDaySeparator] != '-')
		return (false);
	for (int i = 0; i < DATE_MAX_SIZE; i++)
	{
		if (i == YearMonthSeparator || i == MonthDaySeparator)
			i++;
		if (i == FinalSpace)
			break;
		if (!std::isdigit(date[i]))
			return (false);
	}
	
	short int year = static_cast<int>(std::atol(date.substr(YearThousandsDigit, YearMonthSeparator).c_str()));
	short int month = static_cast<int>(std::atol(date.substr(MonthTensDigit, MonthDaySeparator).c_str()));
	short int day = static_cast<int>(std::atol(date.substr(DayTensDigit, DayOnesDigit).c_str()));

	if (month < 1 || month > 12)
		return (false);
	if (day < 1 || day > 31)
		return (false);
	if ((month == 4 || month == 6 || month == 9 || month == 11) && (day == 31))
		return (false);
	if ((month == 2) && (day > 28))
	{
		if (((day == 29) && ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))))
			return (true);
		return (false);
	}
	return (true);
}

const char* BitcoinExchange::CouldNotOpenFileException::what() const throw()
{
	return "Error: could not open file.";
}

const char* BitcoinExchange::NotAPositiveNumberException::what() const throw()
{
	return "Error: not a positive number.";
}

const char* BitcoinExchange::TooLargeNumberException::what() const throw()
{
	return "Error: too large number.";
}

const char* BitcoinExchange::BadInputException::what() const throw()
{
	return "Error: bad input";
}
