/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:15:30 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/22 20:22:47 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main( void )
{
	Harl	debugger;

	debugger.complain("INFO");
    debugger.complain("WARNING");
    debugger.complain("DEBUG");
    debugger.complain("ERROR");
    debugger.complain("DEBUGGING");
}
