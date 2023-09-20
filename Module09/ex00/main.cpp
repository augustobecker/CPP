# include <iostream>
# include "BitcoinExchange.hpp"
# include <fstream>

int main ( int argc, char **argv )
{
    if (argc != 2)
    {
        std::cout << "btc : invalid number of arguments" << std::endl;
		std::cout << "\tusage : ./btc <input_file> "<< std::endl;
        return (0);
    }
    try {
        BitcoinExchange::exchange(argv[1]);
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
    return (0);
}
