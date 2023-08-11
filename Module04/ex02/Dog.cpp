# include "Dog.hpp"

Dog::Dog( void ) : AAnimal()
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

Dog::Dog(Dog &obj) : AAnimal()
{
    std::cout << "Dog " << this->type << " Copy Constructor called" << std::endl;
    *this = obj;
}

Dog& Dog::operator=(Dog &toCopyFrom)
{
    std::cout << "Dog " << this->type << " Copy Assign Operator called" << std::endl;
    if (this != &toCopyFrom)
        type = toCopyFrom.getType();
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

std::string Dog::getIdea( const int numIdea ) const
{
    return(this->brain->getIdea(numIdea));
}
