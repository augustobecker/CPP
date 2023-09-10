#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <cstdlib> 
# include <time.h>

class Brain
{

protected:

	std::string ideas[100];

public:

	Brain( void );
	~Brain( void );

	Brain(Brain &);
	Brain& operator=(Brain &);

	std::string	getRandomIdea( void ) const;

	std::string	getIdea( const int numIdea ) const;
	bool		setIdea( const int, const std::string );

	void invertIdeas( void );
	void displayIdeas( void ) const;

};

#endif
