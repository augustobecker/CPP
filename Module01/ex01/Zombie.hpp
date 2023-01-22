/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:18:48 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/18 01:00:41 by acesar-l         ###   ########.fr       */
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

	void    announce( void );
    void    define_name( std::string name );

	Zombie( void );

};


#endif