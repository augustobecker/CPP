/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 23:27:23 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/20 00:11:40 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACER_H
# define REPLACER_H

# include <iostream> 
# include <fstream> 
# include <stdlib.h> 
# include "defines.hpp"

typedef enum e_error
{
	NO_ERROR,
	NOT_DOCUMENTED_ERROR,
	NUM_PARAMS_NOT_ACCEPTED,
	NULL_PARAM,
	FILE_DOES_NOT_EXIST,
}	t_error;


void	validate_params(int argc, char **argv);
void    error_handler(t_error error_type);


#endif
