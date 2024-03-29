#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"

class Cat: public Animal
{

private:

    std::string type;

public:

	Cat( void );
	~Cat( void );

	Cat(Cat &);
	Cat& operator=(Cat &);

    std::string getType( void ) const;

    void makeSound( void ) const;

};

#endif