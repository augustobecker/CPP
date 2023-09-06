# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"

# define HIGEST_GRADE   1
# define LOWEST_GRADE   150

void testCreateValidBureaucrat( std::string name );
void testCreateInvalidBureaucrat( std::string name );

void testOverloadInsertionBureaucrat( std::string name );

void testIncrementGrade( std::string name );
void testDecrementGrade( std::string name );

void testCreateShrubberyCreationForm( std::string name );
void testCreateRobotomyRequestForm( std::string name );
void testCreatePresidentialPardonForm( std::string name );

void testExecuteShrubberyCreationFormWithQualifiedBureaucrat( std::string name );
void testExecuteRobotomyRequestFormWithQualifiedBureaucrat( std::string name );
void testExecutePresidentialPardonFormWithQualifiedBureaucrat( std::string name );

void testExecuteShrubberyCreationFormWithUnqualifiedBureaucrat( std::string name );
void testExecuteRobotomyRequestFormWithUnqualifiedBureaucrat( std::string name );
void testExecutePresidentialPardonFormWithUnqualifiedBureaucrat( std::string name );

void testExecuteShrubberyCreationFormBeeingUnsigned( std::string name );
void testExecuteRobotomyRequestFormBeeingUnsigned( std::string name );
void testExecutePresidentialPardonFormBeeingUnsigned( std::string name );

