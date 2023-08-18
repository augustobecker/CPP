# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

void testIncrementOperators( void );
void testDecrementOperators( void );

int main( void )
{
    testIncrementOperators();
    std::cout << "\n||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
    std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||\n" << std::endl;
    testDecrementOperators();
    return 0;
}

void testIncrementOperators( void )
{
	Bureaucrat Rafael("Rafael");
    Bureaucrat Marco("Marco Tulio", 42);
    Bureaucrat Amanda("Amanda", 3);

    std::cout << "_______| TEST DECREMENT OPERATORS |_______" << std::endl;
    std::cout << "__| yes, it's counterintuitive, but the increment here is the subtraction |__" << std::endl;

    std::cout << "\t" << Rafael << std::endl;
    std::cout << "\t" << Marco << std::endl;
    std::cout << "\t" << Amanda << std::endl;

    std::cout << "_______| TEST PRE INCREMENT |_______" << std::endl;

    std::cout << "\t" << ++Rafael << std::endl;
    std::cout << "\t" << ++Marco << std::endl;
    std::cout << "\t" << ++Amanda << std::endl;

    std::cout << "_______| TEST POST INCREMENT |_______" << std::endl;

    std::cout << "\t" << Rafael++ << std::endl;
    std::cout << "\t" << Marco++ << std::endl;
    std::cout << "\t" << Amanda++ << std::endl;
    std::cout << "     | post increment |" << std::endl;
    std::cout << "\t" << Rafael << std::endl;
    std::cout << "\t" << Marco << std::endl;
    std::cout << "\t" << Amanda << std::endl;

    std::cout << "_______| TEST PRE INCREMENT IN EXCEPTION CASES |_______" << std::endl;
    std::cout << "\t" << ++Amanda << std::endl;

    std::cout << "_______| TEST POST INCREMENT IN EXCEPTION CASES |_______" << std::endl;
    std::cout << "\t" << Amanda++ << std::endl;
}

void testDecrementOperators( void )
{
	Bureaucrat Augusto("Augusto", 1);
    Bureaucrat Nicolas("Nicolas", 22);
    Bureaucrat Natalia("Natalia", 147);

    std::cout << "_______| TEST INCREMENT OPERATORS |_______" << std::endl;

    std::cout << "\t" << Augusto << std::endl;
    std::cout << "\t" << Nicolas << std::endl;
    std::cout << "\t" << Natalia << std::endl;

    std::cout << "_______| TEST PRE DECREMENT |_______" << std::endl;

    std::cout << "\t" << --Augusto << std::endl;
    std::cout << "\t" << --Nicolas << std::endl;
    std::cout << "\t" << --Natalia << std::endl;

    std::cout << "_______| TEST POST DECREMENT |_______" << std::endl;

    std::cout << "\t" << Augusto-- << std::endl;
    std::cout << "\t" << Nicolas-- << std::endl;
    std::cout << "\t" << Natalia-- << std::endl;
    std::cout << "     | post decrement |" << std::endl;
    std::cout << "\t" << Augusto << std::endl;
    std::cout << "\t" << Nicolas << std::endl;
    std::cout << "\t" << Natalia << std::endl;

    std::cout << "_______| TEST PRE DECREMENT IN EXCEPTION CASES |_______" << std::endl;
    std::cout << "\t" << --Natalia << std::endl;

    std::cout << "_______| TEST POST DECREMENT IN EXCEPTION CASES |_______" << std::endl;
    std::cout << "\t" << Natalia-- << std::endl;
}