/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 23:54:28 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/28 15:18:15 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "StringReplacer.hpp"

int main ( int argc, char **argv )
{
	StringReplacer strReplacer = StringReplacer(argc, argv);

	strReplacer.replace();
}
