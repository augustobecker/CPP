#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{

private:

    std::string type;

public:

	WrongCat( void );
	~WrongCat( void );

	WrongCat(WrongCat &);
	WrongCat& operator=(WrongCat &);

    std::string getType( void ) const;

    void makeSound( void ) const;

};

#endif