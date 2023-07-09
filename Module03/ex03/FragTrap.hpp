#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{

public:

	FragTrap( std::string );
	~FragTrap( void );

	FragTrap(FragTrap &);
	FragTrap& operator=(FragTrap &);

	void highFivesGuys( void );

};

#endif
