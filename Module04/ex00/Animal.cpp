# include "Animal.hpp"

Animal::Animal( void )
{
    this->type = "Default";
    std::cout << "Animal " << this->type << " Constructor called" << std::endl;
}

Animal::~Animal( void )
{
    std::cout << "Animal " << this->type << " Destructor called" << std::endl;
}

Animal::Animal(Animal &obj)
{
    this->type = obj.getType();
    std::cout << "Animal " << this->type << " Copy Constructor called" << std::endl;
}

Animal& Animal::operator=(Animal &toCopyFrom)
{
    std::cout << "Animal " << this->type << " Copy Assign Operator called" << std::endl;
    if (this != &toCopyFrom)
        this->type = toCopyFrom.getType();
    return (*this);
}

std::string Animal::getType( void ) const
{
    return (this->type);
}

void Animal::makeSound( void ) const
{
    std::cout << "Animal make sound: ¨¨¨¨¨¨¨¨¨ (unrecognizable noise)" << std::endl;
}
