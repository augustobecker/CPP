/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 21:03:00 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/30 22:14:04 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"
# include "Point.hpp"
# include <iostream>
# include <cmath>

bool	bsp( Point const a, Point const b, Point const c, Point const point);

int main (void)
{
	Fixed xVertexA(5), yVertexA(5);
	Fixed xVertexB(15), yVertexB(15);
	Fixed xVertexC(12), yVertexC(2);
	Fixed xFind(6), yFind(8);

	Point vertexA(xVertexA, yVertexA);
	Point vertexB(xVertexB, yVertexB);
	Point vertexC(xVertexC, yVertexC);
	Point toFind(xFind, yFind);
	
	std::cout << "Is the Point inside of the Triangle?" << std::endl;
	if (bsp(vertexA, vertexB, vertexC, toFind))
		std::cout << "Yes";
	else
		std::cout << "Else";
	std::cout << std::endl;
	return (0);
}