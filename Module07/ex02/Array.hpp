#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
class Array 
{
public:
    Array ( void );
    Array ( unsigned int n );
    ~Array ( void );

private:
    T* elements;
};

#endif