#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <iostream>
# include <stdint.h>

struct Data
{
    int value;
    Data(int nbr) : value(nbr) {}
};

class Serializer
{

private:

    Serializer( void );
    Serializer(const Serializer &);

public:

	~Serializer( void );

	Serializer& operator=(const Serializer &);

    static uintptr_t serialize(Data* ptr);

    static Data* deserialize(uintptr_t raw);

};

#endif