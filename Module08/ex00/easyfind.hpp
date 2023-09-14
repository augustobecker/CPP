#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <exception>
# include <algorithm>

template <typename T>
typename T::iterator easyfind(T &container, int target)
{
    typename T::iterator elemFound;

    elemFound = std::find(
        container.begin(), 
        container.end(), 
        target);

    if (elemFound == container.end())
		throw std::out_of_range("Target not found");
	return elemFound;
}

template<typename T>
typename T::const_iterator easyfind(const T& container, int target) {

    typename T::const_iterator elemFound = std::find(
        container.begin(), 
        container.end(),
        target);

    if (elemFound == container.end())
        throw std::out_of_range("Target was not found");
    return elemFound;
}

#endif
