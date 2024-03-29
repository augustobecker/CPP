#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
{

private:
    std::string type;
	Brain		*brain;

public:

	Dog( void );
	~Dog( void );

	Dog(Dog &);
	Dog& operator=(Dog &);

    std::string getType( void ) const;

    void 		makeSound( void ) const;

	std::string getIdea( void ) const;
	void		displayIdeas( void ) const;
	void		invertIdeas( void );

};

#endif