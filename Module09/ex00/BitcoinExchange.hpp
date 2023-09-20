#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <algorithm>
# include <map>

# define DATE_MAX_SIZE 11

enum DateDigitPosition
{
    YearThousandsDigit,
    YearHundredsDigit,
    YearTensDigit,
    YearOnesDigit,
	YearMonthSeparator,
    MonthTensDigit,
    MonthOnesDigit,
	MonthDaySeparator,
    DayTensDigit,
    DayOnesDigit,
	FinalSpace
};

class BitcoinExchange
{

private:
	
	BitcoinExchange( void );
	BitcoinExchange( const BitcoinExchange & );

	static bool isDateValid( std::string );
	static void validateFile( std::string filename );

	static std::map<std::string, double> databaseToMapContainer ( void );

	static std::string 	getDate( std::string );
	static double		getValue( std::string );

	static double getLastBitcoinValue( std::map<std::string, double>, std::string );

public:

	static const std::string databaseFilename;

	~BitcoinExchange( void );

	BitcoinExchange& operator=( const BitcoinExchange & );

	static void 	exchange( std::string );

	class	CouldNotOpenFileException : public std::exception
	{
		public:
		const char* what() const throw();
	};

	class	NotAPositiveNumberException : public std::exception
	{
		public:
		const char* what() const throw();
	};

	class	TooLargeNumberException : public std::exception
	{
		public:
		const char* what() const throw();
	};

	class	BadInputException : public std::exception
	{
		public:
		const char* what() const throw();
	};

};

#endif
