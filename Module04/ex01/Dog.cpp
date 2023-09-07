# include "Dog.hpp"

Dog::Dog( void ) : Animal()
{
    this->type = "Dog";
    std::cout << "Dog " << this->type << " Constructor called" << std::endl;
    this->brain = new Brain();
}

Dog::~Dog( void )
{
    delete this->brain;
    std::cout << "Dog " << this->type << " Destructor called" << std::endl;
}

Dog::Dog(Dog &obj) : Animal()
{
    std::cout << "Dog " << this->type << " Copy Constructor called" << std::endl;
    type = obj.getType();
    brain = new Brain(*obj.brain);
}

Dog& Dog::operator=(Dog &toCopyFrom)
{
    std::cout << "Dog " << this->type << " Copy Assign Operator called" << std::endl;
    if (this != &toCopyFrom)
    {
        type = toCopyFrom.getType();
        delete brain;
        brain = new Brain(*toCopyFrom.brain);
    }
    return (*this);
}

std::string Dog::getType( void ) const
{
    return (this->type);
}

void Dog::makeSound( void ) const
{
    std::cout << "Dog make sound: ruFF RUFF" << std::endl;
}

std::string Dog::getIdea( void ) const
{
    return(this->brain->getRandomIdea());
}

void Dog::displayIdeas( void ) const
{
    return(this->brain->displayIdeas());
}

void Dog::invertIdeas( void )
{
    return(this->brain->invertIdeas());
}

