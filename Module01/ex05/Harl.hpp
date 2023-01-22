/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:15:05 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/22 20:15:18 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

#define OPTIONS_NUM         5

class Harl
{
private:

	void debug( void );
	void info( void );
	void warning( void );
	void error( void );

public:

	void complain( std::string );

};

#endif