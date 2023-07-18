#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <iostream>

class WrongAnimal
{

protected:

	std::string type;

public:

	WrongAnimal( void );
	virtual ~WrongAnimal( void );

	WrongAnimal(WrongAnimal &);
	WrongAnimal& operator=(WrongAnimal &);

    virtual std::string getType( void ) const;

    virtual void makeSound( void ) const;

};

#endif
