/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 23:44:58 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/20 02:47:39 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replacer.hpp"

void    error_handler(t_error error_type)
{
    switch (error_type)
    {
        case (NO_ERROR):
            exit(NO_ERROR);
        case (NUM_PARAMS_NOT_ACCEPTED):
            exit(NUM_PARAMS_NOT_ACCEPTED);
        case (NULL_PARAM):
            exit(NULL_PARAM);
        case (FILE_DOES_NOT_EXIST):
            exit(FILE_DOES_NOT_EXIST);
        default:
            exit(NOT_DOCUMENTED_ERROR);
    }
}
