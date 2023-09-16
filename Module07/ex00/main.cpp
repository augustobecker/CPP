# include <iostream>
# include "whatever.hpp"

void subjectTests( void );
void floatTests( void );
void doubleTests( void );
void charTests( void );

int main(void)
{
    subjectTests();
    std::cout << "______________________________________________________" << std::endl;
    floatTests();
    std::cout << "_______________________________________________________" << std::endl;
    doubleTests();
    std::cout << "_______________________________________________________" << std::endl;
    charTests();
    std::cout << "_______________________________________________________" << std::endl;
    return 0;
}

void subjectTests( void )
{
    std::cout << "________________|Subject Tests|______________________" << std::endl;
    int a = 2;
    int b = 3;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
    
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
}

void floatTests( void )
{
    std::cout << "________________|Float Type Tests|____________________" << std::endl;
    float a = 3.5;
    float b = 3.333;

    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
}

void doubleTests( void )
{
    std::cout << "________________|Double Type Tests|____________________" << std::endl;
    double a = 7.5;
    double b = 3.333;

    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
}

void charTests( void )
{
    std::cout << "________________|Char Type Tests|______________________" << std::endl;
    char a = 'a';
    char b = 'A';

    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
}