int main( void )
{
    testCreateValidBureaucrat("Amanda");
    testCreateInvalidBureaucrat("Naty");

    testOverloadInsertionBureaucrat("Abel Ferreira");

    testIncrementGrade("Rony Rustico");
    testDecrementGrade("Raphael Veiga");

    testCreateShrubberyCreationForm("Dudu");
    testCreateRobotomyRequestForm("Richard Ríos");
    testCreatePresidentialPardonForm("Endrick");


    testExecuteShrubberyCreationFormWithUnqualifiedBureaucrat("Luan");
    testExecuteRobotomyRequestFormWithUnqualifiedBureaucrat("Marcos Rocha");
    testExecutePresidentialPardonFormWithUnqualifiedBureaucrat("Murilo");

    testExecuteShrubberyCreationFormWithQualifiedBureaucrat("Flaco López");
    testExecuteRobotomyRequestFormWithQualifiedBureaucrat("Gustavo Gómez");
    testExecutePresidentialPardonFormWithQualifiedBureaucrat("Weverton");
    
    testExecuteShrubberyCreationFormBeeingUnsigned("Zé Rafael");
    testExecuteRobotomyRequestFormBeeingUnsigned("Piquerez");
    testExecutePresidentialPardonFormBeeingUnsigned("John John");
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

void testCreateShrubberyCreationForm( std::string name )
{
    std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||\n" << std::endl;
    std::cout << "____| Test Create ShrubberyCreationForm   |__" << std::endl;
    std::cout << "\t (No output means its working properly)" << std::endl;

    try {
        Form *document = new ShrubberyCreationForm(name);

        document->getTarget();
    }
    catch (std::exception &e){
        std::cout << "EXCEPTION: " << e.what() << std::endl;
    }

    std::cout << "____|         End of test          |__" << std::endl;
    std::cout << "\n||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
}

void testCreatePresidentialPardonForm( std::string name )
{
    std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||\n" << std::endl;
    std::cout << "____| Test Create PresidentialPardonForm   |__" << std::endl;
    std::cout << "\t (No output means its working properly)" << std::endl;

    try {
        Form *document = new PresidentialPardonForm(name);

        document->getTarget();
    }
    catch (std::exception &e){
        std::cout << "EXCEPTION: " << e.what() << std::endl;
    }

    std::cout << "____|         End of test          |__" << std::endl;
    std::cout << "\n||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
}

void testCreateRobotomyRequestForm( std::string name )
{
    std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||\n" << std::endl;
    std::cout << "____| Test Create RobotomyRequestForm   |__" << std::endl;
    std::cout << "\t (No output means its working properly)" << std::endl;

    try {
        Form *document = new RobotomyRequestForm(name);

        document->getTarget();
    }
    catch (std::exception &e){
        std::cout << "EXCEPTION: " << e.what() << std::endl;
    }

    std::cout << "____|         End of test          |__" << std::endl;
    std::cout << "\n||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
}

void testExecuteShrubberyCreationFormWithQualifiedBureaucrat( std::string name )
{
    std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||\n" << std::endl;
    std::cout << "____| Test Execute ShrubberyCreationForm with Qualified Bureaucrat   |__" << std::endl;
    std::cout << "\t (it should print that form has been signed, executed and its execution )" << std::endl;

    Bureaucrat random("Daniel", 1);
    Form *document = new ShrubberyCreationForm(name);
    
    random.signForm(*document);
    random.executeForm(*document);
    
    std::cout << "____|         End of test          |__" << std::endl;
    std::cout << "\n||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
}

void testExecutePresidentialPardonFormWithQualifiedBureaucrat( std::string name )
{
    std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||\n" << std::endl;
    std::cout << "____| Test Execute PresidentialPardonForm with Qualified Bureaucrat   |__" << std::endl;
    std::cout << "\t (it should print that form has been signed, executed and its execution )" << std::endl;

    Bureaucrat  random("Daniel", 1);
    Form *document = new PresidentialPardonForm(name);
    
    random.signForm(*document);
    random.executeForm(*document);

    std::cout << "____|         End of test          |__" << std::endl;
    std::cout << "\n||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
}

void testExecuteRobotomyRequestFormWithQualifiedBureaucrat( std::string name )
{
    std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||\n" << std::endl;
    std::cout << "____| Test Execute RobotomyRequestForm with Qualified Bureaucrat  |__" << std::endl;
    std::cout << "\t (it should print that form has been signed, executed and its execution )" << std::endl;

    Bureaucrat random("Daniel", 1);
    Form *document = new RobotomyRequestForm(name);
    
    random.signForm(*document);
    random.executeForm(*document);

    std::cout << "____|         End of test          |__" << std::endl;
    std::cout << "\n||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
}

void testExecuteShrubberyCreationFormWithUnqualifiedBureaucrat( std::string name )
{
    std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||\n" << std::endl;
    std::cout << "____| Test Execute ShrubberyCreationForm with Unqualified Bureaucrat   |__" << std::endl;
    std::cout << "\t (it should print that form has been signed, and throw an exception when trying to execute )" << std::endl;

    Bureaucrat random("Daniel", 138);
    Form *document = new ShrubberyCreationForm(name);
    
    random.signForm(*document);
    random.executeForm(*document);
    
    std::cout << "____|         End of test          |__" << std::endl;
    std::cout << "\n||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
}

void testExecutePresidentialPardonFormWithUnqualifiedBureaucrat( std::string name )
{
    std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||\n" << std::endl;
    std::cout << "____| Test Execute PresidentialPardonForm with Unqualified Bureaucrat   |__" << std::endl;
    std::cout << "\t (it should print that form has been signed, and throw an exception when trying to execute )" << std::endl;

    Bureaucrat  random("Daniel", 6);
    Form *document = new PresidentialPardonForm(name);
    
    random.signForm(*document);
    random.executeForm(*document);

    std::cout << "____|         End of test          |__" << std::endl;
    std::cout << "\n||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
}

void testExecuteRobotomyRequestFormWithUnqualifiedBureaucrat( std::string name )
{
    std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||\n" << std::endl;
    std::cout << "____| Test Execute RobotomyRequestForm with Unqualified Bureaucrat  |__" << std::endl;
    std::cout << "\t (it should print that form has been signed, and throw an exception when trying to execute )" << std::endl;

    Bureaucrat random("Daniel", 46);
    Form *document = new RobotomyRequestForm(name);
    
    random.signForm(*document);
    random.executeForm(*document);

    std::cout << "____|         End of test          |__" << std::endl;
    std::cout << "\n||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
}

void testExecuteShrubberyCreationFormBeeingUnsigned( std::string name )
{
    std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||\n" << std::endl;
    std::cout << "____| Test Execute ShrubberyCreationForm Beeing Unsigned   |__" << std::endl;
    std::cout << "\t (it should throw an exeception)" << std::endl;

    Bureaucrat random("Daniel", 138);
    Form *document = new ShrubberyCreationForm(name);

    random.executeForm(*document);
    
    std::cout << "____|         End of test          |__" << std::endl;
    std::cout << "\n||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
}

void testExecutePresidentialPardonFormBeeingUnsigned( std::string name )
{
    std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||\n" << std::endl;
    std::cout << "____| Test Execute PresidentialPardonForm Beeing Unsigned   |__" << std::endl;
    std::cout << "\t (it should throw should an exeception)" << std::endl;

    Bureaucrat  random("Daniel", 6);
    Form *document = new PresidentialPardonForm(name);
    
    random.executeForm(*document);

    std::cout << "____|         End of test          |__" << std::endl;
    std::cout << "\n||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
}

void testExecuteRobotomyRequestFormBeeingUnsigned( std::string name )
{
    std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||\n" << std::endl;
    std::cout << "____| Test Execute RobotomyRequestForm Beeing Unsigned  |__" << std::endl;
    std::cout << "\t (it should throw should an exeception)" << std::endl;

    Bureaucrat random("Daniel", 46);
    Form *document = new RobotomyRequestForm(name);
    
    random.executeForm(*document);

    std::cout << "____|         End of test          |__" << std::endl;
    std::cout << "\n||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
}
