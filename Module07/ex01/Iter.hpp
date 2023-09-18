#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *array, size_t const arrayLength, void (function)(T& value))
{
    for (size_t i = 0; i < arrayLength; i++)
        function(array[i]);
}

template <typename T>
void iter(T const *array, size_t const arrayLength, void (function)(const T& value))
{
    for (size_t i = 0; i < arrayLength; i++)
        function(array[i]);
}

template <typename T>
void display(T const elem)
{
    std::cout << elem << " | ";
}

#endif