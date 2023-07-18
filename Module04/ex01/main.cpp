# include <iostream>
# include "Animal.hpp"
# include "Cat.hpp"
# include "Dog.hpp"
# include "WrongAnimal.hpp"
# include "WrongCat.hpp"

void subjectTests( void );
void wrongAnimalTests( void );

int main( void )
{
    subjectTests();
    std::cout << "__________________________________________" << std::endl;
    wrongAnimalTests();
    std::cout << "__________________________________________" << std::endl;
}

void subjectTests( void )
{
	std::cout << "_________| Subject Tests |__________" << std::endl;
	const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;

    return ;
}

void wrongAnimalTests( void )
{
	std::cout << "_________| Wrong Animal Tests |__________" << std::endl;
	const WrongAnimal* meta = new WrongAnimal();
    const WrongAnimal* i = new WrongCat();

    std::cout << meta->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound();
    meta->makeSound();

    delete meta;
    delete i;

    return ;
}