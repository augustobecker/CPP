/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 23:32:51 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/20 02:54:04 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replacer.hpp"

static bool	is_number_of_params_accepted(int argc);
static bool	there_is_a_null_param(char **argv);
static bool	file_exists(char *filename);

void	validate_params(int argc, char **argv)
{

	if ( !is_number_of_params_accepted(argc) )
		error_handler(NUM_PARAMS_NOT_ACCEPTED);
	if ( there_is_a_null_param(argv) )
		error_handler(NULL_PARAM);
	if ( !file_exists(argv[FILE_ARG]))
		error_handler(FILE_DOES_NOT_EXIST);
}

static bool	is_number_of_params_accepted(int argc)
{
	if (argc < NUM_PARAMS || argc > NUM_PARAMS)
		return (false);
	return (true);
}

static bool	there_is_a_null_param(char **argv)
{
	int i;

	i = 0;
	while ( i < NEW_STR_ARG )
	{
		if (!argv[i][0])
			return (true);
		i++;
	}
	return (false);
}

static bool	file_exists(char *filename)
{
	std::ifstream	test_file;

	test_file.open(filename);
	if (test_file)
	{
		test_file.close();
		return (true);
	}
	test_file.close();
	return (false);
}
