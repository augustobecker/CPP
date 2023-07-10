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

Fixed triangleArea(Fixed x1, Fixed y1, Fixed x2, Fixed y2, Fixed x3, Fixed y3);

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed   originalTriangleArea;
    Fixed   triangleAreaABP, triangleAreaACP, triangleAreaBCP;

    originalTriangleArea = triangleArea(
            a.getPositionX(), a.getPositionY(),
            b.getPositionX(), b.getPositionY(),
            c.getPositionX(), c.getPositionY());

    triangleAreaABP = triangleArea(
            a.getPositionX(), a.getPositionY(),
            b.getPositionX(), b.getPositionY(),
            point.getPositionX(), point.getPositionY());

    triangleAreaACP = triangleArea(
            a.getPositionX(), a.getPositionY(),
            c.getPositionX(), c.getPositionY(),
            point.getPositionX(), point.getPositionY());

    triangleAreaBCP = triangleArea(
            b.getPositionX(), b.getPositionY(),
            c.getPositionX(), c.getPositionY(),
            point.getPositionX(), point.getPositionY());

    if (originalTriangleArea == (triangleAreaABP + triangleAreaACP + triangleAreaBCP))
        return (true);
    return (false);
}

Fixed triangleArea(Fixed x1, Fixed y1, Fixed x2, Fixed y2, Fixed x3, Fixed y3)
{
    Fixed Area;
    
    Area = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
    if (Area > 0)
        Area = Area * Fixed(-1);
    return (Area);
}