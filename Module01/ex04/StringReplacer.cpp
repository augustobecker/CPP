/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringReplacer.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:14:51 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/28 15:51:30 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "StringReplacer.hpp"

StringReplacer::StringReplacer(int argc, char **argv)
{
	if (!validateCommandLineInput(argc, argv))
		exit (0);
	this->_fileToModify = argv[1];
	this->_strToBeReplaced = argv[2];
	this->_newStr = argv[3];
}

bool	StringReplacer::validateCommandLineInput(int argc, char **argv)
{
	int index;

	index = 0;
	if (argc > NEEDED_ARGS || argc < NEEDED_ARGS)
	{
		std::cout << "StringReplacer : ";
		std::cout << "Please type 3 params: "<< std::endl;
		std::cout << "\t\tName of the file to modify from" << std::endl;
		std::cout << "\t\tText to be replaced"<< std::endl;
		std::cout << "\t\tNew text"<< std::endl;
		return (false);
	}
	while (index < argc)
	{
		if (!argv[index][0])
		{
			std::cout << "StringReplacer : Null Parameter" << std::endl;
			return (false);
		}
		index++;
	}
	return (true);
}

StringReplacer::~StringReplacer(void)
{
	return ;
}

void		StringReplacer::setStrToBeReplaced(std::string oldStr)
{
	this->_strToBeReplaced = oldStr;
}

std::string	StringReplacer::getStrToBeReplaced(void)
{
	return (_strToBeReplaced);
}

void        StringReplacer::setNewStr(std::string newStr)
{
	this->_newStr = newStr;
}

std::string StringReplacer::getNewStr(void)
{
	return (_newStr);
}

void        StringReplacer::setFileToModify(std::string filename)
{
	this->_fileToModify = filename;
}

std::string StringReplacer::getFileToModify(void)
{
	return (_fileToModify);
}

bool	StringReplacer::replace(void)
{
	if (_fileToModify.empty() || _strToBeReplaced.empty() || _newStr.empty())
		return (false);
	if (!fileExists(_fileToModify))
	{
		std::cout << "StringReplacer : File passed doesn't exist" << std::endl;
		return (false);
	}
	this->_outputFile.append(_fileToModify);
	this->_outputFile.append(".replace");
	replaceToNewFile(_fileToModify, _outputFile);
	return (true);
}

bool	StringReplacer::fileExists(std::string filename)
{
	std::ifstream	test_file;

	test_file.open(filename.c_str());
	if (test_file)
	{
		test_file.close();
		return (true);
	}
	test_file.close();
	return (false);
}

bool	StringReplacer::replaceToNewFile(std::string srcFilename,
std::string destFilename)
{
	std::ifstream	infile;
	std::ofstream	outfile;
	std::string		currentLine;

	infile.open(srcFilename.c_str());
	outfile.open(destFilename.c_str(), std::ofstream::out);
	while ((not infile.eof()) && (not infile.fail()))
	{
		std::getline(infile, currentLine);
		currentLine = lineReplacer(currentLine);
		outfile << currentLine;
		if ((not infile.eof()) && (not infile.fail()))
			outfile << std::endl;
	}
	outfile.close();
	infile.close();
	return (true);
}

std::string StringReplacer::lineReplacer(std::string src)
{
	std::string	dest;
	size_t		srcLen;
	size_t		index;
	int			lastIndex;

	index = 0;
	srcLen = src.length();
	index = src.find(_strToBeReplaced, 0);
	dest.append(src.substr(0, index));
	while (index < srcLen)
	{
		lastIndex = index;
		index = src.find(_strToBeReplaced, index + _strToBeReplaced.length());
		dest.append(_newStr);
		dest.append(src.substr(lastIndex + _strToBeReplaced.length(), index - (lastIndex + _strToBeReplaced.length())));
	}
	return (dest);
}
