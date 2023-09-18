# include <iostream>
# include "Iter.hpp"
# include "Fixed.hpp"

void testCases(void);
void testConstCases(void);

int main(void)
{
	testCases();
	testConstCases();
}

void testCases(void)
{
	int         intArray[10] 	= {3, 9, 2001, 4, 1951, 11, 20, 22, 1, 8};
	char        charArray[8] 	= "oublier";
	bool 		boolArray[3] 	= {true, false, true};
	float       floatArray[5] 	= {5.05, 3.09, 0.3, 1.1, 22.11};
	double      doubleArray[5] 	= {10000, 505, 39.01, 110101101, 27.02};
	std::string stringArray[3] 	= {"Vivre", "sa", "vie"};
	Fixed		objArray[3] 	= {Fixed(3.5f), Fixed(2022), Fixed(2001)};

	std::cout << "__________________________________________________________________" << std::endl;
	std::cout << "Int Array: ";
	::iter(intArray, 10, ::display);
	std::cout << std::endl;
	std::cout << "__________________________________________________________________" << std::endl;
	std::cout << "Char Array: ";
	::iter(charArray, 8, ::display);
	std::cout << std::endl;
	std::cout << "__________________________________________________________________" << std::endl;
	std::cout << "Bool Array: ";
	::iter(boolArray, 3, ::display);
	std::cout << std::endl;
	std::cout << "__________________________________________________________________" << std::endl;
	std::cout << "Float Array: ";
	::iter(floatArray, 5, ::display);
	std::cout << std::endl;
	std::cout << "__________________________________________________________________" << std::endl;
	std::cout << "Double Array: ";
	::iter(doubleArray, 5, ::display);
	std::cout << std::endl;
	std::cout << "__________________________________________________________________" << std::endl;
	std::cout << "std::string Array: ";
	::iter(stringArray, 3, ::display);
	std::cout << std::endl;
	std::cout << "__________________________________________________________________" << std::endl;
	std::cout << "Object Fixed Array: ";
	::iter(objArray, 3, ::display);
	std::cout << std::endl;
}

void testConstCases(void)
{
	const int         	intArray[10] 	= {3, 9, 2001, 4, 1951, 11, 20, 22, 1, 8};
	const char        	charArray[8] 	= "oublier";
	const bool 			boolArray[3] 	= {true, false, true};
	const float       	floatArray[5] 	= {5.05, 3.09, 0.3, 1.1, 22.11};
	const double      	doubleArray[5]	= {10000, 505, 39.01, 110101101, 27.02};
	const std::string	stringArray[3]	= {"Vivre", "sa", "vie"};
	const Fixed			objArray[3] 	= {Fixed(3.5f), Fixed(2022), Fixed(2001)};

	std::cout << "__________________________________________________________________" << std::endl;
	std::cout << "Const Int Array: ";
	::iter(intArray, 10, ::display);
	std::cout << std::endl;
	std::cout << "__________________________________________________________________" << std::endl;
	std::cout << "Const Char Array: ";
	::iter(charArray, 8, ::display);
	std::cout << std::endl;
	std::cout << "__________________________________________________________________" << std::endl;
	std::cout << "Const Bool Array: ";
	::iter(boolArray, 3, ::display);
	std::cout << std::endl;
	std::cout << "__________________________________________________________________" << std::endl;
	std::cout << "Const Float Array: ";
	::iter(floatArray, 5, ::display);
	std::cout << std::endl;
	std::cout << "__________________________________________________________________" << std::endl;
	std::cout << "Const Double Array: ";
	::iter(doubleArray, 5, ::display);
	std::cout << std::endl;
	std::cout << "__________________________________________________________________" << std::endl;
	std::cout << "Const std::string Array: ";
	::iter(stringArray, 3, ::display);
	std::cout << std::endl;
	std::cout << "__________________________________________________________________" << std::endl;
	std::cout << "Const Object Fixed Array: ";
	::iter(objArray, 3, ::display);
	std::cout << std::endl;
}
