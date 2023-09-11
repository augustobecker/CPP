#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

class ScalarConverter
{

private:

public:

	ScalarConverter( std::string );
	ScalarConverter( std::string, int );
	~ScalarConverter( void );

	ScalarConverter(const ScalarConverter &);
	ScalarConverter& operator=(const ScalarConverter &);

	void convert( std::string );

};

#endif
