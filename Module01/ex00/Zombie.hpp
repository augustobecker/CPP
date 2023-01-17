/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:31:21 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/17 19:09:24 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{

private:

	std::string _name;

public:

	Zombie( std::string name );
	~Zombie( void );

	Zombie* newZombie( std::string name );
	void	randomChump( std::string name );

	void    announce( void );

};

#endif
