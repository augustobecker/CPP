# include "Serializer.hpp"

Serializer::Serializer( void )
{
    std::cout << "Serializer Constructor Called" << std::endl;
}

Serializer::~Serializer( void )
{
    std::cout << "Serializer Destructor Called" << std::endl;
}

Serializer::Serializer(const Serializer &obj)
{
    *this = obj;
}

Serializer& Serializer::operator=(const Serializer &toCopyFrom)
{
    if (this != &toCopyFrom)
        return (*this);
    return (*this);
}

uintptr_t Serializer::serialize(Data* ptrData)
{
    return (reinterpret_cast<uintptr_t>(ptrData));
}

Data* Serializer::deserialize(uintptr_t ptrUInt)
{
    return (reinterpret_cast<Data*>(ptrUInt));
}