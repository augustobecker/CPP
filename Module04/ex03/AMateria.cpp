# include "AMateria.hpp"

AMateria::AMateria( void ) : AAnimal()
{
    this->_type = "AMateria";
    std::cout << "AMateria " << this->type << " Constructor called" << std::endl;
}

AMateria::~AMateria( void )
{
    std::cout << "AMateria " << this->type << " Destructor called" << std::endl;
}

AMateria::AMateria(AMateria &obj) : AAnimal()
{
    std::cout << "AMateria " << this->type << " Copy Constructor called" << std::endl;
    *this= obj;
}

AMateria& AMateria::operator=(AMateria &toCopyFrom)
{
    std::cout << "AMateria " << this->type << " Copy Assign Operator called" << std::endl;
    if (this != &toCopyFrom)
        this->type = toCopyFrom.getType();
    return (*this);
}

std::string const & AMateria::getType( void ) const
{
    return (this->_type);
}

void AMateria::makeSound( void ) const
{
    std::cout << "AMateria make sound: meow meowWWW" << std::endl;
}
