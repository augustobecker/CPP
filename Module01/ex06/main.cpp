/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 03:36:21 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/23 04:09:07 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

t_level  get_complain_level( std::string complain );

int	main( int argc, char **argv )
{
	Harl	debugger;
	t_level complaining;

	if (argc != 2)
		return (1);
	complaining = get_complain_level(argv[1]);
	debugger.complain(complaining);
}

t_level  get_complain_level( std::string complain )
{
	if (!complain.compare("DEBUG"))
		return (DEBUG);
	else if (!complain.compare("INFO"))
		return (INFO);
	else if (!complain.compare("WARNING"))
		return (WARNING);
	else if (!complain.compare("ERROR"))
		return (ERROR);
	else
		return (INSIGNIFICANT);
}