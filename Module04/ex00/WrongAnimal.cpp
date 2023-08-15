# include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void )
{
    this->type = "Default";
    std::cout << "WrongAnimal " << this->type << " Constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal( void )
{
    std::cout << "WrongAnimal " << this->type << " Destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal &obj)
{
    this->type = obj.getType();
    std::cout << "WrongAnimal " << this->type << " Copy Constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal &toCopyFrom)
{
    std::cout << "WrongAnimal " << this->type << " Copy Assign Operator called" << std::endl;
    if (this != &toCopyFrom)
        this->type = toCopyFrom.getType();
    return (*this);
}

std::string WrongAnimal::getType( void ) const
{
    return (this->type);
}

void WrongAnimal::makeSound( void ) const
{
    std::cout << "WrongAnimal make sound: ~~~~~.~~~~~~. (unidentified sound)" << std::endl;
}
