#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"

class Dog: public Animal
{

private:

    std::string type;

public:

	Dog( void );
	~Dog( void );

	Dog(Dog &);
	Dog& operator=(Dog &);

    std::string getType( void ) const;

    void makeSound( void ) const;

};

#endif