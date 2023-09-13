# include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void )
{

}

ScalarConverter::~ScalarConverter( void )
{

}

ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{
    *this = obj;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &toCopyFrom)
{
    if (this != &toCopyFrom)
        return (*this);
    return (*this);
}

void 	ScalarConverter::convert( std::string literalString )
{
    ConversionData values;

    if (isType(literalString, CHAR_ARG))
        values = ScalarConverter::convertToChar(literalString);
    else if (isType(literalString, INT_ARG))
        values = ScalarConverter::convertToInt(literalString);
    else if (isType(literalString, FLOAT_ARG))
        values = ScalarConverter::convertToFloat(literalString);
    else if (isType(literalString, DOUBLE_ARG))
        values = ScalarConverter::convertToDouble(literalString);
    else
    {
        values.isConversionPossible[CHAR_ARG] = false;
        values.isConversionPossible[INT_ARG] = false;
        values.isConversionPossible[FLOAT_ARG] = false;
        values.isConversionPossible[DOUBLE_ARG] = false;
    }
    ScalarConverter::displayConversion(values);
}

ConversionData    ScalarConverter::convertToChar( std::string literalString )
{
    ConversionData values;

    values.convertedChar = static_cast<char>(literalString[0]);
    values.convertedInt = static_cast<int>(values.convertedChar);
    values.convertedFloat = static_cast<float>(values.convertedChar);
    values.convertedDouble = static_cast<double>(values.convertedChar);
    values.isConversionPossible[CHAR_ARG] = true;
    values.isConversionPossible[INT_ARG] = true;
    values.isConversionPossible[FLOAT_ARG] = true;
    values.isConversionPossible[DOUBLE_ARG] = true;
    return (values);
}

ConversionData    ScalarConverter::convertToInt( std::string literalString )
{
    ConversionData values;

    values.convertedInt = static_cast<int>(std::atol(literalString.c_str()));
    values.convertedChar = static_cast<char>(values.convertedInt);
    values.convertedFloat = static_cast<float>(values.convertedInt);
    values.convertedDouble = static_cast<double>(values.convertedInt);
    if ( values.convertedInt >= MIN_CHAR && values.convertedInt <= MAX_CHAR)
        values.isConversionPossible[CHAR_ARG] = true;
    else
        values.isConversionPossible[CHAR_ARG] = false;
    values.isConversionPossible[INT_ARG] = true;
    values.isConversionPossible[FLOAT_ARG] = true;
    values.isConversionPossible[DOUBLE_ARG] = true;
    return (values);
}

ConversionData 	ScalarConverter::convertToFloat( std::string literalString )
{
    ConversionData values;

    values.convertedFloat = static_cast<float>(std::atof(literalString.c_str()));
    values.convertedChar = static_cast<char>(values.convertedFloat);
    values.convertedInt = static_cast<int>(values.convertedFloat);
    values.convertedDouble = static_cast<double>(values.convertedFloat);
    if ( values.convertedFloat >= MIN_CHAR && values.convertedFloat <= MAX_CHAR)
        values.isConversionPossible[CHAR_ARG] = true;
    else
        values.isConversionPossible[CHAR_ARG] = false;
    if ( values.convertedDouble >= INT_MIN && values.convertedDouble <= INT_MAX)
        values.isConversionPossible[INT_ARG] = true;
    else
        values.isConversionPossible[INT_ARG] = false;
    values.isConversionPossible[FLOAT_ARG] = true;
    values.isConversionPossible[DOUBLE_ARG] = true;
    return (values);
}

ConversionData	ScalarConverter::convertToDouble( std::string literalString )
{
    ConversionData values;

    values.convertedDouble = static_cast<double>(std::strtod(literalString.c_str(), NULL));
    values.convertedChar = static_cast<char>(values.convertedDouble);
    values.convertedInt = static_cast<int>(values.convertedDouble);
    values.convertedFloat = static_cast<float>(values.convertedDouble);
    if ( values.convertedDouble >= MIN_CHAR && values.convertedDouble <= MAX_CHAR)
        values.isConversionPossible[CHAR_ARG] = true;
    else
        values.isConversionPossible[CHAR_ARG] = false;
    if ( values.convertedDouble >= INT_MIN && values.convertedDouble <= INT_MAX)
        values.isConversionPossible[INT_ARG] = true;
    else
        values.isConversionPossible[INT_ARG] = false;
    if ( values.convertedDouble >= FLT_MIN && values.convertedDouble <= FLT_MAX)
        values.isConversionPossible[FLOAT_ARG] = true;
    else
        values.isConversionPossible[FLOAT_ARG] = false;
    values.isConversionPossible[DOUBLE_ARG] = true;
    return (values);
}

