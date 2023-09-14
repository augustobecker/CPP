#ifndef DISPLAY_HPP
# define DISPLAY_HPP

#include <iostream>

template <typename T>
void display(T const elem)
{
    std::cout << elem << " | ";
}

#endif