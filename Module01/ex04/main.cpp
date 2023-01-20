/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 23:54:28 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/20 02:52:28 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replacer.hpp"


void		replacer_init(std::string filename, std::string str_replaced, std::string new_str);
std::string	replacer(std::string source, std::string str_replaced, std::string new_str);

int main ( int argc, char **argv )
{
	validate_params(argc, argv);
	replacer_init(argv[FILE_ARG], argv[STR_REPLACED_ARG], argv[NEW_STR_ARG]);
}

void replacer_init(std::string filename, std::string str_replaced, std::string new_str)
{
	std::ifstream	infile;
	std::ofstream	outfile;
	std::string		outfile_name;
	std::string		actual_line;
	
	infile.open(&filename[0]);
	outfile_name.append(&filename[0]);
	outfile_name.append(".replace");
	outfile.open(&outfile_name[0], std::ofstream::out);
	while((not infile.eof()) && (not infile.fail()))
	{
		std::getline(infile, actual_line);
		actual_line = replacer(actual_line, str_replaced, new_str);
		outfile << actual_line;
		if ((not infile.eof()) && (not infile.fail()))
			outfile << std::endl;
	}
	outfile.close(); 
	infile.close();
}

std::string replacer(std::string source, std::string str_replaced, std::string new_str)
{
	std::string	dest;
	size_t		src_len;
	size_t		index;
	int			last_index;

	index = 0;
	src_len = source.length();
	index = source.find(str_replaced, 0);
	dest.append(source.substr(0, index));
	while (index < src_len)
	{
		last_index = index;
		index = source.find(str_replaced, index + str_replaced.length());
		dest.append(new_str);
		dest.append(source.substr(last_index + str_replaced.length(), index));
	}
	return (dest);
}
