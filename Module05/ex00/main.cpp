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
    testIncrementGrade("Rony Rustico");
    testDecrementGrade("Raphael Veiga");
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
    std::cout << "*****(yes, it's counterintuitive, but the increment here is the subtraction)*****" << std::endl;
    Bureaucrat random(name, 2);
	try {
        random.incrementGrade(1);
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
    std::cout << "\t Increment 1 to Bureaucrat Grade 1 (Now it should throw an exception)" << std::endl;
    try {
        random.incrementGrade(1);
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
    std::cout << "____|           End of test          |__" << std::endl;
    std::cout << "\n||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
}

void testDecrementGrade( std::string name )
{
    std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||\n" << std::endl;
    std::cout << "____| Test Increment Bureaucrat's Grade |__" << std::endl;
    std::cout << "\t Decrement 1 to Bureaucrat Grade 149 (No output means its working properly)" << std::endl;
    std::cout << "****(yes, it's counterintuitive, but the decrement here is the addition)****" << std::endl;
    Bureaucrat random(name, 149);
	try {
        random.decrementGrade(1);
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
    std::cout << "\t Decrement 1 to Bureaucrat Grade 150 (Now it should throw an exception)" << std::endl;
    try {
        random.decrementGrade(1);
    }
    catch (std::exception &e){
        std::cout << "EXCEPTION: " << e.what() << std::endl;
    }
    std::cout << "____|           End of test          |__" << std::endl;
    std::cout << "\n||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
}
