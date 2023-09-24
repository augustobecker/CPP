# include <iostream>
# include "RPN.hpp"

void testCases( void );
void calculateRPN( std::string expression );

int main ( int argc, char **argv )
{
    std::string input;

    input = argv[argc - 1];
    if (argc != 2)
    {
        std::cout << "RPN : invalid number of arguments" << std::endl;
		std::cout << "\tusage : ./RPN <RPN expression> "<< std::endl;
    }
    else if (!input.compare("tests"))
        testCases();
    else
        calculateRPN(input);
    return (0);
}

void testCases( void )
{
    std::cout << "_____________ Subject Test Cases _____________" << std::endl;
    std::cout << "./RPN  \"8 9 * 9 - 9 - 9 - 4 - 1 +\"" << std::endl;
    calculateRPN( "8 9 * 9 - 9 - 9 - 4 - 1 +");
    std::cout << std::endl;

    std::cout << "./RPN \"7 7 * 7 -\"" << std::endl;
    calculateRPN("7 7 * 7 -");
    std::cout << std::endl;

    std::cout << "./RPN \"1 2 * 2 / 2 * 2 4 - +\"" << std::endl;
    calculateRPN("1 2 * 2 / 2 * 2 4 - +");
    std::cout << std::endl;

    std::cout << "./RPN \"(1 + 1)\"" << std::endl;
    calculateRPN("( 1 + 1 )");

    std::cout << "_____________ Invalid Test Cases _____________" << std::endl;

    std::cout << "./RPN \"15 5 - 0 /\"" << std::endl;
    calculateRPN("15 5 - 0 /");
    std::cout << std::endl;

    std::cout << "./RPN \"1 2 * 2 / 2 * 2 4\"" << std::endl;
    calculateRPN("1 2 * 2 / 2 * 2 4");
}

void calculateRPN( std::string expression )
{
    try {
        RPN::calculate(expression);
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
}