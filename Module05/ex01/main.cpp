# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"
# include "Form.hpp"

# define HIGEST_GRADE   1
# define LOWEST_GRADE   150

void testCreateValidForm( std::string name );
void testCreateInvalidForm( std::string name );

void testOverloadInsertionForm( std::string name );

void testFormBeSignMethodQualifiedBureaucrat( void );
void testFormBeSignMethodUnqualifiedBureaucrat( void );

void testBureaucratSignFormMethodBeingQualified( void );
void testBureaucratSignFormMethodBeingUnqualified( void );

void testSignAlreadySignedForm( void );

int main( void )
{
    testCreateValidForm("Entry");
    testCreateInvalidForm("42 Admission");

    testOverloadInsertionForm("Socio Avanti Admission");

    testFormBeSignMethodQualifiedBureaucrat();
    testFormBeSignMethodUnqualifiedBureaucrat();

    testBureaucratSignFormMethodBeingQualified();
    testBureaucratSignFormMethodBeingUnqualified();

    testSignAlreadySignedForm();
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
    std::cout << "\t (should sign the form)" << std::endl;

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
    std::cout << "\t (should sign the form)" << std::endl;

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


void testSignAlreadySignedForm( void )
{
    std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||\n" << std::endl;
    std::cout << "____| Test Sign Already Signed Form   |__" << std::endl;
    std::cout << "\t (should sign the form)" << std::endl;

    Form document("Itau Admission", 99, HIGEST_GRADE);
    Bureaucrat employee("Augusto", 1);

    employee.signForm(document);

    std::cout << "\t verify if it was sign (it should) : " << std::boolalpha << document.getIsSigned() << std::endl;

    try {
        employee.signForm(document);
    } catch (std::exception &e){
        std::cout << "EXCEPTION: " << e.what() << std::endl;
    }

    std::cout << "\t verify if it was sign (it should) : " << std::boolalpha << document.getIsSigned() << std::endl;
    
    std::cout << "____|                       End of test                     |__" << std::endl;
    std::cout << "\n||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
}