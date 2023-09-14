# include <iostream>
# include "Iter.hpp"
# include "Display.hpp"

int main(void)
{
    int         intArray[10] = {3, 9, 2001, 4, 1951, 11, 20, 22, 1, 8};
    char        charArray[8] = "oublier";
    float       floatArray[5] = {5.05, 3.09, 0.3, 1.1, 22.11};
    double      doubleArray[5] = {10000, 505, 39.01, 110101101, 27.02};
    std::string stringArray[3] = {"Vivre", "sa", "vie"};
 
    std::cout << "________________________________________________" << std::endl;
    ::iter(intArray, 10, ::display);
    std::cout << std::endl;
    std::cout << "________________________________________________" << std::endl;
    ::iter(charArray, 7, ::display);
    std::cout << std::endl;
    std::cout << "________________________________________________" << std::endl;
    ::iter(floatArray, 5, ::display);
    std::cout << std::endl;
    std::cout << "________________________________________________" << std::endl;
    ::iter(doubleArray, 5, ::display);
    std::cout << std::endl;
    std::cout << "________________________________________________" << std::endl;
    ::iter(stringArray, 3, ::display);
    std::cout << std::endl;
    return 0;
}
