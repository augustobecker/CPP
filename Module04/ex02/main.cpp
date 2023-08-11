# include <iostream>
# include "Animal.hpp"
# include "Cat.hpp"
# include "Dog.hpp"
# include "Brain.hpp"

void brainTests( void );

int main( void )
{
    std::cout << "__________________________________________" << std::endl;
    brainTests();
    std::cout << "__________________________________________" << std::endl;
}

void brainTests( void )
{
	std::cout << "_________| Brain Tests |__________" << std::endl;
    AAnimal* jackson = new Dog;
    Dog michael;
    std::cout << "Dog has an idea: " << michael.getIdea(21) << std::endl;
    std::cout << "Dog has an idea: " << michael.getIdea(77) << std::endl;
    jackson->makeSound();
    delete &michael;
    return ;
}