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

std::map<std::string, double> BitcoinExchange::getDatabaseValues( void )
{
	std::map<std::string, double> 	map;
	std::ifstream					databaseFile;
	std::string						currentLine;
	std::string 					key;
    double 							value;

	databaseFile.open(BitcoinExchange::databaseFilename.c_str() , std::ifstream::in);
	if(databaseFile.is_open())
	{
		while (std::getline(databaseFile, currentLine))
		{
        	std::istringstream lineStream(currentLine);

        	if (std::getline(lineStream, key, ',') && lineStream >> value)
            	map[key] = value;
        }
    }
	databaseFile.close();
	return (map);
} 
void BitcoinExchange::exchange( std::string inputFilename )
{
    std::map<std::string, double> database = getDatabaseValues();
	std::map<std::string, double>::iterator it;

    for (it = database.begin(); it != database.end(); ++it) {
        std::cout << it->first << ": " << std::fixed << std::setprecision(2) << it->second << std::endl;
    }
	if (!inputFilename.empty())
		std::cout << "\tfinal execução "<< std::endl;


}


// void BitcoinExchange::validateInputFile( std::ifstream inputFile )
// {
//     std::string line;

// 	std::getline(inputFile, line);
// 	if (line != "date | value")
// 		throw std::runtime_error("Invalid Header");
// 	while (std::getline(ifs, line))
//     {
// 		if (line.find("|") == std::string::npos || line.empty())
// 			std::cout << "Error: bad input => " << line << std::endl;
// 		else
// 		{
// 			size_t pos = line.find('|');
// 			date = line.substr(0, pos);
// 			value = line.substr(pos + 1);
// 			float rate = atof(value.c_str());
// 			_calcBitcoin(date, rate);
// 		}
// 	}
// }

//**************************************
// std::ifstream	data;
// 	std::string		line;

// 	data.open("data.csv", std::ifstream::in);
// 	if(data.is_open())
// 	{
// 		while(getline(data, line))
// 		{
// 			size_t	sep = line.find(',');
// 			_map[line.substr(0, sep)] = std::strtod(line.substr(sep + 1, line.size() - sep).c_str(), NULL);
// 		}
// 	}
// 	data.close();

// 	std::ifstream	file;
// 	std::string		line;

// 	file.open(file_name.data(), std::ifstream::in);
// 	if(file.is_open())
// 	{
// 		getline(file, line);
// 		while(getline(file, line))
// 		{
// 			try
// 			{
// 				std::string	key = getKey(line);
// 				double		value = getValue(line);
				
// 				std::cout << key << " => " << value << " = " << value * getBottomDate(key) << std::endl;
// 			}
// 			catch (NotAPositiveNumberException& e)
// 			{
// 				std::cout << e.what();
// 			}
// 			catch (TooLargeNumberException& e)
// 			{
// 				std::cout << e.what();
// 			}
// 			catch (BadInputException& e)
// 			{
// 				std::cout << e.what() << " => " << line << std::endl;
// 			}
// 		}
// 	}
// 	else
// 		throw CouldNotOpenFileException();
// 	file.close();




	
// double	BitcoinExchange::getBottomDate(const std::string& targetDate) const
// {
// 	std::map<std::string, double>::const_iterator it = _map.lower_bound(targetDate);
// 	const std::string& returnedDate = it->first;

// 	if (it == _map.begin() || returnedDate == targetDate)
// 		return it->second;
// 	--it;
// 	return it->second;
// }

// bool	BitcoinExchange::isDate(std::string date) const
// {
// 	if (date.size() != 10)
// 		return (false);
// 	if (date[5] != '0' && date[5] != '1')
// 		return (false);
// 	if (date[8] > '3' || date[8] < '0')
// 		return (false);
// 	for (size_t i = 0; i < date.size(); i++)
// 	{
// 		if (!std::isdigit(date[i]) && date[i] != '-')
// 			return (false);
// 	}
// 	return (true);
// }

// std::string	BitcoinExchange::getKey(std::string line) const
// {
// 	size_t		sep;
// 	std::string	key;

// 	sep = line.find(" | ");
// 	if (sep == std::string::npos)
// 		throw BadInputException();
// 	key = line.substr(0, sep);
// 	if (isDate(key))
// 		return (key);
// 	throw BadInputException();
// }

// double	BitcoinExchange::getValue(std::string line) const
// {
// 	size_t		sep;
// 	double		value;

// 	sep = line.find(" | ");
// 	line = line.substr(sep + 3, line.size());
// 	value = std::strtod(line.c_str(), NULL);
// 	if (value < 0)
// 		throw NotAPositiveNumberException();
// 	if(value > 1000)
// 		throw TooLargeNumberException();
// 	return (value);
// }