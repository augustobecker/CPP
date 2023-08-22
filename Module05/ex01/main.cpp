# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"
# include "Form.hpp"

int main( void )
{
    Form admission("admission", 30, 6);
    Form entry("entry", 100, 6);
    Bureaucrat Augusto("Augusto", 40);

    admission.beSigned(Augusto);
    Augusto.signForm(admission);
    Augusto.signForm(entry);
    std::cout << admission << std::endl;
    return 0;
}
