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

# define GREEN		"\033[0;32m";
# define RED		"\033[0;31m";
# define RESET		"\033[0m";

bool	bsp( Point const a, Point const b, Point const c, Point const point);
void	bpsFailMessage( void );

bool isPointInsideTriangle(
	Fixed xVertexA, Fixed yVertexA,
	Fixed xVertexB, Fixed yVertexB,
	Fixed xVertexC, Fixed yVertexC,
	Fixed xFind,    Fixed yFind);

int main (void)
{
	//should be true
	if (!isPointInsideTriangle(
		5, 5,   15, 15,   10, 2,
		10, 8)
	)
	{
		bpsFailMessage();
		return (0);
	}

	//should be true
	if (!isPointInsideTriangle(
		-1, 5,   15, 15,   10, 2,
		6, 8)
	)
	{
		bpsFailMessage();
		return (0);
	}

	//should be false
	if (isPointInsideTriangle(
		5, 5,   15, 15,   10, 2,
		6, 8)
	)
	{
		bpsFailMessage();
		return (0);
	}

	//should be true
	if (!isPointInsideTriangle(
		5, 5,   15, 15,   10, 2,
		10, 8)
	)
	{
		bpsFailMessage();
		return (0);
	}

	//should be true
	if (!isPointInsideTriangle(
		5, 5,   15, 15,   10, 2,
		10, 8)
	)
	{
		bpsFailMessage();
		return (0);
	}

	//should be true
	if (!isPointInsideTriangle(
		5, 5,   15, 15,   10, 2,
		10, 8)
	)
	{
		bpsFailMessage();
		return (0);
	}
}

bool isPointInsideTriangle(
	Fixed xVertexA, Fixed yVertexA,
	Fixed xVertexB, Fixed yVertexB,
	Fixed xVertexC, Fixed yVertexC,
	Fixed xFind,    Fixed yFind)
{
	Point	vertexA(xVertexA, yVertexA);
	Point	vertexB(xVertexB, yVertexB);
	Point	vertexC(xVertexC, yVertexC);
	Point	toFind(xFind, yFind);
	bool	isInside;

	isInside = false;
	if (bsp(vertexA, vertexB, vertexC, toFind))
	{
		isInside = true;
		std::cout << GREEN;
	}
	else
		std::cout << RED;
	std::cout << "\t*-------------------------------------------*" << std::endl;
	std::cout << "\t Vertex 1 (x: " << xVertexA << ", y: " << yVertexA << ")";
	std::cout << "\t\tPoint (x: " << xFind << ", y: " << yFind << ")" << std::endl;
	std::cout << "\t Vertex 2 (x: " << xVertexB << ", y: " << yVertexB << ")" << std::endl;
	std::cout << "\t Vertex 3 (x: " << xVertexC << ", y: " << yVertexC << ")" << std::endl;
	std::cout << "\t*-------------------------------------------*" << std::endl;
	std::cout << std::endl;
	std::cout << RESET;
	return (isInside);
}

void bpsFailMessage( void )
{
	std::cout << RED;
	std::cout << "Bsp failed :(";
	std::cout << RESET;
	std::cout << std::endl;
}