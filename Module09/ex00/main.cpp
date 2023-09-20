# include <iostream>
# include "BitcoinExchange.hpp"
# include <fstream>

bool isInputValid( int argc, char **argv );
bool fileExists( const std::string& filename );

int main ( int argc, char **argv )
{
    if (isInputValid(argc, argv))
    {
        try {
            BitcoinExchange::exchange(argv[1]);
        }
        catch (std::exception &e){
            std::cout << e.what() << std::endl;
        }
    }
    return (0);
}

bool isInputValid( int argc, char **argv )
{
    if (argc != 2)
    {
        std::cout << "btc : invalid number of arguments" << std::endl;
		std::cout << "\tusage : ./btc <input_file> "<< std::endl;
        return false;
    }
    else if (!argv[1][0])
    {
        std::cout << "btc : invalid file" << std::endl;
        return false;
    }
    else if (!fileExists(argv[1]))
    {
        std::cout << "btc : invalid input file" << std::endl;
        return false;
    }
    else if (!fileExists(BitcoinExchange::databaseFilename))
    {
        std::cout << "btc : couldn't open database file: " << BitcoinExchange::databaseFilename << std::endl;
        return false;
    }
    return true;
}

bool fileExists( const std::string& filename )
{
    std::ifstream test_file(filename.c_str());
    return test_file.good();
}