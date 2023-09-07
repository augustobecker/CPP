#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{

protected:

	std::string type;

public:

	Animal( void );
	virtual ~Animal( void );

	Animal(Animal &);
	Animal& operator=(Animal &);

    virtual std::string getType( void ) const;

    virtual void makeSound( void ) const = 0;

};

#endif
