# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

int main( void )
{
    Bureaucrat Rafael("Rafael");
    Bureaucrat Marco("Marco Tulio", 10);

    std::cout << ++Rafael << std::endl;
    std::cout << Marco++ << std::endl;
    return (0);
}
