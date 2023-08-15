# include "Cat.hpp"

Cat::Cat( void ) : Animal()
{
    this->type = "Cat";
    std::cout << "Cat " << this->type << " Constructor called" << std::endl;
}

Cat::~Cat( void )
{
    std::cout << "Cat " << this->type << " Destructor called" << std::endl;
}

Cat::Cat(Cat &obj) : Animal()
{
    std::cout << "Cat " << this->type << " Copy Constructor called" << std::endl;
    *this = obj;
}

Cat& Cat::operator=(Cat &toCopyFrom)
{
    std::cout << "Cat " << this->type << " Copy Assign Operator called" << std::endl;
    if (this != &toCopyFrom)
        this->type = toCopyFrom.getType();
    return (*this);
}

std::string Cat::getType( void ) const
{
    return (this->type);
}

void Cat::makeSound( void ) const
{
    std::cout << "Cat make sound: meow meowWWW" << std::endl;
}
