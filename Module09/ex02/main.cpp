#include "PmergeMe.hpp"

int	main( int argc, char **argv )
{
	if (argc < 3)
	{
        std::cout << "PmergeMe: invalid number of arguments" << std::endl;
		return (0);
    }
	try
	{
		PmergeMe algorithm;
		algorithm.merge(argc, argv);
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
