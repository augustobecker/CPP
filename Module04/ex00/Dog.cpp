# include "Dog.hpp"

Dog::Dog( void ) : Animal()
{
    this->type = "Dog";
    std::cout << "Dog " << this->type << " Constructor called" << std::endl;
}

Dog::~Dog( void )
{
    std::cout << "Dog " << this->type << " Destructor called" << std::endl;
}

Dog::Dog(Dog &obj) : Animal()
{
    std::cout << "Dog " << this->type << " Copy Constructor called" << std::endl;
    *this = obj;
}

Dog& Dog::operator=(Dog &toCopyFrom)
{
    std::cout << "Dog " << this->type << " Copy Assign Operator called" << std::endl;
    if (this != &toCopyFrom)
        this->type = toCopyFrom.getType();
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
