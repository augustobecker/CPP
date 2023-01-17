/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:21:04 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/17 21:32:35 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int	main( void )
{
	Zombie	*horde;
	int		zombies;
	int		i;

	i = 0;
	zombies = 10;
	horde = zombieHorde(zombies, "Becker");
	std::cout << "Every Zombie must announce itself:" << std::endl;
	while (i < zombies)
	{
		std::cout << "[Zombie - " << i + 1 << "]	: ";
		horde[i++].announce();
	}
	std::cout << std::endl;
	std::cout << "Redefining Zombie 5 and 6." << std::endl;
	horde[4].define_name("Carlos");
	horde[5].define_name("Andrés");
	std::cout << std::endl;
	i = 0;
	std::cout << "Every Zombie must announce itself:" << std::endl;
	while (i < zombies)
	{
		std::cout << "[Zombie - " << i + 1 << "]	: ";
		horde[i++].announce();
	}
	std::cout << std::endl;
	std::cout << "Delete horde" << std::endl;
	std::cout << std::endl;
	delete [] horde;
	return (0);
}