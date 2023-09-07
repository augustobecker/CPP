# include "Animal.hpp"
Animal::Animal( void )
{
    type = "Default";
    std::cout << "Animal " << type << " Constructor called" << std::endl;
}

Animal::~Animal( void )
{
    std::cout << "Animal " << type << " Destructor called" << std::endl;
}

Animal::Animal(Animal &obj)
{
    type = obj.getType();
    std::cout << "Animal " << type << " Copy Constructor called" << std::endl;
}

Animal& Animal::operator=(Animal &toCopyFrom)
{
    std::cout << "Animal " << type << " Copy Assign Operator called" << std::endl;
    if (this != &toCopyFrom)
        type = toCopyFrom.getType();
    return (*this);
}

std::string Animal::getType( void ) const
{
    return (type);
}
