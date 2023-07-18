# include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal()
{
    type = "WrongCat";
    std::cout << "WrongCat " << type << " Constructor called" << std::endl;
}

WrongCat::~WrongCat( void )
{
    std::cout << "WrongCat " << type << " Destructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat &obj) : WrongAnimal()
{
    std::cout << "WrongCat " << type << " Copy Constructor called" << std::endl;
    *this= obj;
}

WrongCat& WrongCat::operator=(WrongCat &toCopyFrom)
{
    std::cout << "WrongCat " << type << " Copy Assign Operator called" << std::endl;
    if (this != &toCopyFrom)
        type = toCopyFrom.getType();
    return (*this);
}

std::string WrongCat::getType( void ) const
{
    return (type);
}

void WrongCat::makeSound( void ) const
{
    std::cout << "WrongCat make sound: yow! (definitely not a cat)" << std::endl;
}
