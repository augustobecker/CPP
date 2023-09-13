#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>
#include <string>

template <typename T>
T const& min(T const &x, T const &y)
{
    return ((x <= y) ? x : y);
}

template <typename T>
T const& max(T const &x, T const &y)
{
    return ((x >= y) ? x : y);
}

template <typename T>
void swap(T &x, T &y)
{
    T temp = x;
    x = y;
    y = temp;
}

template <>
std::string const& min(std::string const &x, std::string const &y)
{
    return ((x.compare(y) <= 0) ? x : y);
}

template <>
std::string const& max(std::string const &x, std::string const &y)
{
    return ((x.compare(y) >= 0) ? x : y);
}

#endif