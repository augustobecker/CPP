# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"
# include "Intern.hpp"

# define HIGEST_GRADE   1

void testCreateFormViaIntern( const std::string formType, const std::string target);

int main( void )
{
    testCreateFormViaIntern("shrubbery creation", "Home");
    testCreateFormViaIntern("robotomy request", "Bender");
    testCreateFormViaIntern("presidential pardon", "Alex Turner");

    testCreateFormViaIntern("ShrubberyCreationform", "Mall");
    testCreateFormViaIntern("RobotomyrequestForm", "Lana");
    testCreateFormViaIntern("PresidentialpardonForm", "Justin Timberlake");
}

void testCreateFormViaIntern( const std::string formType, const std::string target)
{
    std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||\n" << std::endl;
    std::cout << "____| Test Create Form " << formType << " Via Intern and Execute it   |__" << std::endl;
    Bureaucrat someRandomBureucrat("Santos", HIGEST_GRADE);
    Intern someRandomIntern;
    AForm* randomForm;

    try {
        randomForm = someRandomIntern.makeForm(formType, target);

        someRandomBureucrat.signForm(*randomForm);
        someRandomBureucrat.executeForm(*randomForm);
    } catch (std::exception &e){
        std::cout << "EXCEPTION: " << e.what() << std::endl;
    }

    std::cout << "____|         End of test          |__" << std::endl;
    std::cout << "\n||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
}