void    ScalarConverter::displayConversion( ConversionData values )
{
    if (!values.isConversionPossible[CHAR_ARG])
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(values.convertedChar))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " << values.convertedChar << std::endl;

    if (!values.isConversionPossible[INT_ARG])
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << values.convertedInt  << std::endl;

    if (!values.isConversionPossible[FLOAT_ARG])
        std::cout << "float: impossible" << std::endl;
    else
    {
        std::cout << "float: " << values.convertedFloat << (ScalarConverter::floatHasDecimal(values.convertedFloat) ? ".0f": "f") << std::endl;
    }

    if (!values.isConversionPossible[DOUBLE_ARG])
        std::cout << "double: impossible" << std::endl;
    else
        std::cout << "double: " << values.convertedDouble << (ScalarConverter::doubleHasDecimal(values.convertedDouble) ? ".0": "") << std::endl;
}

bool    ScalarConverter::isType( std::string literalString, int type  )
{
    if (literalString.empty())
        return (false);
    switch (type)
    {
        case CHAR_ARG:
            return (ScalarConverter::isTypeChar(literalString));
        case INT_ARG:
            return (ScalarConverter::isTypeInt(literalString));
        case FLOAT_ARG:
            return (ScalarConverter::isTypeFloat(literalString));
        case DOUBLE_ARG:
            return (ScalarConverter::isTypeDouble(literalString));
        default:
            return (false);
    }
}

bool    ScalarConverter::isTypeChar( const std::string &literalString)
{
    if (literalString.length() != 1)
        return (false);
    if (std::isdigit(literalString[0]))
        return (false);
    return (true); 
}

bool    ScalarConverter::isTypeInt( const std::string &literalString )
{
    long int    value;
    size_t      i = 0;

    while ((literalString[i] == '+') || (literalString[i] == '-'))
        i++;
    while ((i < literalString.length()) && (std::isdigit(literalString[i])))
        i++;
    if (i != literalString.length())
        return (false);
    value = std::atol(literalString .c_str());
    if (value > INT_MAX || value < INT_MIN)
        return (false);
    return (true); 
}

bool    ScalarConverter::isTypeFloat( std::string literalString )
{
    double value;
    size_t sizeUntilF;
    
    sizeUntilF = literalString.length() - 1;
    if (!isTypeDouble(literalString.substr(0, sizeUntilF)))
        return (false);
    else if (literalString[sizeUntilF] != 'f')
        return (false);
    value = std::atof(literalString.c_str());
    if (value > FLT_MAX || value < FLT_MIN)
        return (false);
    return (true);
}

bool    ScalarConverter::isTypeDouble( std::string literalString )
{
    long double value;
    bool        isDecimal = false;
    size_t      i = 0;

    while ((literalString[i] == '+') || (literalString[i] == '-'))
        i++;
    while ((i < literalString.length()) && (std::isdigit(literalString[i])))
        i++;
    while (i < literalString.length())
    {
        if (literalString[i] == '.' && !isDecimal)
        {
            isDecimal = true;
            i++;
        }
        if (!std::isdigit(literalString[i]))
            return (false);
        i++;
    }
    value = std::strtod(literalString.c_str(), NULL);
    if (value > DBL_MAX || value < DBL_MIN)
        return (false);
    return (true);
}

bool	ScalarConverter::floatHasDecimal( float value )
{
    float  diff;
    int     intPart;

    intPart = static_cast<int>(value);
    diff = std::abs(value - static_cast<float>(intPart));
    if (diff > 0.0f)
        return (false);
    return (true);
}

bool	ScalarConverter::doubleHasDecimal( double value )
{
    double  diff;
    int     intPart;

    intPart = static_cast<int>(value);
    diff = std::abs(value - static_cast<double>(intPart));
    if (diff > 0.0)
        return (false);
    return (true);
}
