/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringReplacer.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:01:31 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/28 15:21:37 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGREPLACER_HPP
# define STRINGREPLACER_HPP

# include <iostream> 
# include <fstream> 
# include <stdlib.h> 

class	StringReplacer
{

public:

    static const int NEEDED_ARGS = 4;

    StringReplacer(int argc, char **argv);
	StringReplacer(std::string fileToModify, std::string oldStr, std::string newStr);
	~StringReplacer(void);

	void		setStrToBeReplaced(std::string);
	std::string	getStrToBeReplaced(void);

	void		setNewStr(std::string);
	std::string	getNewStr(void);

	void		setFileToModify(std::string);
	std::string	getFileToModify(void);

	void		setOutputFile(std::string);
	std::string	getOutputFile(void);

	bool		replace(void);

private:

	std::string	_strToBeReplaced;
	std::string	_newStr;
	std::string	_fileToModify;
	std::string _outputFile;

	std::string lineReplacer(std::string);
	bool	replaceToNewFile(std::string srcFilename,
		std::string destFilename);
		
	static bool validateCommandLineInput(int argc, char **argv);
	static bool	fileExists(std::string);
};

#endif
