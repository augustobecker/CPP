/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 03:36:01 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/28 16:51:22 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <stdlib.h>

#define OPTIONS_NUM         5

enum Level
{
    INSIGNIFICANT,
    DEBUG,
    INFO,
    WARNING,
    ERROR
};

class Harl
{
    
private:

    Level   _complainLevel;

    void    insignificant( void );
	void    debug( void );
	void    info( void );
	void    warning( void );
	void    error( void );

public:
    
    typedef void (Harl::*ComplainFunction)( void );

    Harl( int argc, char **argv );
    ~Harl( void );
    
    Level   getComplainLevel(void);
    void    setComplainLevel(Level);
    void    setComplainLevel(std::string);

	void complain( void );

};

#endif