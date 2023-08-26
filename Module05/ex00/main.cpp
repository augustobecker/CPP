# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

# define HIGEST_GRADE   1
# define LOWEST_GRADE   150

void testCreateValidBureaucrat( std::string name );
void testCreateInvalidBureaucrat( std::string name );
void testIncrementGrade( std::string name );
void testDecrementGrade( std::string name );

int main( void )
{
    testCreateValidBureaucrat("Amanda");
    testCreateInvalidBureaucrat("Naty");
    //testIncrementOperators();
    //testDecrementOperators();
    return 0;
}

void testCreateValidBureaucrat( std::string name )
{
    std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||\n" << std::endl;
    std::cout << "____| Test Create Valid Bureaucrat |__" << std::endl;
    std::cout << "\t (No output means its working properly)" << std::endl;
    try {
        Bureaucrat random(name, HIGEST_GRADE);
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
    try {
        Bureaucrat random(name, LOWEST_GRADE);
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
    std::cout << "____|         End of test          |__" << std::endl;
    std::cout << "\n||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
}

void testCreateInvalidBureaucrat( std::string name )
{
    std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||\n" << std::endl;
    std::cout << "____| Test Create Invalid Bureaucrat |__" << std::endl;
    std::cout << "\t (should throw an exception)" << std::endl;
    try {
        Bureaucrat random(name, HIGEST_GRADE - 1);
    } 
    catch (std::exception &e){
        std::cout << "EXCEPTION: " << e.what() << std::endl;
    }
    std::cout << "\t (Also should throw an exception)" << std::endl;
    try {
        Bureaucrat random(name, LOWEST_GRADE + 1);
    } 
    catch (std::exception &e){
        std::cout << "EXCEPTION: " << e.what() << std::endl;
    }
    std::cout << "____|           End of test          |__" << std::endl;
    std::cout << "\n||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
}

void testIncrementGrade( std::string name )
{
    std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||\n" << std::endl;
    std::cout << "____| Test Increment Bureaucrat's Grade |__" << std::endl;
    std::cout << "\t Increment 1 to Bureaucrat Grade 2 (No output means its working properly)" << std::endl;
	
    std::cout << "\t (should throw an exception)" << std::endl;

    std::cout << "_______| TEST INCREMENT |_______" << std::endl;
    std::cout << "__| yes, it's counterintuitive, but the increment here is the subtraction |__" << std::endl;

    //std::cout << "\t" << Rafael << std::endl;
    //std::cout << "\t" << Marco << std::endl;
    //std::cout << "\t" << Amanda << std::endl;

    std::cout << "_______| + 1 |_______" << std::endl;

    Rafael.incrementGrade(1);
    Marco.incrementGrade(1);
    Amanda.incrementGrade(1);

    //std::cout << "\t" << Rafael << std::endl;
    //std::cout << "\t" << Marco << std::endl;
    //std::cout << "\t" << Amanda << std::endl;

    std::cout << "_______| TEST PRE INCREMENT IN EXCEPTION CASES |_______" << std::endl;
    Amanda.incrementGrade(1);
    //std::cout << "\t" << Amanda << std::endl;

    std::cout << "_______| TEST POST INCREMENT IN EXCEPTION CASES |_______" << std::endl;
   // std::cout << "\t" << Amanda++ << std::endl;
   std::cout << "____| End of test |__" << std::endl;
   std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||\n" << std::endl;
}

void testDecrementGrade( std::string name )
{
    std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||\n" << std::endl;
	Bureaucrat Augusto("Augusto", 1);
    Bureaucrat Nicolas("Nicolas", 22);
    Bureaucrat Natalia("Natalia", 147);

    std::cout << "_______| TEST INCREMENT OPERATORS |_______" << std::endl;

    //std::cout << "\t" << Augusto << std::endl;
    //std::cout << "\t" << Nicolas << std::endl;
    //std::cout << "\t" << Natalia << std::endl;

    std::cout << "_______| TEST PRE DECREMENT |_______" << std::endl;

    //std::cout << "\t" << --Augusto << std::endl;
    //std::cout << "\t" << --Nicolas << std::endl;
    //std::cout << "\t" << --Natalia << std::endl;

    std::cout << "_______| TEST POST DECREMENT |_______" << std::endl;

    //std::cout << "\t" << Augusto-- << std::endl;
    //std::cout << "\t" << Nicolas-- << std::endl;
    //std::cout << "\t" << Natalia-- << std::endl;
    std::cout << "     | post decrement |" << std::endl;
    //std::cout << "\t" << Augusto << std::endl;
    //std::cout << "\t" << Nicolas << std::endl;
    //std::cout << "\t" << Natalia << std::endl;

    std::cout << "_______| TEST PRE DECREMENT IN EXCEPTION CASES |_______" << std::endl;
    //std::cout << "\t" << --Natalia << std::endl;

    std::cout << "_______| TEST POST DECREMENT IN EXCEPTION CASES |_______" << std::endl;
    //std::cout << "\t" << Natalia-- << std::endl;
    std::cout << "____| End of test |__" << std::endl;
    std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||\n" << std::endl;
}
