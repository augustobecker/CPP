/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 23:05:16 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/02 15:36:02 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void ft_print_upper(const char *str)
{
	std::string	output;
	size_t		i;

	i = 0;
	output = str;
	while (i < output.length())
		std::cout << (char)std::toupper(output[i++]);
}

int main(int argc, char **argv)
{
	int words;
	
	words = 1;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		while (words < argc)
			ft_print_upper(argv[words++]);
	}
	std::cout << std::endl;
  	return 0;
}
