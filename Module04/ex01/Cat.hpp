#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
private:

    std::string type;
	Brain		*brain;

public:

	Cat( void );
	~Cat( void );

	Cat(Cat &);
	Cat& operator=(Cat &);

    std::string getType( void ) const;

    void 		makeSound( void ) const;

	std::string getIdea( void ) const;
	void		displayIdeas( void ) const;
	void		invertIdeas( void );

};

#endif