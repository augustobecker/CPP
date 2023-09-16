# include <iostream>
# include "ScalarConverter.hpp"

void testCases( void );

int main ( int argc, char **argv )
{
    std::string input;

    input = argv[argc - 1];
    if (argc != 2)
    {
        std::cout << "ScalarConverter : Invalid Number of Parameters" << std::endl;
		std::cout << "\tusage : ./converter <str_literal> "<< std::endl;
        std::cout << "\t\t<str_literal> : string literal to be converted in char, int, float and double "<< std::endl;
    }
    else if (!input.compare("tests"))
        testCases();
    else
        ScalarConverter::convert(argv[1]);
    return (0);
}

void testCases( void )
{
    std::cout << "_____________ Test Cases _____________" << std::endl;
    std::cout << "./convert 420" << std::endl;
    ScalarConverter::convert("420");
    std::cout << std::endl;

    std::cout << "./convert -4.25" << std::endl;
    ScalarConverter::convert("-4.25");
    std::cout << std::endl;

    std::cout << "./convert -42.0f" << std::endl;
    ScalarConverter::convert("-42.0f");
    std::cout << std::endl;
    
    std::cout << "./convert 0" << std::endl;
    ScalarConverter::convert("0");
    std::cout << std::endl;

    std::cout << "./convert 2147483649" << std::endl;
    ScalarConverter::convert("2147483649");
    std::cout << std::endl;

    std::cout << "./convert nan" << std::endl;
    ScalarConverter::convert("nan");
    std::cout << std::endl;

    std::cout << "./convert -inf" << std::endl;
    ScalarConverter::convert("-inf");
    std::cout << std::endl;

    std::cout << "./convert string" << std::endl;
    ScalarConverter::convert("string");
    std::cout << std::endl;

    std::cout << "_____________ Test Pseudo Literal _____________" << std::endl;

    std::cout << "./convert -inff" << std::endl;
    ScalarConverter::convert("-inff");
    std::cout << std::endl;

    std::cout << "./convert inff" << std::endl;
    ScalarConverter::convert("-inff");
    std::cout << std::endl;

    std::cout << "./convert nanf" << std::endl;
    ScalarConverter::convert("nanf");
    std::cout << std::endl;

    std::cout << "./convert -inf" << std::endl;
    ScalarConverter::convert("-inf");
    std::cout << std::endl;

    std::cout << "./convert inff" << std::endl;
    ScalarConverter::convert("-inf");
    std::cout << std::endl;

    std::cout << "./convert nan" << std::endl;
    ScalarConverter::convert("nan");
    std::cout << std::endl;

    std::cout << "_____________ Test Data Types Limits _____________" << std::endl;

    std::cout << "./convert 0" << std::endl;
    ScalarConverter::convert("0");
    std::cout << std::endl;

    std::cout << "./convert -1" << std::endl;
    ScalarConverter::convert("-1");
    std::cout << std::endl;

    std::cout << "./convert 120" << std::endl;
    ScalarConverter::convert("120");
    std::cout << std::endl;

    std::cout << "./convert 127" << std::endl;
    ScalarConverter::convert("127");
    std::cout << std::endl;

    std::cout << "./convert 128" << std::endl;
    ScalarConverter::convert("128");
    std::cout << std::endl;

    std::cout << "./convert -2147483648" << std::endl;
    ScalarConverter::convert("-2147483648");
    std::cout << std::endl;

    std::cout << "./convert -2147483649" << std::endl;
    ScalarConverter::convert("-2147483649");
    std::cout << std::endl;

    std::cout << "./convert 2147483647" << std::endl;
    ScalarConverter::convert("2147483647");
    std::cout << std::endl;

    std::cout << "./convert 2147483648" << std::endl;
    ScalarConverter::convert("2147483648");
    std::cout << std::endl;
}