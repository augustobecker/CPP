#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

# include <cstdlib>
# include <climits>
# include <limits>
# include <cfloat>
# include <cctype>
# include <cmath>

# define CHAR_ARG		0
# define INT_ARG		1
# define FLOAT_ARG		2
# define DOUBLE_ARG		3

# define MIN_CHAR		0
# define MAX_CHAR		127

# define SUPORTED_CONVERSIONS 	4

struct ConversionData
{
	char		convertedChar;
	int			convertedInt;
	float		convertedFloat;
	double		convertedDouble;
	bool		isConversionPossible[SUPORTED_CONVERSIONS];
};

class ScalarConverter
{

private:

	ScalarConverter( void );
	ScalarConverter(const ScalarConverter &);

	static ConversionData	convertToChar( std::string );
	static ConversionData	convertToInt( std::string );
	static ConversionData 	convertToFloat( std::string );
	static ConversionData	convertToDouble( std::string );

	static bool    			isType( std::string, int );
	static bool    			isTypeChar( const std::string &);
	static bool    			isTypeInt( const std::string &);
	static bool    			isTypeFloat( std::string );
	static bool    			isTypeDouble( std::string );

	static bool				floatHasDecimal( float );
	static bool				doubleHasDecimal( double );

	static bool				isPseudoLiteralFloat( std::string );
	static bool				isPseudoLiteralDouble( std::string );
	static void   			displayConversion( ConversionData );

public:

	~ScalarConverter( void );

	ScalarConverter& operator=(const ScalarConverter &);

	static void 			convert( std::string );

};

#endif
