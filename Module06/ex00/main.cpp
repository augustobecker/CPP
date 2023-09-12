# include <iostream>
# include "ScalarConverter.hpp"

/* 
	test cases: 420, -4.25, 42.0f, 0, 2147483649, nan, -inf, string
*/

int main ( int argc, char **argv )
{
    if (argc != 2)
    {
        std::cout << "ScalarConverter : Invalid Number of Parameters" << std::endl;
		std::cout << "\tusage : ./converter <str_literal> "<< std::endl;
        std::cout << "\t\t<str_literal> : string literal to be converted in char, int, float and double "<< std::endl;
    }
    else
        ScalarConverter::convert(argv[1]);
    return (0);
}
