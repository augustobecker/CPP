# include <iostream>
# include "Animal.hpp"
# include "Cat.hpp"
# include "Dog.hpp"
# include "Brain.hpp"

void subjectTests( void );
void brainTests( void );
void deepCopyTestsDog( void );
void deepCopyTestsCat( void );
void deepCopyConstructorTestsDog( void );
void deepCopyConstructorTestsCat( void );
void subjectExtraTests( void );

int main( void )
{
    subjectTests();
    std::cout << "__________________________________________" << std::endl;
    brainTests();
    std::cout << "__________________________________________" << std::endl;
    deepCopyTestsDog();
    std::cout << "__________________________________________" << std::endl;
    deepCopyTestsCat();
    std::cout << "__________________________________________" << std::endl;
    deepCopyConstructorTestsDog();
    std::cout << "__________________________________________" << std::endl;
    deepCopyConstructorTestsCat();
    std::cout << "__________________________________________" << std::endl;
    subjectExtraTests();
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

    Dog michael;
    Cat douglas;

    std::cout << "Dog has an idea: " << michael.getIdea() << std::endl;
    std::cout << "Cat has an idea: " << douglas.getIdea() << std::endl;
}

void deepCopyTestsDog( void )
{
    std::cout << "_________| Deep Copy Tests Dog |__________" << std::endl;

    Dog michael;
    Dog douglas;

    std::cout << "||||||||||||| Michael Ideas |||||||||||||" << std::endl;
    michael.displayIdeas();
    std::cout << "||||||||||||| Douglas Ideas |||||||||||||" << std::endl;
    douglas.displayIdeas();
    std::cout << "||||||||||||| Michael New Inverted Ideas |||||||||||||" << std::endl;
    michael.invertIdeas();
    michael.displayIdeas();
    std::cout << "||||||||||||| Deep Copying Michael to Douglas |||||||||||||" << std::endl;
    douglas = michael;
    std::cout << "||||||||||||| Douglas Ideas after DeepCopy |||||||||||||" << std::endl;
    douglas.displayIdeas();
    std::cout << "||||||||||||||||||||||||||" << std::endl;
}

void deepCopyTestsCat( void )
{
    std::cout << "_________| Deep Copy Tests Cat |__________" << std::endl;

    Cat michael;
    Cat douglas;

    std::cout << "||||||||||||| Michael Ideas |||||||||||||" << std::endl;
    michael.displayIdeas();
    std::cout << "||||||||||||| Douglas Ideas |||||||||||||" << std::endl;
    douglas.displayIdeas();
    std::cout << "||||||||||||| Michael New Inverted Ideas |||||||||||||" << std::endl;
    michael.invertIdeas();
    michael.displayIdeas();
    std::cout << "||||||||||||| Deep Copying Michael to Douglas |||||||||||||" << std::endl;
    douglas = michael;
    std::cout << "||||||||||||| Douglas Ideas after DeepCopy |||||||||||||" << std::endl;
    douglas.displayIdeas();
    std::cout << "||||||||||||||||||||||||||" << std::endl;
}

void deepCopyConstructorTestsDog( void )
{
    std::cout << "_________| Deep Copy Constructor Tests Dog |__________" << std::endl;

    Dog michael;

    std::cout << "||||||||||||| Michael Ideas |||||||||||||" << std::endl;
    michael.displayIdeas();
    std::cout << "||||||||||||| Michael New Inverted Ideas |||||||||||||" << std::endl;
    michael.invertIdeas();
    michael.displayIdeas();
    std::cout << "||||||||||||| Deep Copy Constructor Michael to Douglas |||||||||||||" << std::endl;
    Dog douglas = michael;
    std::cout << "||||||||||||| Douglas Ideas after DeepCopy |||||||||||||" << std::endl;
    douglas.displayIdeas();
    std::cout << "||||||||||||||||||||||||||" << std::endl;
}

void deepCopyConstructorTestsCat( void )
{
    std::cout << "_________| Deep Copy Constructor Tests Cat |__________" << std::endl;

    Cat michael;

    std::cout << "||||||||||||| Michael Ideas |||||||||||||" << std::endl;
    michael.displayIdeas();
    std::cout << "||||||||||||| Michael New Inverted Ideas |||||||||||||" << std::endl;
    michael.invertIdeas();
    michael.displayIdeas();
    std::cout << "||||||||||||| Deep Copy Constructor Michael to Douglas |||||||||||||" << std::endl;
    Cat douglas = michael;
    std::cout << "||||||||||||| Douglas Ideas after DeepCopy |||||||||||||" << std::endl;
    douglas.displayIdeas();
    std::cout << "||||||||||||||||||||||||||" << std::endl;
}

void subjectExtraTests( void )
{
	std::cout << "_________| Subject Extra Tests |__________" << std::endl;

    Animal *animals[10];

    for (int i = 0; i < 10; ++i) 
    {
        if (i % 2 == 0)
            animals[i] = new Cat();
        else
            animals[i] = new Dog();
        std::cout << "+++++++++++++++" << std::endl;
    }

    std::cout << "||||||||||||| Destructor |||||||||||||" << std::endl;

    for (int i = 0; i < 10; ++i) 
    {
        delete animals[i];
        std::cout << "+++++++++++++++" << std::endl;
    }

    return ;
}