# include <iostream>
# include "Animal.hpp"
# include "Cat.hpp"
# include "Dog.hpp"
# include "Brain.hpp"

void subjectTests( void );

int main( void )
{
    subjectTests();
    std::cout << "__________________________________________" << std::endl;
}

void subjectTests( void )
{
	std::cout << "_________| Subject Tests |__________" << std::endl;
	//const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    //meta->makeSound();

    //delete meta;
    delete j;
    delete i;

    return ;
}
