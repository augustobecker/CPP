#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <algorithm>
# include <map>

class BitcoinExchange
{

private:
	
	BitcoinExchange( void );
	BitcoinExchange( const BitcoinExchange & );

public:

	static const std::string databaseFilename;

	~BitcoinExchange( void );

	BitcoinExchange& operator=( const BitcoinExchange & );

	static std::map<std::string, double> getDatabaseValues ( void );
	static void 	exchange( std::string );

};

#endif
