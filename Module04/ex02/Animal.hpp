#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class AAnimal
{

protected:

	std::string type;

public:

	virtual ~AAnimal() {};
    virtual void makeSound( void ) const = 0;

};

#endif
