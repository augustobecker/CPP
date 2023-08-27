# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"
# include "Form.hpp"

# define HIGEST_GRADE   1
# define LOWEST_GRADE   150

void testCreateValidBureaucrat( std::string name );
void testCreateInvalidBureaucrat( std::string name );

void testOverloadInsertionBureaucrat( std::string name );

void testIncrementGrade( std::string name );
void testDecrementGrade( std::string name );

void testCreateValidForm( std::string name );
void testCreateInvalidForm( std::string name );

void testOverloadInsertionForm( std::string name );

void testFormBeSignMethodQualifiedBureaucrat( void );
void testFormBeSignMethodUnqualifiedBureaucrat( void );

void testBureaucratSignFormMethodBeingQualified( void );
void testBureaucratSignFormMethodBeingUnqualified( void );

int main( void )
{
    testCreateValidBureaucrat("Amanda");
    testCreateInvalidBureaucrat("Naty");

    testOverloadInsertionBureaucrat("Abel Ferreira");

    testIncrementGrade("Rony Rustico");
    testDecrementGrade("Raphael Veiga");

    testCreateValidForm("Entry");
    testCreateInvalidForm("42 Admission");

    testOverloadInsertionForm("Socio Avanti Admission");

    testFormBeSignMethodQualifiedBureaucrat();
    testFormBeSignMethodUnqualifiedBureaucrat();

    testBureaucratSignFormMethodBeingQualified();
    testBureaucratSignFormMethodBeingUnqualified();
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
        std::cout << "EXCEPTION: " << e.what() << std::endl;
    }

    try {
        Bureaucrat random(name, LOWEST_GRADE);
    }
    catch (std::exception &e){
        std::cout << "EXCEPTION: " << e.what() << std::endl;
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

void testOverloadInsertionBureaucrat( std::string name )
{
    std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||\n" << std::endl;
    std::cout << "____| Test  Bureaucrat Overload << |__" << std::endl;
    std::cout << "\t (Should output '<name>, bureaucrat grade <grade>.')" << std::endl;

    Bureaucrat random(name, HIGEST_GRADE);

    std::cout << random << std::endl;
    
    std::cout << "____|         End of test          |__" << std::endl;
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
        std::cout << "EXCEPTION: " << e.what() << std::endl;
    }

    std::cout << "\t Increment 1 to Bureaucrat Grade 1 (Now it should throw an exception)" << std::endl;

    try {
        random.incrementGrade(1);
    }
    catch (std::exception &e){
        std::cout << "EXCEPTION: " << e.what() << std::endl;
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
        std::cout << "EXCEPTION: " << e.what() << std::endl;
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

void testCreateValidForm( std::string name )
{
    std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||\n" << std::endl;
    std::cout << "____| Test Create Valid From   |__" << std::endl;
    std::cout << "\t (No output means its working properly)" << std::endl;

    try {
        Form document(name, LOWEST_GRADE, HIGEST_GRADE);
    }
    catch (std::exception &e){
        std::cout << "EXCEPTION: " << e.what() << std::endl;
    }

    try {
        Form document(name, HIGEST_GRADE, HIGEST_GRADE);
    }
    catch (std::exception &e){
        std::cout << "EXCEPTION: " << e.what() << std::endl;
    }

    std::cout << "____|         End of test          |__" << std::endl;
    std::cout << "\n||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
}

void testCreateInvalidForm( std::string name )
{
    std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||\n" << std::endl;
    std::cout << "____| Test Create Invalid Form |__" << std::endl;
    std::cout << "\t (should throw an exception)" << std::endl;

    try {
        Form document(name, HIGEST_GRADE - 1, HIGEST_GRADE);
    } 
    catch (std::exception &e){
        std::cout << "EXCEPTION: " << e.what() << std::endl;
    }

    std::cout << "\t (Also should throw an exception)" << std::endl;

    try {
        Form document(name, LOWEST_GRADE + 1, HIGEST_GRADE);
    } 
    catch (std::exception &e){
        std::cout << "EXCEPTION: " << e.what() << std::endl;
    }

    std::cout << "____|           End of test          |__" << std::endl;
    std::cout << "\n||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
}

void testOverloadInsertionForm( std::string name )
{
    std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||\n" << std::endl;
    std::cout << "____| Test  Form Overload << |__" << std::endl;

    Form document(name, 3, HIGEST_GRADE);

    std::cout << document << std::endl;
    
    std::cout << "____|         End of test          |__" << std::endl;
    std::cout << "\n||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
}

void testFormBeSignMethodQualifiedBureaucrat( void )
{
    std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||\n" << std::endl;
    std::cout << "____| Test beSing Method (Form) with Qualified Bureaucrat   |__" << std::endl;
    std::cout << "\t (No output means its working properly)" << std::endl;

    Form document("Itau Admission", LOWEST_GRADE, HIGEST_GRADE);
    Bureaucrat employee("Augusto", 39);

    try {
        document.beSigned(employee);
    }
    catch (std::exception &e){
        std::cout << "EXCEPTION: " << e.what() << std::endl;
    }

    std::cout << "\t verify if it was sign (it should) : " << std::boolalpha << document.getIsSigned() << std::endl;
    std::cout << "____|                       End of test                     |__" << std::endl;
    std::cout << "\n||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
}

void testFormBeSignMethodUnqualifiedBureaucrat( void )
{
    std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||\n" << std::endl;
    std::cout << "____| Test beSing Method (Form) with Unqualified Bureaucrat  |__" << std::endl;
    std::cout << "\t (should throw an exception)" << std::endl;

    Form document("Itau Admission", 39, HIGEST_GRADE);
    Bureaucrat employee("Augusto", 100);

    try {
        document.beSigned(employee);
    }
    catch (std::exception &e){
        std::cout << "EXCEPTION: " << e.what() << std::endl;
    }

    std::cout << "\t verify if it was sign (should not) : " << std::boolalpha << document.getIsSigned() << std::endl;
    std::cout << "____|                     End of test                        |__" << std::endl;
    std::cout << "\n||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
}

void testBureaucratSignFormMethodBeingQualified( void )
{
    std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||\n" << std::endl;
    std::cout << "____| Test signForm Method (Bureaucrat) being Qualified   |__" << std::endl;
    std::cout << "\t (No output means its working properly)" << std::endl;

    Form document("Itau Admission", 99, HIGEST_GRADE);
    Bureaucrat employee("Augusto", 91);

    employee.signForm(document);

    std::cout << "\t verify if it was sign (it should) : " << std::boolalpha << document.getIsSigned() << std::endl;
    std::cout << "____|                       End of test                     |__" << std::endl;
    std::cout << "\n||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
}

void testBureaucratSignFormMethodBeingUnqualified( void )
{
    std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||\n" << std::endl;
    std::cout << "____| Test signForm Method (Bureaucrat) being Unqualified  |__" << std::endl;
    std::cout << "\t (should throw an exception)" << std::endl;

    Form document("Image Rights Contract", HIGEST_GRADE, HIGEST_GRADE);
    Bureaucrat employee("Cristiano", 3);

    employee.signForm(document);

    std::cout << "\t verify if it was sign (should not) : " << std::boolalpha << document.getIsSigned() << std::endl;
    std::cout << "____|                     End of test                        |__" << std::endl;
    std::cout << "\n||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
}
