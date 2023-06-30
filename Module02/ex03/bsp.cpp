/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 21:24:11 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/30 21:45:50 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"
# include "Point.hpp"
# include <iostream>
# include <cmath>

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    if (a.getPositionX() > b.getPositionX())
        return (true);
    if (c.getPositionX() > point.getPositionX())
        return (true);
    return (false);
}
