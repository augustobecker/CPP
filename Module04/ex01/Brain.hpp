#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{

protected:

	std::string ideas[100];

public:

	Brain( void );
	~Brain( void );

	Brain(Brain &);
	Brain& operator=(Brain &);

	std::string getIdea( const int ) const;
	bool setIdea( const int, const std::string );

};

#endif
