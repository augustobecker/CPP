/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 03:36:01 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/23 04:05:38 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

#define OPTIONS_NUM         5

typedef enum e_level
{
    INSIGNIFICANT,
    DEBUG,
    INFO,
    WARNING,
    ERROR
}   t_level;

class Harl
{
private:

    void insignificant( void );
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );

public:

	void complain( t_level complain );

};

#endif