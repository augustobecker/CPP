# include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void )
{
    type = "Default";
    std::cout << "WrongAnimal " << type << " Constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal( void )
{
    std::cout << "WrongAnimal " << type << " Destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal &obj)
{
    type = obj.getType();
    std::cout << "WrongAnimal " << type << " Copy Constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal &toCopyFrom)
{
    std::cout << "WrongAnimal " << type << " Copy Assign Operator called" << std::endl;
    if (this != &toCopyFrom)
        type = toCopyFrom.getType();
    return (*this);
}

std::string WrongAnimal::getType( void ) const
{
    return (type);
}

void WrongAnimal::makeSound( void ) const
{
    std::cout << "WrongAnimal make sound: ~~~~~.~~~~~~. (unidentified sound)" << std::endl;
}
