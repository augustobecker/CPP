/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:26:37 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/17 21:16:26 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie	*new_z = new Zombie[N];
	int		i;
	
	i = 0;
	while (i < N)
		new_z[i++].setName(name);
	return (new_z);
}
