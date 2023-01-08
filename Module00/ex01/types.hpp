/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:57:40 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/08 21:56:44 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_HPP
# define TYPES_HPP

enum	Field
{
	FIRST_NAME, 
	LAST_NAME, 
	NICKNAME, 
	PHONE_NBR, 
	DARK_SECRET
};

enum	Command
{
	ADD,
	SEARCH,
	EXIT,
	NONE
};

#endif