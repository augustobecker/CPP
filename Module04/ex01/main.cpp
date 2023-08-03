# include <iostream>
# include "Animal.hpp"
# include "Cat.hpp"
# include "Dog.hpp"
# include "Brain.hpp"

void subjectTests( void );
void brainTests( void );

int main( void )
{
    subjectTests();
    std::cout << "__________________________________________" << std::endl;
    brainTests();
    std::cout << "__________________________________________" << std::endl;
}

void subjectTests( void )
{
	std::cout << "_________| Subject Tests |__________" << std::endl;

    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;

    return ;
}

void brainTests( void )
{
	std::cout << "_________| Brain Tests |__________" << std::endl;

    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    Dog michael;
    std::cout << "Dog has an idea: " << michael.getIdea(21) << std::endl;
    std::cout << "Dog has an idea: " << michael.getIdea(77) << std::endl;
    delete dog;
    delete cat;

    return ;
}