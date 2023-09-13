# include <iostream>
# include "Serializer.hpp"

# define GREEN		"\033[0;32m";
# define RED		"\033[0;31m";
# define RESET		"\033[0m";

int main (void)
{
    uintptr_t   serialized;
    Data        *deserialized;
    Data        data(42);

    serialized = Serializer::serialize(&data);
    deserialized = Serializer::deserialize(serialized);

    std::cout << "Original Value: \t\t";
    std::cout << GREEN;
    std::cout << data.value;
    std::cout << RESET;
    std::cout << std::endl;
    std::cout << "Value after serialization: \t";
    std::cout << RED ;
    std::cout << serialized ;
    std::cout << RESET;
    std::cout << std::endl;
    std::cout << "Value after deserialization: \t";
    std::cout << GREEN;
    std::cout << deserialized->value;
    std::cout << RESET;
    std::cout << std::endl;
    std::cout << "_____________________________________" << std::endl << std::endl;
    std::cout << "Original address: \t\t";
    std::cout << GREEN;
    std::cout <<  &data;
    std::cout << RESET;
    std::cout << std::endl;
    std::cout << "Address after serialize: \t";
    std::cout << RED;
    std::cout << &serialized;
    std::cout << RESET;
    std::cout << std::endl;
    std::cout << "Address after deserialize: \t";
    std::cout << GREEN;
    std::cout << deserialized;
    std::cout << RESET;
    std::cout << std::endl;
    std::cout << "_____________________________________" << std::endl << std::endl;
    return (0);
}
