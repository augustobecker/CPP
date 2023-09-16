# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"

# define HIGEST_GRADE   1

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
    testCreateShrubberyCreationForm("Dudu");
    testCreateRobotomyRequestForm("Richard Ríos");
    testCreatePresidentialPardonForm("Endrick");

    testExecuteShrubberyCreationFormWithUnqualifiedBureaucrat("Luan");
    testExecuteRobotomyRequestFormWithUnqualifiedBureaucrat("Marcos Rocha");
    testExecutePresidentialPardonFormWithUnqualifiedBureaucrat("Murilo");

    testExecuteShrubberyCreationFormBeeingUnsigned("Flaco Lópezl");
    testExecuteRobotomyRequestFormBeeingUnsigned("Piquerez");
    testExecutePresidentialPardonFormBeeingUnsigned("John John");

    testExecuteShrubberyCreationFormWithQualifiedBureaucrat("Piquerez");
    testExecuteRobotomyRequestFormWithQualifiedBureaucrat("Gustavo Gómez");
    testExecutePresidentialPardonFormWithQualifiedBureaucrat("Weverton");

}

void testCreateShrubberyCreationForm( std::string name )
{
    std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||\n" << std::endl;
    std::cout << "____| Test Create ShrubberyCreationForm   |__" << std::endl;
    std::cout << "\t (No output means its working properly)" << std::endl;

    try {
        AForm *document = new ShrubberyCreationForm(name);

        document->getTarget();

        delete document;
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
        AForm *document = new PresidentialPardonForm(name);

        document->getTarget();

        delete document;
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
        AForm *document = new RobotomyRequestForm(name);

        document->getTarget();

        delete document;
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

    Bureaucrat random("Daniel", HIGEST_GRADE);
    AForm *document = new ShrubberyCreationForm(name);
    
    random.signForm(*document);
    random.executeForm(*document);

    delete document;
    
    std::cout << "____|         End of test          |__" << std::endl;
    std::cout << "\n||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
}

void testExecutePresidentialPardonFormWithQualifiedBureaucrat( std::string name )
{
    std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||\n" << std::endl;
    std::cout << "____| Test Execute PresidentialPardonForm with Qualified Bureaucrat   |__" << std::endl;
    std::cout << "\t (it should print that form has been signed, executed and its execution )" << std::endl;

    Bureaucrat  random("Daniel", HIGEST_GRADE);
    AForm *document = new PresidentialPardonForm(name);
    
    random.signForm(*document);
    random.executeForm(*document);

    delete document;

    std::cout << "____|         End of test          |__" << std::endl;
    std::cout << "\n||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
}

void testExecuteRobotomyRequestFormWithQualifiedBureaucrat( std::string name )
{
    std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||\n" << std::endl;
    std::cout << "____| Test Execute RobotomyRequestForm with Qualified Bureaucrat  |__" << std::endl;
    std::cout << "\t (it should print that form has been signed, executed and its execution )" << std::endl;

    Bureaucrat random("Daniel", 1);
    AForm *document = new RobotomyRequestForm(name);
    
    random.signForm(*document);
    random.executeForm(*document);

    delete document;

    std::cout << "____|         End of test          |__" << std::endl;
    std::cout << "\n||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
}

void testExecuteShrubberyCreationFormWithUnqualifiedBureaucrat( std::string name )
{
    std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||\n" << std::endl;
    std::cout << "____| Test Execute ShrubberyCreationForm with Unqualified Bureaucrat   |__" << std::endl;
    std::cout << "\t (it should print that form has been signed, and throw an exception when trying to execute )" << std::endl;

    Bureaucrat random("Daniel", 138);
    AForm *document = new ShrubberyCreationForm(name);
    
    random.signForm(*document);
    random.executeForm(*document);

    delete document;
    
    std::cout << "____|         End of test          |__" << std::endl;
    std::cout << "\n||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
}

void testExecutePresidentialPardonFormWithUnqualifiedBureaucrat( std::string name )
{
    std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||\n" << std::endl;
    std::cout << "____| Test Execute PresidentialPardonForm with Unqualified Bureaucrat   |__" << std::endl;
    std::cout << "\t (it should print that form has been signed, and throw an exception when trying to execute )" << std::endl;

    Bureaucrat  random("Daniel", 6);
    AForm *document = new PresidentialPardonForm(name);
    
    random.signForm(*document);
    random.executeForm(*document);

    delete document;

    std::cout << "____|         End of test          |__" << std::endl;
    std::cout << "\n||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
}

void testExecuteRobotomyRequestFormWithUnqualifiedBureaucrat( std::string name )
{
    std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||\n" << std::endl;
    std::cout << "____| Test Execute RobotomyRequestForm with Unqualified Bureaucrat  |__" << std::endl;
    std::cout << "\t (it should print that form has been signed, and throw an exception when trying to execute )" << std::endl;

    Bureaucrat random("Daniel", 46);
    AForm *document = new RobotomyRequestForm(name);
    
    random.signForm(*document);
    random.executeForm(*document);

    delete document;

    std::cout << "____|         End of test          |__" << std::endl;
    std::cout << "\n||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
}

void testExecuteShrubberyCreationFormBeeingUnsigned( std::string name )
{
    std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||\n" << std::endl;
    std::cout << "____| Test Execute ShrubberyCreationForm Beeing Unsigned   |__" << std::endl;
    std::cout << "\t (it should throw an exeception)" << std::endl;

    Bureaucrat random("Daniel", 138);
    AForm *document = new ShrubberyCreationForm(name);

    random.executeForm(*document);

    delete document;
    
    std::cout << "____|         End of test          |__" << std::endl;
    std::cout << "\n||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
}

void testExecutePresidentialPardonFormBeeingUnsigned( std::string name )
{
    std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||\n" << std::endl;
    std::cout << "____| Test Execute PresidentialPardonForm Beeing Unsigned   |__" << std::endl;
    std::cout << "\t (it should throw should an exeception)" << std::endl;

    Bureaucrat  random("Daniel", 6);
    AForm *document = new PresidentialPardonForm(name);
    
    random.executeForm(*document);

    delete document;

    std::cout << "____|         End of test          |__" << std::endl;
    std::cout << "\n||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
}

void testExecuteRobotomyRequestFormBeeingUnsigned( std::string name )
{
    std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||\n" << std::endl;
    std::cout << "____| Test Execute RobotomyRequestForm Beeing Unsigned  |__" << std::endl;
    std::cout << "\t (it should throw should an exeception)" << std::endl;

    Bureaucrat random("Daniel", 46);
    AForm *document = new RobotomyRequestForm(name);
    
    random.executeForm(*document);

    delete document;

    std::cout << "____|         End of test          |__" << std::endl;
    std::cout << "\n||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
}
