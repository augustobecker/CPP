# include "Cat.hpp"

Cat::Cat( void ) : Animal()
{
    this->type = "Cat";
    std::cout << "Cat " << type << " Constructor called" << std::endl;
    this->brain = new Brain();
}

Cat::~Cat( void )
{
    delete this->brain;
    std::cout << "Cat " << type << " Destructor called" << std::endl;
}

Cat::Cat(Cat &obj) : Animal()
{
    std::cout << "Cat " << type << " Copy Constructor called" << std::endl;
    type = obj.getType();
    brain = new Brain(*obj.brain);
}

Cat& Cat::operator=(Cat &toCopyFrom)
{
    std::cout << "Cat " << type << " Copy Assign Operator called" << std::endl;
    if (this != &toCopyFrom)
    {
        type = toCopyFrom.getType();
        delete brain;
        brain = new Brain(*toCopyFrom.brain);
    }
    return (*this);
}

std::string Cat::getType( void ) const
{
    return (type);
}

void Cat::makeSound( void ) const
{
    std::cout << "Cat make sound: meow meowWWW" << std::endl;
}

std::string Cat::getIdea( void ) const
{
    return(this->brain->getRandomIdea());
}

void Cat::displayIdeas( void ) const
{
    return(this->brain->displayIdeas());
}

void Cat::invertIdeas( void )
{
    return(this->brain->invertIdeas());
}
