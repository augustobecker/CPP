#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void iter(T const *array, int const arrayLength, void (*function)(T))
{
    for (int i = 0; i < arrayLength; i++)
        function(array[i]);
}

#endif