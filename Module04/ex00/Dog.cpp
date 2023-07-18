# include "Dog.hpp"

Dog::Dog( void ) : Animal()
{
    type = "Dog";
    std::cout << "Dog " << type << " Constructor called" << std::endl;
}

Dog::~Dog( void )
{
    std::cout << "Dog " << type << " Destructor called" << std::endl;
}

Dog::Dog(Dog &obj) : Animal()
{
    std::cout << "Dog " << type << " Copy Constructor called" << std::endl;
    *this = obj;
}

Dog& Dog::operator=(Dog &toCopyFrom)
{
    std::cout << "Dog " << type << " Copy Assign Operator called" << std::endl;
    if (this != &toCopyFrom)
        type = toCopyFrom.getType();
    return (*this);
}

std::string Dog::getType( void ) const
{
    return (type);
}

void Dog::makeSound( void ) const
{
    std::cout << "Dog make sound: ruFF RUFF" << std::endl;
}
